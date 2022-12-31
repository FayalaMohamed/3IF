#include <stdio.h>
#include <stdbool.h>

int objet[101];
bool L[101][10001];

int main(){
   int i, j, capa, nbObjets= 0;
   scanf("%d", &capa);
   objet[0] = 0;
   for(i = 1; i<101; i++){
      scanf("%d", &objet[i]);
      nbObjets++;
      if(objet[i]==-1)
         break;
   }
   for(i = 0; i<nbObjets; i++)
      L[i][0] = true;
   for(i = 1; i<=capa; i++)
      L[0][i] = false;
   for(i = 1; i<nbObjets; i++){
      for(j = 1; j<=capa; j++) {
         if(L[i-1][j] || (j-objet[i] >= 0 && L[i-1][j-objet[i]]))
            L[i][j] = true;
      }
   }
   if(L[nbObjets-1][capa]) //car -1 stocké don nbObjetsEffectifs = nbObjets - 1
      printf("OUI\r\n");
   else
      printf("NON\r\n");
   
   return 0;
}