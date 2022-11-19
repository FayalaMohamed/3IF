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
    int nbElem,i,res=0;
    scanf("%d",&nbElem);
    int tab[nbElem];
    for(i=0;i<nbElem;i++){
        scanf("%d",&tab[i]);
    }
    float moyenne=moyTab(tab,nbElem);
    for(i=0;i<nbElem;i++){
        if(tab[i]>moyenne)
            res++;
    }
    printf("%d\r\n",res);

}