#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "mem.h"

int main(int argc, char *argv[])
{
    // initialize the allocator
    mem_init();
    mem_show_heap();
    /*int i = 0;
     while (i < 7)
    {
        char *p = mem_alloc(42);
        assert(p != NULL); // check whether the allocation was successful
        printf("allocated 42 bytes for the %d time at %p\n", i + 1, p);
        mem_show_heap();
        if (i == 5)
        {
            mem_release(p);
            printf("freed 42 bytes at %p\n", p);
        }
        i++;
    } */
    
    /* mem_init();
    mem_show_heap();
    int i = 0;
    while (i < 2)
    {
        char *p = mem_alloc(200);
        assert(p != NULL); // check whether the allocation was successful
        printf("allocated 200 bytes at %p\n", p);
        mem_show_heap();
    } */

    /* char *p = mem_alloc(200);
    assert(p != NULL); // check whether the allocation was successful
    printf("allocated 200 bytes at %p\n", p);
    mem_show_heap();
    mem_release(p);
    mem_show_heap();
    p = mem_alloc(300);
    assert(p != NULL); // check whether the allocation was successful
    printf("allocated 300 bytes at %p\n", p);
    mem_show_heap(); */

    int i = 0;
     while (i < 7)
    {
        char *p = mem_alloc(42);
        assert(p != NULL); // check whether the allocation was successful
        printf("allocated 42 bytes for the %d time at %p\n", i + 1, p);
        mem_show_heap();
        i++;
    }
}
