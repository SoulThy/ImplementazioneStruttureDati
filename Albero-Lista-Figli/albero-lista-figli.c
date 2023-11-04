// Rappresentazione mediante lista dei figli
#include <stdio.h>
#include <stdlib.h>

typedef char TipoInfo;
struct NodoSCL;

typedef struct{
    TipoInfo info;
    struct NodoSCL *figli;
} NodoAlbero;

typedef struct{
    NodoAlbero* figlio;
    struct NodoSCL* next;
} NodoSCL;

typedef NodoAlbero* Albero;

int grado(Albero);
Albero aggiungiNodo(Albero);

int numNodi(Albero a);
Albero padre(Albero a, Albero n);
NodoSCL* figli(Albero n);
void aggiungiSottoalbero(Albero a, Albero n);
Albero rimuoviSottoalbero(Albero* a, Albero n);

void stampa(Albero a);

int main(){
    Albero a = NULL;
};

int grado(Albero n){
    int g = 0;
    NodoSCL* aux = (NodoSCL *) n->figli;
    while (aux != NULL){ //Scansiona tutti i figli
        g += 1; // aggiunge 1 a g per ogni figlio del nodo n
        aux = (NodoSCL *) aux->next;
    }
    return g;
}

Albero aggiungiNodo(Albero n){ //E' piu' un allocazione Nodo.
    if (n == NULL) {
        return NULL;
    }

    NodoAlbero* nuovo = malloc(sizeof(NodoAlbero));
    nuovo->figli = NULL;
    NodoSCL* nodoSCL = malloc(sizeof(NodoSCL));
    nodoSCL->figlio = nuovo;
    nodoSCL->next = n->figli;

    return nuovo;
};

