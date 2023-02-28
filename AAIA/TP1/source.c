#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const double upsilon = 1.0e-10;
const double alpha = 0.9;

typedef struct{
    int n; // number of vertices in the graph
    int* nbSucc; // for each 0<=i<n, nbSucc[i] = number of successors of i
    int** succ; // for each 0<=i<n and each 0<=j<nbSucc[i], succ[i][j]=jth successor of i
} DIGRAPH;


DIGRAPH* readDigraph(FILE *fp){
    // return the DIGRAPH contained in file fp
    DIGRAPH *g = (DIGRAPH*)malloc(sizeof(DIGRAPH));
    if (fscanf(fp, "%d\n", &(g->n)) != 1 || g->n <= 0){
        printf("erreur de lecture du fichier\n");
        exit(1);
    }
    g->nbSucc = (int*)malloc(g->n*sizeof(int));
    g->succ = (int**)malloc(g->n*sizeof(int*));
    int succ[g->n];
    for (int i=0; i<g->n; i++){
        g->nbSucc[i] = 0;
        while (1){
            if (fscanf(fp, "%d", &(succ[g->nbSucc[i]])) != 1 || succ[g->nbSucc[i]] >= g->n){
                printf("erreur de lecture du fichier\n");
                exit(1);
            }
            if (succ[g->nbSucc[i]]<0) break;
            g->nbSucc[i]++;
        };
        g->succ[i] = (int*)malloc(g->nbSucc[i]*sizeof(int));
        memcpy(g->succ[i], succ, g->nbSucc[i]*sizeof(int));
    }
    return g;
}

void printDigraph(DIGRAPH *g){
    // For each vertex of g, display the list of its successors
    for (int i=0; i<g->n; i++){
        printf("Vertex %d has %d successors: ", i, g->nbSucc[i]);
        for (int j=0; j<g->nbSucc[i]; j++)
            printf("%d ", g->succ[i][j]);
        printf("\n");
    }
}

void exo2(DIGRAPH* g){
    printf("\n");
    double s[g->n];
    double sp[g->n];
    printf("s0= ( ");
    for (int k = 0; k < g->n; k++)
    {
        s[k] = 1.0 / g->n;
        printf("%f ", s[k]);
    }
    printf(")\n");
    int k = 1;
    // Tant que la différence entre les nouveaux scores et les anciens n'est pas < upsilon pour tout sommet du graphe faire :
    while (true)
    {
        // Initialiser le nouveau tableau de score à 0
        for (int i = 0; i < g->n; i++)
            sp[i] = 0.0;
        // Pour tout sommet du graphe :
        for (int i = 0; i < g->n; i++)
        {
            // Distribuer sa proba sur tous ses successeurs de manière équitable
            for (int j = 0; j < g->nbSucc[i]; j++)
            {
                sp[g->succ[i][j]] += s[i] / g->nbSucc[i];
            }
        }

        printf("s%d= ( ", k);
        for (int j = 0; j < g->n; j++)
        {
            printf("%f ", sp[j]);
        }
        
        
        k++;
        int nb = 0;
        // Faire la somme des proba du score
        double somme = 0.0;
        for (int j = 0; j < g->n; j++)
        {
            somme += sp[j];
            if (fabs(sp[j] - s[j]) <= upsilon)
                nb++;
        }
        memcpy(s, sp, g->n * sizeof(double));

        printf(") %f\n",somme);

        if (nb == g->n)
            break;
    }
    printf("\n");
}

void exo4(DIGRAPH *g)
{
    printf("\n");
    double s[g->n];
    double sp[g->n];
    printf("s0= ( ");
    for (int k = 0; k < g->n; k++)
    {
        s[k] = 1.0 / g->n;
        printf("%f ", s[k]);
    }
    printf(")\n");
    int k = 1;
    while (true)
    {
        double scoreAbs = 0.0;
        for (int i = 0; i < g->n; i++)
            sp[i] = 0.0;
        for (int i = 0; i < g->n; i++)
        {
            for (int j = 0; j < g->nbSucc[i]; j++)
            {
                sp[g->succ[i][j]] += s[i] / g->nbSucc[i];
            }

            // Si le sommet est absorbant (pas de successeurs) : on distribue sa proba à tous les sommets du graphe
            if (g->nbSucc[i]==0){
                scoreAbs += s[i];
            }
        }
        for (int j = 0; j < g->n; j++)
        {
            sp[j] += scoreAbs / g->n;
        }

        printf("s%d= ( ", k);
        for (int j = 0; j < g->n; j++)
        {
            printf("%f ", sp[j]);
        }

        k++;
        int nb = 0;
        double somme = 0.0;
        for (int j = 0; j < g->n; j++)
        {
            somme += sp[j];
            if (fabs(sp[j] - s[j]) <= upsilon)
                nb++;
        }
        memcpy(s, sp, g->n * sizeof(double));

        printf(") %f\n", somme);

        if (nb == g->n)
            break;
    }
    printf("\n");
}

void getRank(double *s, int n)
{
    double max = -1.0;
    int indice = -1;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] > max)
            {
                max = s[i];
                indice = i;
            }
        }
        max = -1.0;
        s[indice] = -2.0;
        printf("%d", indice);
        if(k !=n-1)
            printf(", ");
    }
}

void exo6(DIGRAPH *g)
{
    printf("\n");
    double s[g->n];
    double sp[g->n];
    printf("s0= ( ");

    for (int k = 0; k < g->n; k++)
    {
        s[k] = 1.0 / g->n;
        printf("%f ", s[k]);
    }
    printf(")\n");
    int k = 1;
    while (true)
    {
        double scoreAbs = 0.0;
        // Initialiser  le nouveau tableau de score à 1.0/n
        for (int i = 0; i < g->n; i++)
            sp[i] = (1.0-alpha)/g->n;
        for (int i = 0; i < g->n; i++)
        {
            for (int j = 0; j < g->nbSucc[i]; j++)
            {
                sp[g->succ[i][j]] += alpha * s[i] / g->nbSucc[i];
            }

            // Si le sommet est absorbant (pas de successeurs) : on distribue sa proba à tous les sommets du graphe
            if (g->nbSucc[i] == 0)
            {
                scoreAbs += s[i];
            }
        }
        for (int j = 0; j < g->n; j++)
        {
            sp[j] += alpha* scoreAbs / g->n;
        }

        printf("s%d= ( ", k);
        for (int j = 0; j < g->n; j++)
        {
            printf("%f ", sp[j]);
        }

        k++;
        int nb = 0;
        double somme = 0.0;
        for (int j = 0; j < g->n; j++)
        {
            somme += sp[j];
            if (fabs(sp[j] - s[j]) <= upsilon)
                nb++;
        }
        memcpy(s, sp, g->n * sizeof(double));

        printf(") %f\n", somme);

        if (nb == g->n)
            break;
    }
    printf("\n");
    getRank(s,g->n);
    printf("\n");
}

void freeDiagraph(DIGRAPH *g)
{
    for (int i = 0; i < g->n; i++){
        free(g->succ[i]);  
    }
    free(g->succ);
    free(g->nbSucc);
    free(g);
}

int main()
{
    FILE* fp  = fopen("exemple2.txt", "r");
    DIGRAPH* g = readDigraph(fp);
    fclose(fp);
    printDigraph(g);
    
    exo4(g);
    
    freeDiagraph(g);
    return 0;
}
