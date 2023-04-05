#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if(argc!=2) {
        printf("Argument manquant");
        exit(0);
    }
    int duree=atoi(argv[1]);
    assert(duree>0);
    int pid = getpid();
    printf("%d: debut\n",pid);
     for(int i = duree;i!=0;i--) {
        printf("%d: %d\n",pid,i);
        sleep(1);
    }
    printf("%d : fin\n",pid);
    return EXIT_SUCCESS;
}
