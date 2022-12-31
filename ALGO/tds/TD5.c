#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int deb;
  int fin;
  int *tab;
  int taille;
} File;


File * Init(int debut,int tailleTab);

void InsertValue(File * file, int value);

int dequeue(File * file, int * val);

void Destroy(File * file);

int main(void) 
{
  char lecture[100];
  int val;
  File * file;
  file = Init(100,101);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"queue")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(file,val);
    } else if (strcmp(lecture,"dequeue")==0) {
      if(dequeue(file,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(file);
  return 0;
}

File * Init(int debut,int tailleTab)
{
  File * file;
  file = (File*) malloc(sizeof(File));
  file->tab = malloc(sizeof(int)*tailleTab);
  file->deb=debut;
  file->fin=debut;
  file->taille=tailleTab;
  return file;
}


void InsertValue(File * file, int value)
{
    /*if(file->fin==file->deb-1 || (file->deb==0 && file->fin==file->taille-1) ||(file->fin==0 && file->deb==file->taille-1) ){
        return;
    }*/

    *(file->tab+file->fin)=value;

    if(file->fin!=file->taille-1)
        file->fin++;
    else
        file->fin=0;
    

}



int dequeue(File * file,int *val)
{
    if (file->deb==file->fin)
      return 0;
    
    *val=*(file->tab+file->deb);
    if(file->deb!=file->taille-1)
        file->deb++;
    else 
        file->deb=0;
    return 1;
}

void Destroy(File * file)
{
   free(file->tab);
   free(file);
}