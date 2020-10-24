#ifndef FIFO_H 
#define FIFO_H 

#define INF 2147483647

// Guarda uma célula de fila
typedef struct _data{
    int n;
    int m;
    long int level;
}Data;

//Guarda uma posição na fila
typedef struct _node{
    struct _data data;
    struct _node *next;

}Node;

// Mantém registro do início e final da fila
typedef struct _fifo{
    struct _node *begin;
    struct _node *last;
}Fifo;


typedef enum {false, true} bool;

Node removed(Fifo *queue);
void insert(Fifo *queue, Data data);

Fifo * createFifo();

Data createData(int n, int m, int level);
Data front(Fifo *queue); // início
Data rear(Fifo *queue); // fim

bool isEmpty(Fifo queue);

void printCel(Data cell);
void printFifo(Fifo *queue);
#endif