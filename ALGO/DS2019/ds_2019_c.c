#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int * rot_gauche(int * tab,int size){
    int i;
    int a=*tab;
    for(i=0;i<size-1;i++){
        *(tab+i)=*(tab+i+1);
    }
    *(tab+size-1)=a;
    return tab;
}

void afficher(int *tab,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",tab[i]);
    }
    printf("\r\n");
}

/*void afficher(int *tab,int nb_lignes,int nb_colonnes){
    int i,j;
    for(i=0;i<nb_lignes;i++){
        for(j=0;j<nb_colonnes;j++){
            printf("%d ",tab[i][j]);
        }
        printf("\r\n");
    }
    printf("\r\n");
}*/

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

/*int max_metal_bateau(int * tab_metal,int nb_metal,int capa){
    int i,j;
    int value[nb_metal][capa];
    for(i=0;i<capa;i++){
        for(j=0;i<nb_metal;j++){
            value[j][i]=-1;
        }
    }
    //afficher(tab_metal,nb_metal,capa);
    return m(value,tab_metal,nb_metal,capa,nb_metal,capa);
}*/

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

    // Tri tab_or et tab_arg
    /*for(i=0;i<=nb_or;i++){
        int ipp=i;
        for(j=i+1;j<=nb_or;j++){
            if(tab_or[j]>tab_or[ipp])
                ipp=j;
        }
        int a=tab_or[ipp];
        tab_or[ipp]=tab_or[i];
        tab_or[i]=a;
    }
    for(i=0;i<=nb_arg;i++){
        int ipp=i;
        for(j=i+1;j<=nb_arg;j++){
            if(tab_arg[j]>tab_arg[ipp])
                ipp=j;
        }
        int a=tab_arg[ipp];
        tab_arg[ipp]=tab_arg[i];
        tab_arg[i]=a;
    }*/

    // Initialistion L et nb
    /*bool L[capa1+1][nb_or+1];
    int nb[capa1+1];
    
    for(i=1;i<=capa1;i++){
        for(j=1;j<=nb_or;j++){
            L[i][j]=false;
        }
    }
    for(i=1;i<=capa1;i++)
        L[i][0]=false;
    for(i=0;i<=nb_or;i++)
        L[0][i]=true;
    for(i=0;i<=capa1;i++)
        nb[i]=0;

    for(i=1;i<=capa1;i++){
        for(j=1;j<=nb_or;j++){
            if(!L[i][j]){
            if((i>=tab[1][j] && L[i-tab[1][j]][j-1]) || L[i][j-1]){
                L[i][j]=true;
                for(k=j;k<=n;k++){
                    L[i][k]=true;
                }

                if(tab[0][j]==1)
                    nb[i]=nb[i-tab[1][j]]+1;
                break;
            }else {
                L[i][j]=false;
            }
            }
        }
    }*/

    //int res=max_metal_bateau(tab_or,nb_or,capa2);
    
    
    /*int value[nb_or][capa1];
    for(i=0;i<capa1;i++){
        for(j=0;j<nb_or;j++){
            value[j][i]=-1;
        }
    }*/
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
    //printf("%d\r\n",res);
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
    //printf("%d\r\n",res);
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
    //printf("%d\r\n",res);
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
    //printf("%d\r\n",res);
    result[3]=res;

    for(i=0;i<=nb_arg;i++){
        free(value[i]);
    }
    free(value);
    printf("%d\r\n",max(result[0]+result[3],result[1]+result[2]));

    
    return 0;
}