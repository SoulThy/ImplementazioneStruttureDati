#include <stdio.h>
#define MAX_ELEMENTI 10

struct strutturaAlbero{
    int arr[MAX_ELEMENTI];
    int numeroElementi;
};

typedef struct strutturaAlbero Albero;

int numNodi(Albero);
int padre(Albero, int);
int *figli(Albero);
void aggiungiNodo(Albero *, int, int);
void aggiungiSottoalbero(Albero *, int);
int rimuoviSottoalbero(Albero *, int);
void stampaAlbero(Albero);

int main() {
    Albero albero;
    albero.numeroElementi = 0;

    aggiungiNodo(&albero, 0, 1);
    aggiungiNodo(&albero, 0, 2);
    aggiungiNodo(&albero, 0, 3);
    aggiungiNodo(&albero, 1, 4);
    aggiungiNodo(&albero, 1, 5);

    stampaAlbero(albero);

    printf("Il padre di [%d] e' [%d]\n", albero.arr[4], padre(albero,4));
    printf("Il padre di [%d] e' [%d]\n", albero.arr[2], padre(albero,2));
    printf("Il padre di [%d] e' [%d]\n", albero.arr[3], padre(albero,3));

}

void stampaAlbero(Albero a) {
    for (int i = 0; i < a.numeroElementi; i++) {
        printf("[%d]", a.arr[i]);
    }
    printf("\n");
}


int numNodi(Albero a){
    return a.numeroElementi;
}

int padre(Albero a, int pos){
    if (numNodi(a) == 0) {
        return 0;
    }
    return a.arr[(pos-1)/2];
}

void aggiungiNodo(Albero *a, int pos, int v){
    if(numNodi(*a) == 0){ //Albero vuoto
        a->arr[0] = v;
        a->numeroElementi ++;
        return;
    }

    if(((pos * 2) + 1) == numNodi(*a)){
        a->arr[(pos * 2) + 1] = v; //metto il figlio come nodo sx
        a->numeroElementi ++;
    } else if (((pos * 2) + 2) == numNodi(*a)){
        a->arr[(pos * 2) + 2] = v; //metto il figlio come nodo dx
        a->numeroElementi ++;
    } else if(((pos * 2) + 1) > numNodi(*a)){
        printf("[!] Impossibile creare un albero sbilanciato.\n");
    } else if(((pos * 2) + 1) < numNodi(*a)){
        printf("[!] Il nodo [%d] ha gia due figli.\n", a->arr[pos]);
    }

}


