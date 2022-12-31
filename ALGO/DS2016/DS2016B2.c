#include <stdio.h>



int findcomb(int capacity, int* types, int n, int* weight, int type){ //function to find the most weight combining the sum of the other type
    int i,j;
    int dp[n+1][capacity+1];
    for(i=0;i<capacity+1;i++){
        dp[0][i]=0;
    }
    for(i=0;i<n+1;i++){
        dp[i][0]=1;
    }

    for(i=1;i<n+1;i++){
        for(j=1;j<capacity+1;j++){
            if((types[i]==type) && (j-weight[i]>=0) && (dp[i-1][j-weight[i]]!=0)){
                dp[i][j]=dp[i-1][j-weight[i]]+dp[i-1][j];
                if(dp[i][j]>1){
                    dp[i][j]=1;
                }
            } else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    /*for(i=0;i<n+1;i++){
         for(j=165;j<capacity+1;j++){
             printf("%d ",dp[i][j]);
         }
         printf("\n");
     }
    printf("eeeee\n");
    */
    for(i=capacity;i>=0;i--){
        if(dp[n][i]==1){
            return i;
        }
    }
}


int main(){
    int c, n; // c being the capacity of the recipient and n the number of students
    scanf("%d", &c);
    scanf("%d", &n);
    int types[n + 1]; // store the type fo each capacity stored in the next array called cap
    int weight[n + 1];
    types[0] = 0;
    weight[0] = 0;
    int i, j;
    for (i = 1; i < n + 1; i++) {
        scanf("%d%d", &weight[i], &types[i]);
    }

    int IF3=findcomb(c,types,n,weight,3);
    int IF4= findcomb(c,types,n,weight,4);

    if(IF3>IF4){
        printf("%d\r\n",3);
    }else if (IF4>IF3){
        printf("%d\r\n",4);
    }else
        printf("%d %d\r\n",3,4);


    return 0;
}