// Rappresentazione mediante lista dei figli

typedef char TipoInfo;

struct NodoSCL;

typedef struct{
    TipoInfo info;
    struct NodoSCL* figli;
} NodoAlbero;

typedef struct{
    NodoAlbero* figlio;
    struct NodoSCL* next;
} NodoSCL;

typedef NodoAlbero* Albero;

int grado(NodoAlbero* n);

int numNodi(Albero a);

NodoAlbero* padre(Albero a, NodoAlbero* n;

NodoSCL* figli(NodoAlbero* n);

NodoAlbero* aggiungiNodo(NodoAlbero* n);

void aggiungiSottoalbero(Albero a, NodoAlbero* n);

Albero rimuoviSottoalbero(Albero* a, NodoAlbero* n);

void stampa(Albero a);

int main();