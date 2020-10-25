#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"

Fifo * createFifo(){
    Fifo * fifo;
    fifo = (Fifo*)malloc(sizeof(Fifo));
    fifo->begin = NULL;
    fifo->last = NULL;
    return fifo;
}

Data createData(int m, int n, int level){
    Data data;
    data.m = m;
    data.n = n;
    data.level = level;
    return data;
}

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