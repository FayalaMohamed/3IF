#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    assert(argc == 2);
    int N = atoi(argv[1]);
    if (N)
    {
        fork();
        char *param;
        itoa(N - 1, param, 10);
        execl(argv[0], param);
        printf("Z");
    }
    else
    {
        printf("Z");
    }
    /* printf("%d: hello world\n", getpid());
    int x = fork();

    if (x == 0)
        printf("%d: je suis l'enfant\n", getpid());
    else
        printf("%d: je suis le parent\n", getpid());

    return EXIT_SUCCESS; */
}
