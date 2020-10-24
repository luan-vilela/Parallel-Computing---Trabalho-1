#include "matrix.h"
#include "stdio.h"


int **createMatrix (int m, int n){
    int **v;  /* ponteiro para a matriz */
    int   i;    /* variavel auxiliar      */
    if (m < 1 || n < 1) { /* verifica parametros recebidos */
        printf ("** Erro: Parametro invalido **\n");
        return (NULL);
    }
  /* aloca as linhas da matriz */
    v = (int **) calloc (m, sizeof(int *));	// Um vetor de m ponteiros para float */
        if (v == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
  /* aloca as colunas da matriz */
    for ( i = 0; i < m; i++ ) {
        v[i] = (int*) calloc (n, sizeof(int));	/* m vetores de n floats */
        if (v[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
        // Coloca valor infinito em todas as células
        for(int j = 0; j < n; j++)
            v[i][j]= INF;
    }
  return v; /* retorna o ponteiro para a matriz */
}

void **createObstacle(int **matrix, int x, int y, int width, int height){
    for(int i = x; i < x+width; i++){
        for(int j = y; j < y+height; j++)
            matrix[i][j] = -1;
    }
}

void **setOrigin(int **matrix, int x, int y){
    matrix[x][y] = 0;
}