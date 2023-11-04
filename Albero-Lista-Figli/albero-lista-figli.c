// Rappresentazione mediante lista dei figli
#include <stdio.h>

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
NodoAlbero* aggiungiNodo(NodoAlbero* n);

int numNodi(Albero a);
NodoAlbero* padre(Albero a, NodoAlbero* n);
NodoSCL* figli(NodoAlbero* n);
void aggiungiSottoalbero(Albero a, NodoAlbero* n);
Albero rimuoviSottoalbero(Albero* a, NodoAlbero* n);

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