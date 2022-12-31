#include <stdio.h>

int main(){
    int n;
    int size;
    int i=1;
    scanf("%d", &n);
    int tab[100];
    tab[0]=0;
    while(1){ //to ask for the values of the weights and stock them in an array
       scanf("%d",&tab[i]);
       if(tab[i]==-1){
           break;
       }
       i++;
    }
    size=i;

    int t[n+1][size];
    int p;
    int j;
    for(p=0;p<size;p++){
        t[0][p]=1;
    }
    for(p=1;p<n+1;p++){
        t[p][0]=0;
    }
   
    for(p=1;p<n+1;p++){
        for(j=1;j<size;j++){
            if(p-tab[j]>=0){
                t[p][j]=t[p-tab[j]][j-1] + t[p][j-1] ;
            }
            if(t[p][j]>1){
                t[p][j]=1;
            }
        }
    }

   if(t[n][size-1]==1){
       printf("OUI\r\n");
   } else {
       printf("NON\r\n");
   }
   return 0;
}



