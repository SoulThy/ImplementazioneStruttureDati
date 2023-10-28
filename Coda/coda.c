#include <stdio.h>
#define MAX_ELEMENTI 10

struct strutturaCoda{
    int arr[MAX_ELEMENTI];
    int numeroElementi;
};

typedef struct strutturaCoda Coda;

void stampaCoda(Coda c);
int isEmpty(Coda);
void enqueue(Coda *, int e);
int dequeue(Coda *);
int first(Coda);

int main(){
    Coda coda;
    coda.numeroElementi = 0;

    enqueue(&coda,1);
    enqueue(&coda,2);
    enqueue(&coda,3);
    enqueue(&coda,4);
    enqueue(&coda,5);
    enqueue(&coda,6);

    stampaCoda(coda);

    printf("Dopo dequeue() = \n");
    dequeue(&coda);
    stampaCoda(coda);

    printf("Dopo first() = \n");
    printf("Il primo elemento e' [%d]\n", first(coda));
    stampaCoda(coda);

}

int isEmpty(Coda c){
    for (int i = 0; i < c.numeroElementi; i++) {
        if (c.arr[i]){
            return 1;
        }
    }
    return 0;
}

int first(Coda c){
    if (c.numeroElementi == 0)
        return 0;

    return c.arr[c.numeroElementi-1];
}

void enqueue(Coda *c, int e){
    if(c->numeroElementi >= MAX_ELEMENTI)
        return;

    c->arr[c->numeroElementi] = e;
    c->numeroElementi++;
}

int dequeue(Coda *c){
    if (c->numeroElementi == 0)
        return 0;

    int elementoRimosso = c->arr[0];

    c->numeroElementi--;
    for (int i = 0; i < c->numeroElementi; ++i) {
        c->arr[i] = c->arr[i+1];
    }

    return elementoRimosso;
}

void stampaCoda(Coda c) {
    for (int i = 0; i < c.numeroElementi; i++) {
        printf("[%d]", c.arr[i]);
    }
    printf("\n");
}
