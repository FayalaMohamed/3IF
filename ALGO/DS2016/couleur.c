#include <stdio.h>
#include <stdbool.h>


int main(){
    int c,n,i,max=0,typeMax,indiceMax,somme;
    bool toutTeste=false;
    scanf("%d",&c);
    scanf("%d",&n);
    if(c==0 || n==0){
        printf("0\r\n");
        return 0;
    }
    int tab[2][n];
    for(i=0;i<n;i++){
        scanf("%d %d",&tab[0][i],&tab[1][i]);
    }

    int indiceTeste[n];
    for(i=0;i<n;i++){
        indiceTeste[i]=0;
    }

    while(!toutTeste){
        for(i=0;i<n;i++){
            indiceTeste[i]=0;
            if(tab[0][i]<=c/2 && tab[0][i]>=max && indiceTeste[i]==0){
                max=tab[0][i];
                typeMax=tab[1][i];
                indiceMax=i;
            }
        }
        indiceTeste[indiceMax]=1;

        somme=0;
        for(i=0;i<n;i++){
            if((2*tab[1][i])%3==typeMax ){
                somme+=tab[0][i];
            }
        }
        
        if(somme>=c-max){
            printf("%d\r\n",2*max);
            return 0;
        }

        toutTeste=true;
        for(i=0;i<n;i++){
            if(indiceTeste[i]==0){
                toutTeste=false;
                break;
            }
        }
    }
    printf("0\r\n");
    return 0;
}