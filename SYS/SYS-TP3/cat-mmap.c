#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        int fd = open(argv[i], O_RDONLY);

        if (fd != -1)
        {
            struct stat buf;
            fstat(fd, &buf);
            char *c = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
            assert(c != MAP_FAILED);
            write(1, c, buf.st_size);
            munmap(c, buf.st_size);
        }

        close(fd);

        if (i != argc - 1)
            printf("\n\n\n");
    }

    return 0;
}
