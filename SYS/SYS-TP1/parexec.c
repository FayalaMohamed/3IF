#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int min(int a ,int b){
    if (a<b) 
        return b;
    return a;
}
// 1ere version
/* int main(int argc, char** argv)
{
    for(int i=2;i<argc;i++){
        if(!fork()){
            execl("./rebours","./rebours",argv[i],NULL);
        }
        wait(NULL);
    }
    return EXIT_SUCCESS;
} */

// 2eme version
/* int main(int argc, char** argv)
{
    int N=atoi(argv[2]);
    int dernier;
    int actifs=0;

    for(int i=3;i<min(3+N,argc);i++){
        if(!fork()){
            execl("./rebours","./rebours",argv[i],NULL);
        }
        dernier=i;
        actifs++;
    }
    for(int i=3;i<argc;i++){
        if(wait(NULL)){
            actifs--;
            if(dernier != argc-1 && actifs!=N){
                dernier++;
                if(!fork()){
                    execl("./rebours","./rebours",argv[dernier],NULL);
                }
            }
        }
    }

    return EXIT_SUCCESS;
} */

// 2eme version
int main(int argc, char** argv)
{
    int N=atoi(argv[2]);
    int actifs=0;

    for(int i=3;i<argc;i++){
        if(!fork() ){
            execl("./rebours","./rebours",argv[i],NULL);
        }
        actifs++;
        if(actifs==N){
            wait(NULL);
            actifs--;
        }
        
    }
    for(int i=0;i<actifs;i++)
        wait(NULL);
    return EXIT_SUCCESS;
}
