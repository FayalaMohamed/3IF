#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct
{
    int sexe; // 1=Garcon, 2=Fille
    char prenom[25];
    int annee;  // 1900..2021
    int nombre; // d'enfants nés cette année avec ce prénom
} tuple;

int main(int argc, char **argv)
{
    printf("Hello, prenoms\n");
    int fd = open("prenoms.dat", O_RDWR);

    if (fd != -1)
    {
        struct stat buf;
        fstat(fd, &buf);
        tuple *c = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
        assert(c != MAP_FAILED);
        int size = buf.st_size / sizeof(tuple);
        printf("%d", size);
        int n = 0;
        for (int i = 0; i < size; i++)
        {
            if (c[i].sexe == 1 || c[i].sexe == 2)
            {
                n++;
                printf("Prenom: %s Année: %d Nombre: %d\n", c[i].prenom, c[i].annee, c[i].nombre);
            }
            else
            {
                c[i].sexe = 2;
            }
        }
        printf("%d=%d", size, n);
    }

    close(fd);
    return 0;
}
