/*
*   fifo.c
*   Esse arquivo faz parte do trabalho-1 de programação paralela da turma 2020/02 (t2)
*   Faculdade Facom - UFMS
*   
*   Arquivo responsável pela criação de uma fila fifo.
*
*/

/******************************************************************************************
**                                      CABEÇALHO
******************************************************************************************/
#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"

/******************************************************************************************
**                                      MÉTODOS
******************************************************************************************/
/* Aloca Fifo na memória */
Fifo * createFifo(){
    Fifo * fifo;
    fifo = (Fifo*)calloc(1,sizeof(Fifo));
    fifo->begin = NULL;
    fifo->last = NULL;
    return fifo;
}
/* Cria Data(célula) para ser usado em um nó */
Data createData(int m, int n, int level){
    Data data;
    data.m = m;
    data.n = n;
    data.level = level;
    return data;
}
/* Insere um nó na fila, recebendo uma Data(célula) */
void insert(Fifo *queue, Data data){  

    Node *node;
    node = (Node*)calloc(1,sizeof(Node));
    node->data = data;
    node->next = NULL;

    if( queue->last == NULL)
        queue->begin = node;
    else
        queue->last->next = node;
    queue->last = node;
 
}
/* Remove um nó dá fila */
Node removed(Fifo *queue){
    if (queue->begin != NULL){    
        Node *node = queue->begin;
        queue->begin = queue->begin->next;
        return *node;
    }

}

// Retorna primeiro da fila
Data front(Fifo *queue){
    return queue->last->data;
}
// Retorna ultimo da fila 
Data rear(Fifo *queue){
    return queue->begin->data;
}

// Verifica se a fila está vazia
// Retorna 0 para cheia e 1 para vazia
bool isEmpty(Fifo queue){
    if (queue.begin != NULL)
        if (queue.last != NULL)
            return false;
    
    return true;
}


/******************************************************************************************
**                                     PRINT PARA DEBUG
******************************************************************************************/
void printFifo(Fifo *queue){
    Node  *aux = queue->begin;
    while(aux != NULL){
        printCel(aux->data);
        aux = aux->next;
    }
    printf("\n");
     printf("\n");
}

void printCel(Data cell){
    if (cell.m == 0) 
        printf("\n");
    printf("%d%d ", cell.n, cell.m);
    //printf("%d ", cell.level);
}