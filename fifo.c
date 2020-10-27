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
    node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if( queue->last == NULL)
        queue->begin = node;
    else
        queue->last->next = node;
    queue->last = node;
 
}
/* Remove um nó dá fila */
Data removed(Fifo *queue){
     
    Data data;
    if (queue->begin != NULL){   
        Node  *p;
        p = queue->begin;
        queue->begin = queue->begin->next;
        data = p->data;
        free(p);
    }
    return data;
    

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
bool isEmpty(Fifo *queue){
    if (queue->begin != NULL)
        if (queue->last != NULL)
            return false;
    
    return true;
}


/******************************************************************************************
**                                     PRINT PARA DEBUG
******************************************************************************************/
void printFifo(Fifo *queue){
    printf("\n------------ fifo ---------------\n");
    Node  *aux = queue->begin;
    while(aux != NULL){
        printCel(aux->data);
        aux = aux->next;
    }
    printf("\n------------ fifo ---------------\n");
}

void printCel(Data cell){
    if (cell.m == 0) 
        printf("%d%d ", cell.m, cell.n);
    //printf("%d ", cell.level);
}