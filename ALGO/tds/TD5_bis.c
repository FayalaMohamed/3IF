#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    struct Cellule * next;
}Cellule;

typedef struct {
  Cellule * debut;
  Cellule * fin;
} File;


File * Init();

void InsertValue(File * file, int value);

int dequeue(File * file, int * val);

void Destroy(File * file);

void afficher(File * file);

int main(void) 
{
  char lecture[100];
  int val;
  File * file;
  file = Init();

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"queue")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(file,val);
    } else if (strcmp(lecture,"dequeue")==0) {
      if(dequeue(file,&val)==1)
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(file);
  return 0;
}

File * Init()
{
  File * file;
  file = (File*) malloc(sizeof(File));
  file->debut = NULL;
  file->fin = NULL;
  return file;
}

void afficher(File * file){
    Cellule * suivant;
    suivant=file->debut;
    while(suivant != NULL){
        printf("%d,",suivant->value);
        suivant=suivant->next;
    }
    printf("\r\n");
}

void InsertValue(File * file, int val)
{
    if(file->debut==NULL){
        file->debut=malloc(sizeof(Cellule));
        file->debut->value=val;
        file->debut->next=NULL;
        file->fin=malloc(sizeof(Cellule));
        file->fin=file->debut;
        //printf("premiere val inseree\r\n");
        return;
    }
    Cellule *newC=malloc(sizeof(Cellule));
    newC->value=val;
    newC->next=(Cellule *) NULL;
    
    file->fin->next=newC;
    file->fin=file->fin->next;
    //printf(" val inseree \r\n");

}



int dequeue(File * file,int *val)
{
    if (file->debut==NULL /*&& file->fin==NULL*/)
      return 0;
    
    *val=file->debut->value;
    Cellule * a=file->debut->next;
    file->debut=a;
    return 1;
}



void Destroy(File * file)
{
    Cellule * suivant;
    suivant=file->debut;
    Cellule * a;
    while(suivant != NULL){
        a=suivant->next;
        free(suivant);
        suivant=a;
    }
    free(file);
}