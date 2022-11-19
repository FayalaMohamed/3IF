#include <stdio.h>

float moyTab(int *tab,int nbElem){
    int i;
    float somme=0;
    for(i=0;i<nbElem;i++){
        somme+=tab[i];
    }
    return somme/nbElem;
}

int main(){
    int n,m,i;
    scanf("%d",&n);
    scanf("%d",&m);
    int tabRg[n];
    int tabNoirs[m];
    for(i=0;i<n;i++){
        scanf("%d",&tabRg[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d",&tabNoirs[i]);
    }
    float moyenneRg=moyTab(tabRg,n);
    float moyenneNoir=moyTab(tabNoirs,m);
    if(moyenneRg>moyenneNoir) printf("R\r\n");
    if(moyenneRg<moyenneNoir) printf("N\r\n");
    if(moyenneRg==moyenneNoir) printf("RN\r\n");

    return 0;
}