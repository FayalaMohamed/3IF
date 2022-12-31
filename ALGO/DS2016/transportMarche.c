#include <stdio.h>
#include <stdbool.h>

int max(int a,int b){
    if(a>=b) return a;
    return b;
}

int m(int c,int *tab,int *w,int *types, int n,int promo){
    int i,j;
    int dp[n+1][c+1];
    for(i=0;i<n+1;i++){
        for(j=0;j<c+1;j++){
            dp[i][j]=0;
        }
    }

    for(i=0;i<n+1;i++){
        dp[i][0]=1;
    }

    for(i=1;i<n+1;i++){
        for(j=1;j<c+1;j++){
            if(types[i]==promo && j>=w[i] && dp[i-1][j-w[i]]==1){
                dp[i][j]=1;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for(i=c;i>=0;i--){
        if(dp[n][i]==1){
            return i;
        }
    }
    return 0;

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
    int tab[n+1];
    int types[n+1];
    tab[0]=types[0]=0;
    for(i=1;i<n+1;i++){
        scanf("%d %d",&tab[i],&types[i]);
    }


    max3A=m(c,tab,tab,types,n,3);
    max4A=m(c,tab,tab,types,n,4);
    
    if(max3A>max4A) printf("3\r\n");
    else printf("4\r\n");


    return 0;
}