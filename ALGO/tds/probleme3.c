#include <stdio.h>
#include <stdbool.h>

bool L [20001];
int v, s;

void operations(int volume){
   if(L[volume]){
      if(3*volume<=v&&!L[3*volume])  { 
         L[3*volume] = true;
         operations(3*volume);
      }
      if(2*volume<=v&&!L[2*volume]){
         L[2*volume] = true;
         operations(2*volume);
      }
      if(!L[volume/5]){
         L[volume/5] = true;
         operations(volume/5);
      }
   }
}


int main(){
   int i, vAtteint = 0;
   scanf("%d%d", &v, &s);
   for(i = 1; i<=v; i++)
      L[i] = false;
   L[s]=true;
   operations(s);
   for(i = v; i>0; i--){
      if(L[i]){
         vAtteint = i;
         break;
      }
   }
   printf("%d\r\n", vAtteint);
   return 0;
}