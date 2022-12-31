#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated; /* current allcoation of array */
  int filled;    /* number of items present in the binheap */
  int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);

void permuter(int *array,int i,int j);

int main(void) 
{
  char lecture[100];
  int val;
  BinaryHeap * heap;
  heap = Init(10);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"insert")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(heap,val);
    } else if (strcmp(lecture,"extract")==0) {
      if(ExtractMax(heap,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap;
  heap=(BinaryHeap *) malloc(sizeof(BinaryHeap));
  heap->allocated=size;
  heap->filled=0;
  heap->array=(int *)malloc(sizeof(int)*size);
  return heap;
}

void InsertValue(BinaryHeap * heap, int value)
{
    int indice,pere,tmp;
  if(heap->filled==heap->allocated){
    heap->allocated*=2;
    heap->array=(int *)realloc(heap->array,sizeof(int)*heap->allocated);
  }
  heap->array[heap->filled]=value;
  indice=heap->filled;
  pere=(indice-1)/2;
  while(indice>0 && heap->array[pere]<heap->array[indice]){
    tmp=heap->array[pere];
    heap->array[pere]=heap->array[indice];
    heap->array[indice]=tmp;
    indice=pere;
    pere=(indice-1)/2;
  }
  heap->filled++;
  /*for(int i=0;i<heap->filled;i++){
    printf("%d ",heap->array[i]);
  }*/
}

int ExtractMax(BinaryHeap * heap, int *res)
{
    /*if(heap->filled==0){
        return 0;
    }else{
        *res=heap->array[0];
        heap->array[0]=heap->array[heap->filled-1];
        heap->filled--;
        //heap->array[heap->filled-1]=NULL;

        int indice=0;
        while(indice<(heap->filled-1)/2){
            if(heap->array[indice]<heap->array[indice*2+1] && heap->array[indice*2+2]<heap->array[indice*2+1] ){
                permuter(heap->array,indice,indice*2+1);
            }else if(heap->array[indice]<heap->array[indice*2+2] && heap->array[indice*2+1]<heap->array[indice*2+2]){
                permuter(heap->array,indice,indice*2+2);
            }
            indice++;
        }
        return 1;
    }*/
    if (heap->filled==0)
      return 0;
   int * a = heap->array; 
   *res = a[0];
   heap->filled--;
   a[0] = a[heap->filled];
   int pere = 0;
   int g = 1;
   int d = 2;
   while ((g<heap->filled && a[g]>a[pere]) || (d<heap->filled && a[d]>a[pere])) {
      int iswap = g;
      if (d<heap->filled && a[d]>a[g]) {
         iswap = d;
      }
      int tmp = a[iswap];
      a[iswap] = a[pere];
      a[pere] = tmp;
      pere = iswap;
      g = pere*2+1;
      d = pere*2+2;
   }
   return 1;
    
    
}

void permuter(int *array,int i,int j){
    int tmp=array[i];
    array[i]=array[j];
    array[j]=tmp;
}

void Destroy(BinaryHeap * heap)
{
  free(heap->array);
  free(heap);
}