#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    int x=fork();
    if(x==0)
        execl("./rebours","./rebours","5",NULL);
    else
        execl("./rebours","./rebours","3",NULL);
        
    return EXIT_SUCCESS;
}
