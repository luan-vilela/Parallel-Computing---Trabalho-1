/*
*   expansion.c
*   Esse arquivo faz parte do trabalho-1 de programação paralela da turma 2020/02 (t2)
*   Faculdade Facom - UFMS
*   
*   Arquivo responsável pela expansão e descoberta de célula.
*
*/

/******************************************************************************************
**                                      CABEÇALHO
******************************************************************************************/
#include "matrix.h"
#include "stdio.h"
#include <omp.h>

/*
    Cria uma matriz dinâmica mxn e coloca INF em todas as células
*/
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
   
    // Não fez diferença para matrizes pequenas
    #pragma omp parallel
    {
        /* aloca as colunas da matriz */
        #pragma omp for
        for ( i = 0; i < m; i++ ) {
            v[i] = (int*) calloc (n, sizeof(int));	/* m vetores de n floats */
            // if (v[i] == NULL) {
            //     printf ("** Erro: Memoria Insuficiente **");
            //     return (NULL);
            // }
            // Coloca valor infinito em todas as células
            for( int j = 0; j < n; j++)
                v[i][j]= INF;
        }
    }
  return v; /* retorna o ponteiro para a matriz */
}

/*  Constroi obstáculos retangulares */
void **createObstacle(int **matrix, int x, int y, int width, int height){
    for(int i = x; i < x+width; i++){
        for(int j = y; j < y+height; j++)
            matrix[i][j] = -1;
    }
}

void **setOrigin(int **matrix, int x, int y, int value){
    matrix[x][y] = value;
}