#include "stdio.h"
#include "fifo.c"

int main(){
    Fifo * fifo = createFifo();

    int n = 0;
    int m = 0;

    for(n = 0; n < 8; n++)
        for(m = 0; m < 8; m++)
            insert(fifo, createData(n,m,INF));

    printFifo(fifo);


    // Remover node;
    Node cel;
    cel = removed(fifo);
    printf("celula %d%d removida!.\n", cel.data.n, cel.data.m);
    printFifo(fifo);

    cel = removed(fifo);
    printf("celula %d%d removida!.\n", cel.data.n, cel.data.m);
    printFifo(fifo);

    cel = removed(fifo);
    printf("celula %d%d removida!.\n", cel.data.n, cel.data.m);
    printFifo(fifo);

    cel = removed(fifo);
    printf("celula %d%d removida!.\n", cel.data.n, cel.data.m);
    printFifo(fifo);

}