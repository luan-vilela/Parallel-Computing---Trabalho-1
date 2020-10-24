#include "expansion.h"
#include "stdio.h"

bool found = false;

//Salva tamanho da matriz
int width = 0, height = 0;


/* Seta tamanho do matriz/mapa*/
void setMatrix(int x, int y){
    width = x;
    height = y;
}

void **center(int **matrix, int x, int y, int tag){
    int currentLevel = matrix[x][y];
    
    // Verifica se célula atual é um obstáculo.
    if(currentLevel == -1 || found == true)
        return (NULL);
    
    // Verifica se célula atual é o destino.
    if(currentLevel == -2){
        found = true;
        printf("....................x:%d - y:%d = %d......................\n", x,y,tag);
    }
    
    if(currentLevel > tag-1){

        // Escreve posição da célula descoberta 
        matrix[x][y] = tag;
        //up
        if(y > 0)
            center(matrix, x, y-1, tag+1);
        //down
        if (y < height-1)
            center(matrix, x, y+1, tag+1);
        //left
        if (x > 0)
             center(matrix, x-1, y, tag+1);
        //right
            if (x < width-1)
             center(matrix, x+1, y, tag+1);
    }

    


}