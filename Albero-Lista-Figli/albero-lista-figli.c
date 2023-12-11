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
Albero aggiungiNodo(Albero*);
int numNodi(Albero a);
Albero padre(Albero a, Albero n);
NodoSCL* figli(Albero n);
void aggiungiSottoalbero(Albero a, Albero n);

Albero rimuoviSottoalbero(Albero* a, Albero n);

void stampa(Albero);

int main(){
    NodoAlbero *nuovoNodo = NULL;
    NodoAlbero *nuovoNodo2 = NULL;
    Albero a = NULL;

    //( [a] ( [c] )( [b] ( [e] )( [d] )))
    nuovoNodo = aggiungiNodo(&a);
    nuovoNodo->info = 'a';
    nuovoNodo2 = aggiungiNodo(&a);
    nuovoNodo2->info = 'b';
    nuovoNodo = aggiungiNodo(&a);
    nuovoNodo->info = 'c';
    nuovoNodo = aggiungiNodo(&nuovoNodo2);
    nuovoNodo->info = 'd';
    nuovoNodo = aggiungiNodo(&nuovoNodo2);
    nuovoNodo->info = 'e';

    stampa(a);

    printf("\nIl numero totale di nodi e': %d", numNodi(a));

    printf("\nIl padre di [%c] e' [%c]", nuovoNodo->info, padre(a,nuovoNodo)->info);
}

void stampa(Albero a){
    if (a == NULL) {
        printf("()");
        return;
    }
    printf("( [%c] ", a->info);
    NodoSCL* aux = (NodoSCL *) a->figli;
    while (aux != NULL) {
        stampa(aux->figlio);
        aux = (NodoSCL *) aux->next;
    }
    printf(")");
}

int grado(Albero a){
    int g = 0;
    NodoSCL* aux = (NodoSCL *) a->figli;
    while (aux != NULL){ //Scansiona tutti i figli
        g += 1; // aggiunge 1 a g per ogni figlio del nodo n
        aux = (NodoSCL *) aux->next;
    }
    return g;
}

Albero aggiungiNodo(Albero* a) {
    NodoAlbero* nuovo = malloc(sizeof(NodoAlbero));
    nuovo->figli = NULL;

    if (*a == NULL) {
        // Se l'a è vuoto, il nuovo nodo diventa l'a stesso
        *a = nuovo;
    } else {
        NodoSCL* nodoSCL = malloc(sizeof(NodoSCL));
        nodoSCL->figlio = nuovo;
        nodoSCL->next = (*a)->figli;
        (*a)->figli = (struct NodoSCL*)nodoSCL;
    }

    return nuovo;
}

int numNodi(Albero a){
    if (a == NULL) {
        return 0;
    }

    int n = 1; // contiamo la radice
    NodoSCL *aux = (NodoSCL *) a->figli;

    while(aux != NULL){
        n += numNodi(aux->figlio);
        aux = (NodoSCL *) aux->next;
    }

    return n;
}

Albero padre(Albero a, Albero n){
    if (a == NULL || n == NULL || n == a) {
        return NULL;
    }

    NodoSCL *aux = (NodoSCL *) a->figli;
    while(aux != NULL){
        if (aux->figlio == n)
            return a;
        Albero p = padre(aux->figlio, n);
        if (p != NULL) {
            return p;
        }
        aux = (NodoSCL *) aux->next;
    }
    return NULL;
}

NodoSCL* figli(Albero n){
    return (NodoSCL *) n->figli;
}

void aggiungiSottoalbero(Albero a, Albero n){
    if(a == NULL || n == NULL){
        return;
    }
    NodoSCL* nodoSCL = (NodoSCL*) malloc(sizeof(NodoSCL));
    nodoSCL->figlio = a;
    nodoSCL->next = n->figli;
    n->figli = (struct NodoSCL *) nodoSCL;
}
