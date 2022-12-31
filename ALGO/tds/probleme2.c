#include <stdio.h>
#include <stdbool.h>

int objet[100];
bool L[100001];

int main(){
   int i, j, capa, nbObjets= 0;
   scanf("%d", &capa);
   for(i = 0; i<100; i++){
      scanf("%d", &objet[i]);
      nbObjets++;
      if(objet[i]==-1)
         break;
   }
   L[0]=true;
   for(i = 1; i<=capa; i++){
      // ATTENTION : il y a nbObjets poids 
      // objets contient nbObjets+1 valeurs 
      // le -1 est mis dans le tableau
      for(j = 0; j<nbObjets; j++) { 
         if(objet[j]<=i && L[i-objet[j]]==true){
            L[i]=true;
            break;
         }else{
            L[i]=false;
         }
      }
   }
   if(L[capa])
      printf("OUI\r\n");
   else
      printf("NON\r\n");
   
   return 0;
}