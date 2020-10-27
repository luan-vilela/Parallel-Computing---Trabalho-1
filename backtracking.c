
#include "backtracking.h"
#include <stdio.h>
/******************************************************************************************
**                                VARIÁVEIS E MACROS
******************************************************************************************/


void back(int **matrix, int x, int y, int *vx, int *vy){
    int nx, ny;
    int nextLevel = matrix[x][y];
    nx = x;
    ny = y-1;

    if ( nextLevel-1 == matrix[x][y+1]){
        nextLevel = matrix[x][y+1];
        nx = x;
        ny = y+1;
    }
    else if ( nextLevel-1 == matrix[x-1][y] ){
        nextLevel = matrix[x-1][y];
        nx = x-1;
        ny = y;
    }
    else if (nextLevel-1 == matrix[x+1][y] ){
        nextLevel = matrix[x+1][y];
        nx = x+1;
        ny = y;
    }
    else{
        nextLevel = matrix[x][y-1];
        nx = x;
        ny = y-1;

    }
    //printf("%d %d %d\n", nextLevel, nx, ny);
    vx[nextLevel] = nx;
    vy[nextLevel] = ny;

}