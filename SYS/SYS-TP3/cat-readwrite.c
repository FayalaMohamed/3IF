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
        int f = open(argv[i], O_RDONLY);
        if (f != -1)
        {
            char c[1];
            int ret;
            ret = read(f, c, 1);
            while (ret != 0)
            {
                write(1, c, 1);
                ret = read(f, c, 1);
            }
        }
        close(f);
        if (i != argc - 1)
            printf("\n\n\n");
    }

    return 0;
}
