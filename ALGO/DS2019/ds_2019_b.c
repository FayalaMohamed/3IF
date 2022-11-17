#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int * rot_gauche(int * tab,int size){
    int i;
    int a=*tab;
    for(i=0;i<size-1;i++){
        *(tab+i)=*(tab+i+1);
    }
    *(tab+size-1)=a;
    return tab;
}



int main(){
    int N,n,i,j,k,min;

    // Saisie
    fscanf(stdin,"%d",&n);

    int tab[n+1];
    tab[0]=0;
    for(i=1;i<=n;i++){
        fscanf(stdin,"%d",&tab[i]);
    }

    fscanf(stdin,"%d",&N);

    // Tri
    for(i=0;i<n+1;i++){
        int ipp=i;
        for(j=i+1;j<n+1;j++){
            if(tab[j]>tab[ipp])
                ipp=j;
        }
        int a=tab[ipp];
        tab[ipp]=tab[i];
        tab[i]=a;
    }

    // Initialistion L et nb
    bool L[N+1];
    int nb[N+1];
    
    L[0]=true;
    for(i=1;i<=N;i++){
        L[i]=false;
    }
    for(i=0;i<=N;i++)
        nb[i]=0;

    min=N+1;

    for(k=0;k<n;k++){
        for(i=1;i<=N;i++){
            for(j=0;j<n;j++){
                
                if(i>=tab[j] && L[i-tab[j]] ){
                    L[i]=true;
                    nb[i]=nb[i-tab[j]]+1;
                    break;
                }else {
                    L[i]=false;
                }
            }  
            
        }
        if(L[N] && min>nb[N])
                min=nb[N];
        int a=*tab;
        for(i=0;i<n;i++){
            *(tab+i)=*(tab+i+1);
        }
        *(tab+n)=a;
    }

    /*if(!L[N])
        printf("%d\r\n",-1);
    else*/ 
        printf("%d\r\n",min);

    return 0;
}