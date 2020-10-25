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

void *center(int **matrix, int x, int y, int *v){
    int currentLevel = matrix[x][y];
    int tag = v[0];
    v[0] = v[0] + 1;    // Atualiza número da celula

    // Verifica se célula atual é um obstáculo.
    if(currentLevel == -1 || found == true)
        return (NULL);
    
    // Verifica se célula atual é o destino.
    if(currentLevel == -2){
        found = true;
        printf("....................x:%d - y:%d = %d......................\n", x,y,tag);
    }

    // Verifica se a célula atual pode ser modificada
    if(currentLevel > tag-1){
        // Escreve posição da célula descoberta 
        matrix[x][y] = tag;
        //up
        if(y > 0){
            //center(matrix, x, y-1, tag+1);
            v[1] = x; 
            v[2] = y-1;
        }
        else{
            v[1] = -1; 
            v[2] = -1;
        
        }   
        //down
        if (y < height-1){
            //center(matrix, x, y+1, tag+1);
            v[3] = x; 
            v[4] = y+1;
        }
        else{
            v[3] = -1; 
            v[4] = -1;
        
        }
        //left
        if (x > 0){
            //center(matrix, x-1, y, tag+1);
            v[5] = x-1; 
            v[6] = y;
        }
        else{
            v[5] = -1; 
            v[6] = -1;
        
        }
        //right
        if (x < width-1){
            //center(matrix, x+1, y, tag+1);
            v[7] = x+1; 
            v[8] = y;
        }
        else{
            v[7] = -1; 
            v[8] = -1;
        
        }
        
    }

    


}