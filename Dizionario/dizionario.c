#include <stdio.h>
#define MAX_ELEMENTI 20

struct elementoDizionario {
    int chiave;
    char *elemento;
};
typedef struct elementoDizionario ElementoDizionario;

struct dizionario {
    ElementoDizionario arrDizionario[MAX_ELEMENTI];
    int quantiElementi;
};
typedef struct dizionario Dizionario;

void stampaDizionario(Dizionario);
int search(Dizionario, int);
void insert(Dizionario *, int, char *);
void delete(Dizionario *, int);

int main() {
    Dizionario dizionario;
    dizionario.quantiElementi = 0;
    int keyToDelete = 4;

    insert(&dizionario, 1, "Valore1");
    insert(&dizionario, 3, "Valore3");
    insert(&dizionario, 2, "Valore2");
    insert(&dizionario, 5, "Valore5");
    insert(&dizionario, 4, "Valore4");
    insert(&dizionario, 6, "Valore6");

    stampaDizionario(dizionario);

    delete(&dizionario, keyToDelete);
    printf("Eliminazione valore %d:\n", keyToDelete);
    stampaDizionario(dizionario);

    return 0;
}

void stampaDizionario(Dizionario d){
    for (int i = 0; i < d.quantiElementi; i++) {
        printf("[%d,%s]\n", d.arrDizionario[i].chiave, d.arrDizionario[i].elemento);
    }
}

int search(Dizionario d, int c){
    int sinistra = 0;
    int centro = 0;
    int destra = d.quantiElementi-1;

    while(sinistra <= destra){
        centro = (sinistra + destra)/2;

        int chiaveAlCentro = d.arrDizionario[centro].chiave;

        if(chiaveAlCentro == c){
            return 1;
        } else if (c > chiaveAlCentro){
            sinistra = centro + 1;
        } else {
            destra = centro - 1;
        }
    }

    return 0;
}

void insert(Dizionario *d, int c, char *e){

    if (d->quantiElementi >= MAX_ELEMENTI || search(*d, c)) {
        return; // Non inserire se il dizionario è pieno o l'elemento è già presente
    }

    Dizionario nuovoDizionario;
    int i = 0;

    // Copia gli elementi da d al nuovoDizionario prima di inserire il nuovo elemento
    while (i < d->quantiElementi && d->arrDizionario[i].chiave < c) {
        nuovoDizionario.arrDizionario[i] = d->arrDizionario[i];
        i++;
    }

    // Inserisci il nuovo elemento
    nuovoDizionario.arrDizionario[i].chiave = c;
    nuovoDizionario.arrDizionario[i].elemento = e;

    // Copia gli elementi rimanenti da d al nuovoDizionario
    for (int j = i; j < d->quantiElementi; j++) {
        nuovoDizionario.arrDizionario[j + 1] = d->arrDizionario[j];
    }

    nuovoDizionario.quantiElementi = d->quantiElementi + 1;
    *d = nuovoDizionario;
}

void delete(Dizionario *d, int c){
    if (d->quantiElementi == 0 || search(*d, c) == 0) {
        return; // Non eliminare se il dizionario è vuoto o l'elemento non e' presente
    }

    Dizionario nuovoDizionario;
    // Copia gli elementi da d al nuovoDizionario senza l'elemento da eliminare
    for (int i = 0, j = 0; i < d->quantiElementi; i++) {
        if (d->arrDizionario[i].chiave != c) {
            nuovoDizionario.arrDizionario[j] = d->arrDizionario[i];
            j++;
        }
    }

    nuovoDizionario.quantiElementi = d->quantiElementi - 1;
    *d = nuovoDizionario;
}