#include "stdio.h"
#include "fifo.c"
#include "matrix.c"


int main(){
    Fifo * fifo = createFifo();

    int **grid;

    int x, y, width, height;
    int ox, oy;
    int dx, dy;
    int n = 0;
    int m = 0;
    int nObstacles = 1;
    scanf("%d %d", &m, &n);     // recebe tamanho da matriz
        grid = createMatrix(m, n); // cria matriz
    scanf("%d %d", &ox, &oy);       //recebe origem
    setOrigin(grid, ox,oy);
    
    scanf("%d %d", &dx, &dy);       // recebe destino
    setOrigin(grid, dx,dy);
    scanf("%d", &nObstacles);       // número de obstaculos


    // desenha obstáculo
    while(nObstacles--){
        scanf("%d %d %d %d", &x, &y, &width, &height);
        createObstacle(grid, x, y,width,height);
    }
    
    printf("\n-----------------------\n");


    //printa matriz
    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++)
            printf("%d ", grid[i][j]);  
        printf("\n");
        
    }

    // // Remover node;
    // Node cel;
    // cel = removed(fifo);
    // printf("celula %d%d removida!.\n", cel.data.n, cel.data.m);
    // printFifo(fifo);

    // cel = removed(fifo);
    // printf("celula %d%d removida!.\n", cel.data.n, cel.data.m);
    // printFifo(fifo);

    // cel = removed(fifo);
    // printf("celula %d%d removida!.\n", cel.data.n, cel.data.m);
    // printFifo(fifo);

    // cel = removed(fifo);
    // printf("celula %d%d removida!.\n", cel.data.n, cel.data.m);
    // printFifo(fifo);

}