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
#include "expansion.h"
#include "stdio.h"

/******************************************************************************************
**                                      VARIÁVEIS
******************************************************************************************/
bool found = false;         //variável de controle, true achou destino
int width = 0, height = 0;  //Salva tamanho do mapa, para referência expansão 

/******************************************************************************************
**                                      MÉTODOS
******************************************************************************************/

/*
    Método recebe uma coordenada x, y de uma matriz e retorna seus vizinhos.
    Método também verifica se chegou no destino, obstáculo ou se já esteve na célula.
*/
void center(int **matrix, int x, int y, int *v, int tag){
    int currentLevel = matrix[x][y];
     v[0] = tag;

    // Verifica se célula atual é um obstáculo.
    if(currentLevel == -1 || found == true)
        return ;
    
    // Verifica se célula atual é o destino.
    if(currentLevel == -2){
        found = true;
        printf("\n:D -> Destino %dx%d\n\t level: %d\n\n", x, y,tag);
    }

    // Verifica se a célula atual pode ser modificada
    if(currentLevel+1 > tag){
        // Escreve posição da célula descoberta 
        matrix[x][y] = tag;
        //up
        if(y > 0){
            v[1] = x; 
            v[2] = y-1;
        }
        else{
            v[1] = -1; 
            v[2] = -1;
        
        }   
        //down
        if (y < height-1){
            v[3] = x; 
            v[4] = y+1;
        }
        else{
            v[3] = -1; 
            v[4] = -1;
        
        }
        //left
        if (x > 0){
            v[5] = x-1; 
            v[6] = y;
        }
        else{
            v[5] = -1; 
            v[6] = -1;
        
        }
        //right
        if (x < width-1){
            v[7] = x+1; 
            v[8] = y;
        }
        else{
            v[7] = -1; 
            v[8] = -1;
        
        }
        
    }
}

/* Seta tamanho do matriz/mapa*/
void setMatrix(int x, int y){
    width = x;
    height = y;
}
