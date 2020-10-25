#include "stdio.h"
#include "fifo.c"
#include "matrix.c"
#include "expansion.c"

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

    //printa matriz
    printf("\n-----------------------\n");
    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++)
            printf("%d ", grid[i][j]);  
        printf("\n");
        
    }
    

    //int temp = 4*4;
    while (found != true){
        
        center(grid, ox, oy, coordenadas);
        
        for(int i = 1; i < 8; i=i+2){
            x = coordenadas[i];
            y = coordenadas[i+1];
            //printf("x: %d, y: %d\n", x, y);
            if(x != -1 && y != -1)
                insert(fifo, createData(x,y, coordenadas[0]+1));
        }
        // resolver tag
        //printFifo(fifo);
        cel = removed(fifo).data;
        ox = cel.m;
        oy = cel.n;
        coordenadas[0] = cel.level;


        
    }

    
            
    printf("\n----------%d(%d%d)-------------\n", coordenadas[0], ox,oy);
    //printa matriz

    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++)
            printf("%d ", grid[i][j]);  
        printf("\n");
    }
    
    
    // printf("\n-----------------------\n");
    // //printa matriz
    // for (int i=0; i < m; i++){
    //     for (int j=0; j < n; j++)
    //         printf("%d ", grid[i][j]);  
    //     printf("\n");
        
    // }

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

/*
8 8
3 5
2 1
3
2 2 5 1
1 5 1 2
2 6 2 1




*/