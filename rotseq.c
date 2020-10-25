/*
*   gcc rotseq.c -o rotseq
*/

/******************************************************************************************
**                                      CABEÇALHO
******************************************************************************************/
#include "stdio.h"
#include "fifo.c"
#include "matrix.c"
#include "expansion.c"
#include "omp.h"


void printGrid(int **grid){
    printf("\n---------------------------------------------\n");
    for (int i=0; i < width; i++){
        for (int j=0; j < height; j++)
            printf("|%3d  ", grid[i][j]);  
        printf("\n");
    }
}


int main(){
    Fifo * fifo = createFifo();
    Data cel;
    int **grid;
    int x, y, width, height;
    int ox, oy;
    int dx, dy;
    int n = 0;
    int m = 0;
    int nObstacles = 1;
    int tag = 0;
    int coordenadas[] = {tag, -1,-1, -1,-1, -1,-1, -1,-1}; // up, down, left, right
    
    /* omp_get_wtime */
    double start; 
    double end; 
    start = omp_get_wtime();

    scanf("%d %d", &m, &n);             // recebe tamanho da matriz
        grid = createMatrix(m, n);      // cria matriz
        setMatrix(m, n);                // Informa tamanho da matriz para o explorador
    scanf("%d %d", &ox, &oy);           //recebe origem
        setOrigin(grid, ox,oy, tag);    // Marca origem no mapa
    scanf("%d %d", &dx, &dy);           // recebe destino
        setOrigin(grid, dx,dy,-2);      // Marca destino no mapa
    scanf("%d", &nObstacles);           // número de obstaculos


    // desenha obstáculo
    while(nObstacles--){
        scanf("%d %d %d %d", &x, &y, &width, &height);
        createObstacle(grid, x, y,width,height);
    }
    
    /* Inicia exploração */
    while (found != true){
        
        center(grid, ox, oy, coordenadas);
        
        // Percorre vetor coordenadas
        // Vetor coordenadas contém posições vizinhas da célula ox, oy
        for(int i = 1; i < 8; i=i+2){
            x = coordenadas[i];
            y = coordenadas[i+1];

            // Caso o vetor tenha explorado vizinhos roda do mapa, obstáculos ou já explorados
            if(x != -1 && y != -1)
                insert(fifo, createData(x,y, coordenadas[0]+1));

        }
        //printFifo(fifo);
        cel = removed(fifo).data;
        ox = cel.m;
        oy = cel.n;
        coordenadas[0] = cel.level;


        
    }

    // Cálculo de tempo de execução
    end = omp_get_wtime(); 
    printf("Tempo de execução: %f\n", end - start);

    //Debug para saber se realmente achou/parou a célula destino;
    printGrid(grid);
}

