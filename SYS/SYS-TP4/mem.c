#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>

#include "mem.h"

void *heap_base = NULL; // first address of the heap
void *heap_end = NULL;  // first address beyond the heap

int mem_initialized = 0;
void mem_init(void)
{
    // request memory from the kernel
    heap_base = mmap(NULL, 800, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    assert(heap_base != MAP_FAILED);

    heap_end = heap_base + 800;

    // create some free blocks: five of 80 bytes and one of 400 bytes
    void *block_ptr = heap_base;
    *((int64_t *)block_ptr) = 800;
    block_ptr = heap_end - 8;
    *((int64_t *)block_ptr) = 800;
    mem_initialized = 1;
}

void *mem_alloc(int64_t length)
{
    assert(mem_initialized == 1);

    // compute actual size of block
    length = (length + 7) / 8 * 8; // round up to nearest multiple of 8
    length += 8;                   // add space for the header

    // heap traversal
    void *block_ptr;
    int64_t header;
    int64_t size;
    char flags;

    int64_t old_size;

    block_ptr = heap_base;
    while (block_ptr < heap_end)
    {
        header = *((int64_t *)block_ptr);
        flags = header & 0b111; // keep only three least significant bits
        size = header & ~0b111; // discard the three least significant bits
        old_size = size;

        if ((flags == 0) &&   // if current block is free, and
            (size >= length)) // is also large enough, then we have a winner
            break;

        // otherwise we move on to the next block
        block_ptr += size;
    }

    // if the heap  traversal reached this far, then it  means we have
    // found no suitable block, so we should return NULL
    if (block_ptr >= heap_end)
    {
        return NULL;
    }

    flags = 0b001; // mark block as taken
    size = length;
    header = size | flags;
    *((int64_t *)block_ptr) = header; // write header back into the block
    *((int64_t *)(block_ptr + size - 8)) = header;

    // decoupage
    if (old_size - size > 8)
    {
        void *remaining_block = block_ptr + length;
        int64_t remaining_size = old_size - size;

        *((int64_t *)remaining_block) = remaining_size | 0b000;
        *((int64_t *)(remaining_block + remaining_size - 8)) = remaining_size | 0b000;
    }

    return block_ptr + 8; // skip header
}

void mem_release(void *ptr)
{
    assert(mem_initialized == 1);
    assert(((int64_t)ptr % 8) == 0); // sanity check

    ptr = ptr - 8;
    int64_t header = *((int64_t *)ptr);
    int64_t size = header & ~0b111;
    char flags = header & 0b111;
    flags = 0b000;
    header = size | flags;
    *((int64_t *)ptr) = header;
    *((int64_t *)(ptr + size - 8)) = header;

    // verifier le bloc precedent
    if (ptr != heap_base && (*((int64_t *)(ptr - 8)) & 0b111) == 0)
    {
        // si le bloc precedent est vide, on merge
        int64_t prec_footer = *((int64_t *)(ptr - 8));
        int64_t prec_size = prec_footer & ~0b111;
        int64_t total_size = prec_size + size;
        int64_t new_header = total_size | flags;
        *((int64_t *)(ptr - prec_size)) = new_header;
        *((int64_t *)(ptr + size - 8)) = new_header;
        ptr = ptr - prec_size;
        size = total_size;
    }

    // verifier le bloc suivant
    if ((ptr + size) != heap_end && (*((int64_t *)(ptr + size)) & 0b111) == 0)
    {
        // si le bloc suivant est vide, on merge
        int64_t next_header = *((int64_t *)(ptr + size));
        int64_t next_size = next_header & ~0b111;
        int64_t total_size = next_size + size;
        int64_t new_header = total_size | flags;
        *((int64_t *)ptr) = new_header;
        *((int64_t *)(ptr + total_size - 8)) = new_header;
        ptr = ptr - next_size;
        size = total_size;
    }

    return;
}

void mem_show_heap(void)
{
    assert(mem_initialized == 1);

    void *block_ptr = heap_base;

    printf("heap_base = %p\n", heap_base);
    while (block_ptr < heap_end)
    {
        int64_t header = *((int64_t *)block_ptr);
        char flags = header & 0b111;    //   keep only three least significant bits
        int64_t size = header & ~0b111; // discard the three least significant bits
        int64_t footer = *((int64_t *)(block_ptr + size - 8));
        if ((size < 8) ||
            (size % 8 != 0))
        {
            printf("error: block at %p has incorrect size %ld\n", block_ptr, size);
            exit(1);
        }

        printf("  block at %p: header=0x%08lx size=%ld flags=%d (%s) footer=0x%08lx ==header? (%s) \n",
               block_ptr, header, size, flags,
               (flags ? "taken" : "free"),
               footer,
               (footer == header ? "true" : "false"));

        block_ptr += size; // move on to next block
    }

    printf("heap_end = %p\n", heap_end);

    // sanity check: a full heap traversal should reach *exactly* the end
    assert(block_ptr == heap_end);
}
