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
        FILE *fich = fopen(argv[i], "r");
        if (fich != NULL)
        {
            char c = fgetc(fich);
            while (c != EOF)
            {
                putchar(c);
                c = fgetc(fich);
            }
        }
        fclose(fich);
        if (i != argc - 1)
            printf("\n\n\n");
    }

    return 0;
}
