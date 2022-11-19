#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int m(int **value,int *w,int nb_metal,int capa, int i,int j){
    if(i==0 || j<=0){
        *(*(value+i)+j)=0;
        return 0 ;
    }
    if(*(*(value+i-1)+j)==-1)
        *(*(value+i-1)+j)=m(value,w,nb_metal,capa,i-1,j);
    
    if(*(w+i)>j){
        *(*(value+i)+j)=*(*(value+i-1)+j);
    }else{
        if(*(*(value+i-1)+j-*(w+i))==-1){
            *(*(value+i-1)+j-*(w+i))=m(value,w,nb_metal,capa,i-1,j-*(w+i));
        }
        *(*(value+i)+j)=max(*(*(value+i-1)+j),*(*(value+i-1)+j-*(w+i))+*(w+i));
    }
    return *(*(value+i)+j);
}


int main(){
    int capa1,capa2,nb_or,nb_arg,i,j;

    // Saisie
    fscanf(stdin,"%d",&capa1);
    fscanf(stdin,"%d",&capa2);
    fscanf(stdin,"%d",&nb_or);
    fscanf(stdin,"%d",&nb_arg);

    int tab_or[nb_or+1];
    int tab_arg[nb_arg+1];
    tab_or[0]=0;
    tab_arg[0]=0;
    for(i=1;i<=nb_or;i++){
        fscanf(stdin,"%d",&tab_or[i]);
    }
    for(i=1;i<=nb_arg;i++){
        fscanf(stdin,"%d",&tab_arg[i]);
    }

    int result[4];
    int **value;

    // nb_or capa1
    value=malloc((nb_or+1)*sizeof(int*));
    for(i=0;i<=nb_or;i++){
        value[i]=malloc((capa1+1)*sizeof(int));
        for(j=0;j<=capa1;j++){
            *(*(value+i)+j)=-1;
        }
    }

    //afficher(tab_metal,nb_metal,capa);
    m(value,tab_or,nb_or+1,capa1+1,nb_or,capa1);
    int res=value[nb_or][capa1];
    result[0]=res;

    for(i=0;i<=nb_or;i++){
        free(value[i]);
    }
    free(value);

    //nb_or capa2
    value=malloc((nb_or+1)*sizeof(int*));
    for(i=0;i<=nb_or;i++){
        value[i]=malloc((capa2+1)*sizeof(int));
        for(j=0;j<=capa2;j++){
            *(*(value+i)+j)=-1;
        }
    }
    m(value,tab_or,nb_or+1,capa2+1,nb_or,capa2);
    res=value[nb_or][capa2];
    result[1]=res;

    for(i=0;i<=nb_or;i++){
        free(value[i]);
    }
    free(value);

    //nb_arg capa1
    value=malloc((nb_arg+1)*sizeof(int*));
    for(i=0;i<=nb_arg;i++){
        value[i]=malloc((capa1+1)*sizeof(int));
        for(j=0;j<=capa1;j++){
            *(*(value+i)+j)=-1;
        }
    }
    m(value,tab_arg,nb_arg+1,capa1+1,nb_arg,capa1);
    res=value[nb_arg][capa1];
    result[2]=res;

    for(i=0;i<=nb_arg;i++){
        free(value[i]);
    }
    free(value);

    //nb_arg capa2
    value=malloc((nb_arg+1)*sizeof(int*));
    for(i=0;i<=nb_arg;i++){
        value[i]=malloc((capa2+1)*sizeof(int));
        for(j=0;j<=capa2;j++){
            *(*(value+i)+j)=-1;
        }
    }
    m(value,tab_arg,nb_arg+1,capa2+1,nb_arg,capa2);
    res=value[nb_arg][capa2];
    result[3]=res;

    for(i=0;i<=nb_arg;i++){
        free(value[i]);
    }
    free(value);
    printf("%d\r\n",max(result[0]+result[3],result[1]+result[2]));
    
    
    return 0;
}