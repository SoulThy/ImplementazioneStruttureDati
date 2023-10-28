#include <stdio.h>
#include <stdlib.h>
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

int main() {
    Dizionario dizionario;
    dizionario.quantiElementi = 0;

    insert(&dizionario, 1, "Valore1");
    insert(&dizionario, 3, "Valore3");
    insert(&dizionario, 2, "Valore2");
    insert(&dizionario, 5, "Valore5");
    insert(&dizionario, 4, "Valore4");
    insert(&dizionario, 6, "Valore6");


    stampaDizionario(dizionario);
    return 0;
}

void stampaDizionario(Dizionario d){
    for (int i = 0; i < d.quantiElementi; i++) {
        printf("[%d,%s]\n", d.arrDizionario[i].chiave, d.arrDizionario[i].elemento);
    }
}

int search(Dizionario d, int c){
    int chiaveAlCentro = d.arrDizionario[d.quantiElementi/2].chiave;
    if(chiaveAlCentro == c)
        return 1;
    else if (c > chiaveAlCentro)
        return search();
}

void insert(Dizionario *d, int c, char *e){

    if (d->quantiElementi >= MAX_ELEMENTI)
        return;
    if(search(*d,c))
        return;

    Dizionario nuovoDizionario;
    nuovoDizionario.quantiElementi = d->quantiElementi + 1;
    int i;
    //Copia dei elementi prima di inserire il nuovoElemento
    for (i = 0; i < d->quantiElementi && d->arrDizionario[i].chiave < c; i++) {
        nuovoDizionario.arrDizionario[i] = d->arrDizionario[i];
    }
    //Inserimento nuovoElemento
    nuovoDizionario.arrDizionario[i].chiave = c;
    nuovoDizionario.arrDizionario[i].elemento = e;
    //Copia degli elementi dopo l'inserimento del nuovoElemento
    for (int j = i; j < d->quantiElementi; j++) {
        nuovoDizionario.arrDizionario[j + 1] = d->arrDizionario[j];
    }

    *d = nuovoDizionario;
}
