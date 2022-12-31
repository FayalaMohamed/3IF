#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i=0;
    float sequence[n];
    for(i=0;i<n;i++)
        fscanf(stdin,"%f",&sequence[i]);
    float lecture =0;
    float maxTrouve = 0;
    for(i=0;i<n;i++){
        lecture += sequence[i];
        if(lecture<0)
            lecture=0;
        if (lecture>maxTrouve)
            maxTrouve=lecture;
    }
    printf("%.0f\r\n",maxTrouve);

}