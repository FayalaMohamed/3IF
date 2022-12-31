#include <stdio.h>
#include <math.h>

int main(){
    int n,m,x,i,somme=0;
    scanf("%d",&n);
    int tab[n+1];
    for(i=0;i<n+1;i++){
        scanf("%d",&tab[i]);
    }
    scanf("%d",&m);
    scanf("%d",&x);

    for(i=0;i<n+1;i++){
       somme+=tab[i]*pow(x,i); 
    }

    printf("%d\r\n",somme%m);

    return 0;
}