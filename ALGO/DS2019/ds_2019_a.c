#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

void trierDeCroi(int **tab,int card){
    int i,j;
    for(i=0;i<card;i++){
        int ipp=i;
        for(j=i+1;j<card;j++){
            if(tab[0][j]>tab[0][ipp])
                ipp=j;
        }
        int a=tab[0][ipp];
        tab[0][ipp]=tab[0][i];
        tab[0][i]=a;

        a=tab[1][ipp];
        tab[1][ipp]=tab[1][i];
        tab[1][i]=a;
    }
}

int main(){
    int N,n,i,j,k;

    fscanf(stdin,"%d",&N);
    fscanf(stdin,"%d",&n);

    int tab[2][n+1];
    tab[0][0]=3;
    tab[1][0]=0;
    for(i=1;i<=n;i++){
        fscanf(stdin,"%d %d",&tab[0][i], &tab[1][i]);
    }
    
    /*for(i=0;i<n+1;i++)
        printf("%d ",tab[0][i]);
    printf("\r\n");
    for(i=0;i<n+1;i++)
        printf("%d ",tab[1][i]);
    printf("\r\n");*/
    for(i=0;i<n+1;i++){
        int ipp=i;
        for(j=i+1;j<n+1;j++){
            if(tab[0][j]>tab[0][ipp])
                ipp=j;
        }
        int a=tab[0][ipp];
        tab[0][ipp]=tab[0][i];
        tab[0][i]=a;

        a=tab[1][ipp];
        tab[1][ipp]=tab[1][i];
        tab[1][i]=a;
    }
    /*for(i=0;i<n+1;i++)
        printf("%d ",tab[0][i]);
    printf("\r\n");
    for(i=0;i<n+1;i++)
        printf("%d ",tab[1][i]);
    printf("\r\n");*/

    bool L[N+1][n+1];
    int nb[N+1];
    
    for(i=1;i<=N;i++){
        for(j=1;j<=n;j++){
            L[i][j]=false;
        }
    }
    for(i=1;i<=N;i++)
        L[i][0]=false;
    for(i=0;i<=n;i++)
        L[0][i]=true;
    for(i=0;i<=N;i++)
        nb[i]=0;

    for(i=1;i<=N;i++){
        for(j=1;j<=n;j++){
            if(!L[i][j]){
            if((i>=tab[1][j] && L[i-tab[1][j]][j-1]) || L[i][j-1]){
                L[i][j]=true;
                for(k=j;k<=n;k++){
                    L[i][k]=true;
                }

                if(tab[0][j]==1)
                    nb[i]=nb[i-tab[1][j]]+1;
                break;
            }else {
                L[i][j]=false;
            }
            }
        }
    }

    if(!L[N][n])
        printf("%d\r\n",-1);
    else 
        printf("%d\r\n",nb[N]);

    return 0;
}