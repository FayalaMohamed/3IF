#include <stdio.h>

void trierDeCroi(int *tab,int card){
    int i,j;
    for(i=0;i<card;i++){
        int ipp=i;
        for(j=i+1;j<card;j++){
            if(tab[j]<tab[ipp])
                ipp=j;
        }
        int a=tab[ipp];
        tab[ipp]=tab[i];
        tab[i]=a;
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    int tab[n];
    for(i=0;i<n;i++){
        scanf("%d",&tab[i]);
    }

    trierDeCroi(tab,n);
    printf("%d\r\n",tab[n-2]-tab[1]);
    
    return 0;
}