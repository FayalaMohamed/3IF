#include <stdio.h>
#include <stdbool.h>

int max(int a,int b){
    if(a>=b) return a;
    return b;
}

int m(int c,int nb, int value[nb+1][c+1],int w[2][nb], int i,int j,int promo){
    if(i==0 || j<=0){
        value[i][j]=0;
        return 0 ;
    }
    if(value[i-1][j]==-1)
        value[i-1][j]=m(c,nb,value,w,i-1,j,promo);
    
    if(w[0][i]>j ||  w[1][i]!=promo ){
        value[i][j]=value[i-1][j];
    }else if(w[1][i]==promo){
        if(value[i-1][j-w[0][i]]==-1){
           value[i][j-w[0][i]]=m(c,nb,value,w,i-1,j-w[0][i],promo);
        }
        value[i][j]=max(value[i-1][j],value[i-1][j-w[0][i]]);
    }
    return value[i][j];
} 

int main(){
    int c,n,i,j,max3A,max4A,maxi;
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

    int value[n+1][c+1];
    for(i=0;i<c+1;i++){
        for(j=0;j<n+1;j++){
            value[j][i]=-1;
        }
    }

    max3A=m(c+1,n,value,tab,c,n,3);
    max4A=m(c+1,n,value,tab,c,n,4);
    
    if(max3A>max4A) printf("3\r\n");
    else printf("4\r\n");


    return 0;
}