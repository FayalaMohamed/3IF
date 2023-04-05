#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>

void afficher(char *crible, int n)
{
    printf("nombres premiers jusqu'à %d: ", n);
    for (int i = 2; i <= n; i++)
        if (crible[i] == 1)
            printf("%d, ", i);
    printf("\n");
}

void rayer_multiples(char *crible, int n, int k)
{
    int j = 2;
    while (k * j <= n)
    {
        crible[k * j] = 0;
        j++;
    }
}

int main(int argc, char **argv)
{
    int n = 1000;
    if (argc > 1)
    {
        n = atoi(argv[1]);
        assert(n > 0);
    }

    // EXO 1
    //  char buffer[1000];
    //  assert(n <= 1000);
    //  char *crible = (char *)&buffer;

    // EXO 2
    // char *crible = mmap(NULL, n * sizeof(int), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);

    // EXO 3
    char *crible = mmap(NULL, n * sizeof(int), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    assert(crible != MAP_FAILED);

    for (int i = 0; i < n; i++)

        for (int i = 0; i < n; i++)
        {
            crible[i] = 1; // par défaut: pas encore barré
        }

    /*
    for (int k = 2; k < n; k++)
    {
        rayer_multiples(crible, n, k);
    }
    */

    // EXO 3
    for (int k = 2; k < n; k++)
    {
        if (!fork())
        {
            rayer_multiples(crible, n, k);
            exit(1);
        }
    }

    for (int k = 2; k < n; k++)
    {
        wait(NULL);
    }
    // FIN EXO 3
    
    afficher(crible, n);

    return 0;
}
