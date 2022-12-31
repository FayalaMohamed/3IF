#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* mettez ici vos déclarations de fonctions et types */

/* raccourcis vers les types clé et valeur */
typedef char * Key;
typedef char * Value;

/* état d’une case (peut être fait aussi avec un enum) */
#define EMPTY 0
#define SET 1
#define REMOVED 2

/* utile pour l’affichage */
const char * Labels[] = {"Empty","Set","Removed"};

/* une cellule de la table */
typedef struct {
  Key key;
  unsigned char status;
  Value val;
} Data;

/* la table de hachage elle-même */
typedef struct {
  Data * tab;
  int size;
} HashTable;


void error(void);

HashTable *init(int size);

void insert (HashTable * table, char * key,char * val);

int recherchePos (HashTable* table, Key key,int *index);

void delete(HashTable * table, Key key);

int Query(HashTable *hTable, Key k, Value *v);

void destroy(HashTable *hTable);

void stats(HashTable *hTable);

unsigned int HashFunction(Key key, unsigned int size);

int main(void) 
{
   int size;
   char lecture[100];
   char * key;
   char * val;
   HashTable *table;

   if (fscanf(stdin,"%99s",lecture)!=1)
      error();
   while (strcmp(lecture,"bye")!=0)
   {
      if (strcmp(lecture,"init")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         size = atoi(lecture);
         table=init(size);
      }
      else if (strcmp(lecture,"insert")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         val = strdup(lecture);
         insert(table,key,val);
      }
      else if (strcmp(lecture,"delete")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         delete(table,key);
      }
      else if (strcmp(lecture,"query")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key=strdup(lecture);
         if(Query(table, key, &val))
			{
				printf("%s\r\n", val);
			}
			else
			{
				printf("Not found\r\n");
			}
      }
      else if (strcmp(lecture,"destroy")==0)
      {
         destroy(table);
      }
      else if (strcmp(lecture,"stats")==0)
      {
         stats(table);
      }

      if (fscanf(stdin,"%99s",lecture)!=1)
         error();
   }
   return 0;
}

HashTable *init (int size){
    HashTable* table=malloc(sizeof(HashTable));
    table->tab=malloc(size*sizeof(Data));
    table->size=size;
    int i;
    for(i=0;i<size;i++){
        table->tab[i].status=EMPTY;
        table->tab[i].key="";
        table->tab[i].val="";
    }
    return table;
}

int recherchePos (HashTable * h, Key key,int *indice){
   int i = HashFunction(key,h->size);
   int savei = i;
   int s=-1;
   do {
      if (h->tab[i].status==EMPTY) {
         *indice = i;
         if (s!=-1)
            *indice = s;
         return 0;
      }
      if (h->tab[i].status==SET && strcmp(h->tab[i].key,key)==0) {
         *indice = i;
         return 1;
      }
      if (h->tab[i].status==REMOVED && s==-1) {
         s = i;
      }
      i = (i+1)%h->size;
   } while (i!=savei);

   *indice = -1;
   return 0;
}

void insert (HashTable * table, Key key,Value val){
    int pos;
    recherchePos(table,key,&pos);
    table->tab[pos].key=key;
    table->tab[pos].status=SET;
    table->tab[pos].val=val;
    //printf("%c ajouté\n",*val);

}

void delete(HashTable * hTable, Key k){
   int indice = HashFunction(k, hTable->size);
	if (strcmp(hTable->tab[indice].key, k) == 0)
	{
		hTable->tab[indice].val = "";
		hTable->tab[indice].key = "";
		hTable->tab[indice].status = REMOVED;
		return;
	}
	int indiceInit = indice++;
	indice %= hTable->size;
	while (hTable->tab[indice].status != EMPTY && indice != indiceInit)
	{
		if (strcmp(hTable->tab[indice].key, k) == 0)
		{
			hTable->tab[indice].val = "";
			hTable->tab[indice].key = "";
			hTable->tab[indice].status = REMOVED;
			return;
		}
		indice++;
		indice %= hTable->size;
	}
   /*int i;
   for(i=0;i<table->size;i++){
      if(strcmp(table->tab[i].key,key)){
         table->tab[i].status=REMOVED;
         printf("%c supp\n",*table->tab[i].val);
         return;
      }
   }*/
}

int Query(HashTable *hTable, Key k, Value *v)
{
	int indice = HashFunction(k, hTable->size);
	if (strcmp(hTable->tab[indice].key, k) == 0)
	{
		*v = hTable->tab[indice].val;
		return 1;
	}
	int indiceInit = indice++;
	indice %= hTable->size;
	while (hTable->tab[indice].status != EMPTY && indice != indiceInit)
	{
		if (strcmp(hTable->tab[indice].key, k) == 0)
		{
			*v = hTable->tab[indice].val;
			return 1;
		}
		indice++;
		indice %= hTable->size;
	}
	return 0;
}

void stats(HashTable *hTable){
   int empty=0,deleted=0,used=0;
   int i;
   for(i=0;i<hTable->size;i++){
      if(hTable->tab[i].status == EMPTY)
         empty++;
      if(hTable->tab[i].status == SET)
         used++;
      if(hTable->tab[i].status == REMOVED)
         deleted++;
   }
   printf("size    : %d\r\n", hTable->size);
	printf("empty   : %d\r\n", empty);
	printf("deleted : %d\r\n", deleted);
	printf("used    : %d\r\n", used);
}

void destroy(HashTable *hTable){
   free(hTable->tab);
   free(hTable);
}

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
  n = n%(sizeof(unsigned int)*8);
  return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
   unsigned int i;
   unsigned int val = 0;
   unsigned int power = 0;
   for (i=0;i<strlen(key);i++)
   {
     val += shift_rotate(key[i],power*7);
     power++;
   }
   return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size)
{
   return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
   return hash(Encode(key),size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */

void error(void)
{
   printf("input error\r\n");
   exit(0);
}