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
**                                VARIÁVEIS E CONSTANTES
******************************************************************************************/
#define UP (y > 0)
#define DOWN (y < height-1)
#define RIGHT (x < width-1)
#define LEFT (x > 0)

bool found = false;         //variável de controle, true achou destino
int width = 0, height = 0;  //Salva tamanho do mapa, para referência expansão 

/******************************************************************************************
**                                      MÉTODOS
******************************************************************************************/

/*
    Método recebe uma coordenada x, y de uma matriz e retorna seus vizinhos.
    Método também verifica se chegou no destino, obstáculo ou se já esteve na célula.
*/
/*
    Código antigo com bug, o center passava a posição de 4 vizinhos e os 4 vizinhos passavam a posição do center
    Método alterado para FOFOQUEIRO, ele verifica se existe vizinho antes de passar posição. Tempo de carga vai aumentar, porém
    vai melhorar consumo de memória na pilha.
*/
void center(int **matrix, int x, int y, int *v, int tag){
    int currentLevel = matrix[x][y];

    // Verifica se célula atual é um obstáculo.
    if(currentLevel != -1 || found != true){
                    
        // Verifica se célula atual é o destino.
        if(currentLevel == -2){
            found = true;
            printf("\n:D -> Destino %dx%d\n\t level: %d\n\n", x, y, tag);
        }
        else
            // Verifica se a célula atual pode ser modificada
            if(currentLevel > tag || currentLevel == INF){
                // Escreve posição da célula descoberta
              
                matrix[x][y] = tag;
                
                // // Reseta coordenadas
                // for(int i = 0; i < 8; i++)
                //     v[i] = -1;
                
                //up
                if UP {
                    if (fofoqueiro(currentLevel, matrix[x][y-1])){
                        v[0] = x; 
                        v[1] = y-1;
                    }
                }
                //down
                if DOWN {
                    if (fofoqueiro(currentLevel, matrix[x][y+1])) {
                        v[2] = x; 
                        v[3] = y+1;
                    }
                }
                //left
                if LEFT {
                    if (fofoqueiro(currentLevel, matrix[x-1][y])){
                        v[4] = x-1; 
                        v[5] = y;
                        }
                }
                //right
                if RIGHT {
                    if (fofoqueiro(currentLevel, matrix[x+1][y])){
                        v[6] = x+1; 
                        v[7] = y;
                        }
                }
                
            }
    }
}

int fofoqueiro(int fofoqueiro, int vizinho){
    return vizinho == INF || fofoqueiro+1 < vizinho ? 1 : 0;
}


/* Seta tamanho do matriz/mapa*/
void setMatrix(int x, int y){
    width = x;
    height = y;
}
