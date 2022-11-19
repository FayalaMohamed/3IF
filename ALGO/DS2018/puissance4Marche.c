#include <stdio.h>
#include <stdlib.h>

/*int existSol(int nbLignes,char * tab[6],int nbColonnes,char car ){
    int i,j;

    //verif alignement Vertical
    for(j=0;j<nbColonnes;j++){
        for(i=0;i<nbLignes-4;i++){
            if(tab[j][i]==car 
                && tab[j][i+1]==car 
                && tab[j][i+2]==car 
                && tab[j][i+3]==car)
            return 1;
        }
    }

    //verif alignement HORIZONTAL
    for(j=0;j<nbLignes;j++){
        for(i=0;i<nbColonnes-4;i++){
            if(tab[i][j]==car 
                && tab[i+1][j]==car 
                && tab[i+2][j]==car 
                && tab[i+3][j]==car)
            return 1;
        }
    }

    //verif alignement DIAGONAL HAUT-BAS
    for(j=0;j<nbLignes-4;j++){
        for(i=nbColonnes-4;i<nbColonnes;i++){
            if(tab[i][j]==car 
                && tab[i-1][j-1]==car 
                && tab[i-2][j-2]==car 
                && tab[i-3][j-3]==car)
            return 1;
        }
    }

    //verif alignement DIAGONAL BAS-HAUT
    for(j=0;j<nbLignes-4;j++){
        for(i=0;i<nbColonnes-4;i++){
            if(tab[i][j]==car 
                && tab[i+1][j+1]==car 
                && tab[i+2][j+2]==car 
                && tab[i+3][j+3]==car)
            return 1;
        }
    }

    return 0;   
}*/
int main(){
    int nbColonnes=7,nbLignes=6,res=0,i,j;
    char tab[nbColonnes][nbLignes];

    char tmp,car='R';
    for ( i=0;i<6;i++) {
        for (j=0;j<7;j++) {
            fscanf(stdin,"%c",&(tab[j][5-i]));
        }
        fscanf(stdin,"%c",&tmp); /* new line */
    }

    //verif alignement Vertical
    for(j=0;j<nbColonnes;j++){
        for(i=0;i<nbLignes-3;i++){
            if(tab[j][i]==car 
                && tab[j][i+1]==car 
                && tab[j][i+2]==car 
                && tab[j][i+3]==car)
            res= 1;
        }
    }

    //verif alignement HORIZONTAL
    for(j=0;j<nbLignes;j++){
        for(i=0;i<nbColonnes-3;i++){
            if(tab[i][j]==car 
                && tab[i+1][j]==car 
                && tab[i+2][j]==car 
                && tab[i+3][j]==car)
            res= 1;
        }
    }

    //verif alignement DIAGONAL HAUT-BAS
    for(j=0;j<nbLignes-3;j++){
        for(i=nbColonnes-4;i<nbColonnes;i++){
            if(tab[i][j]==car 
                && tab[i-1][j-1]==car 
                && tab[i-2][j-2]==car 
                && tab[i-3][j-3]==car)
            res= 1;
        }
    }

    //verif alignement DIAGONAL BAS-HAUT
    for(j=0;j<nbLignes-3;j++){
        for(i=0;i<nbColonnes-3;i++){
            if(tab[i][j]==car 
                && tab[i+1][j+1]==car 
                && tab[i+2][j+2]==car 
                && tab[i+3][j+3]==car)
            res= 1;
        }
    }

    if(res==1){
        printf("%c\r\n",car);
    }else{
        car='J';
        res=0;
        //verif alignement Vertical
        for(j=0;j<nbColonnes;j++){
            for(i=0;i<nbLignes-3;i++){
                if(tab[j][i]==car 
                    && tab[j][i+1]==car 
                    && tab[j][i+2]==car 
                    && tab[j][i+3]==car)
                res= 1;
            }
        }

        //verif alignement HORIZONTAL
        for(j=0;j<nbLignes;j++){
            for(i=0;i<nbColonnes-3;i++){
                if(tab[i][j]==car 
                    && tab[i+1][j]==car 
                    && tab[i+2][j]==car 
                    && tab[i+3][j]==car)
                res= 1;
            }
        }

        //verif alignement DIAGONAL HAUT-BAS
        for(j=0;j<nbLignes-3;j++){
            for(i=nbColonnes-4;i<nbColonnes;i++){
                if(tab[i][j]==car 
                    && tab[i-1][j-1]==car 
                    && tab[i-2][j-2]==car 
                    && tab[i-3][j-3]==car)
                res= 1;
            }
        }

        //verif alignement DIAGONAL BAS-HAUT
        for(j=0;j<nbLignes-3;j++){
            for(i=0;i<nbColonnes-3;i++){
                if(tab[i][j]==car 
                    && tab[i+1][j+1]==car 
                    && tab[i+2][j+2]==car 
                    && tab[i+3][j+3]==car)
                res= 1;
            }
        }

        if(res==1){
            printf("%c\r\n",car);
        }else{
            printf("0\r\n");
        }
    }
    /*if(existSol(6,tab,7,'R')) printf("R\r\n");
    else if(existSol(6,tab,7,'J')) printf("J\r\n");
    else printf("0\r\n");*/


    return 0;
}