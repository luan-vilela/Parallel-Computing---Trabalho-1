#ifndef MATRIX_H 
#define MATRIX_H

int **createMatrix(int n, int m);
void **createObstacle(int **matrix, int x, int y, int width, int height);
void **setOrigin(int **matrix, int x, int y);

#endif