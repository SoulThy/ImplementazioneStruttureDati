#include <stdio.h>

#define MAX_SIZE 50

struct Grafo {
    int numNodi;
    int matrix[MAX_SIZE][MAX_SIZE];
};
typedef struct Grafo Grafo;

void inserisciNodo(Grafo* g);
void eliminaNodo(Grafo* g);
void stampaGrafo(Grafo g);
void inserisciArco(Grafo* g);
void inizializzaGrafo(Grafo* g);
int isFortementeConnesso(Grafo g);
void DFS(Grafo g, int nodo, int* visitato);
Grafo traspostaMatriceGrafo(Grafo g);

int main(){
    Grafo g;
    inizializzaGrafo(&g);
    
    int choice = 0;
    do{
        printf("\nInserisci l'opzione:\n");
        printf("1) Stampa grafo\n");
        printf("2) Inserisci un nodo\n");
        printf("3) Inserisci un arco (u->v)\n");
        printf("4) Controlla se il grafo e' fortemente connesso\n");
        printf("5) Elimina un nodo\n");
        printf("---------------------------\n");
        printf("0) Esci\n");
        
        scanf("%d",&choice);

        switch (choice) {
            case 0: return 0;
            case 1: stampaGrafo(g);break;
            case 2: inserisciNodo(&g);break;
            case 3: inserisciArco(&g);break;
            case 4: 
                if(isFortementeConnesso(g)){
                    printf("Il grafo e' fortemente connesso.\n");
                }
                else {
                    printf("Il grafo non e' fortemente connesso.\n");
                }
                break;
            case 5: eliminaNodo(&g);break;
            default: printf("Opzione non esistente!\n");break;
        }

    }while(choice != 0);


    return 0;
}

void inizializzaGrafo(Grafo* g){
    int i,j;

    g->numNodi = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            g->matrix[i][j] = 0;
        }
    }
    return;
}

void stampaGrafo(Grafo g){
    int i, j;
   
    printf("    ");
    for (i = 0; i < g.numNodi; i++) {
        printf("%3d ", i);
    }
    printf("\n");

    for(i = 0; i < g.numNodi; i++){
        printf("%3d ", i);
        for (j = 0; j < g.numNodi; j++) {
            printf("[%d] ", g.matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

void inserisciNodo(Grafo* g){
    int i,j;  

    i = g->numNodi++;
    for (j = 0 ; j < g->numNodi; j++) {
        g->matrix[i][j] = 0;
        g->matrix[j][i] = 0;
    }
    return;
}

void inserisciArco(Grafo* g){
    int u,v;
    printf("Seleziona nodo (u): ");
    scanf("%d",&u);
    printf("Seleziona nodo (v): ");
    scanf("%d",&v);

    g->matrix[u][v] = 1;
    return;
}

/*  l'idea e' la seguente, controllo:
    1)Se dal primo nodo posso raggiungere tutti
    2)Se tutti possono raggiungere il primo nodo
    Se queste condizioni sono verificate implica che 
    possiamo raggiungere ogni nodo, infatti da qualsiasi
    nodo ci riportiamo al primo e da li arriviamo ovunque */
int isFortementeConnesso(Grafo g){
    int i;
    int nodoPartenza = 0;
    int visitato[g.numNodi];

    for(i = 0; i < g.numNodi; i++){
        visitato[i] = 0;
    }

    DFS(g, nodoPartenza, visitato); /* punto (1) */

    for(i = 0; i < g.numNodi; i++){ /* controllo se un nodo non e' stato raggiunto a partire dal primo, questo implicherebbe subito che non e' F.C */
        if (visitato[i] == 0){
            return 0;
        }
    }

    for(i = 0; i < g.numNodi; i++){ /* resetto i visitati */
        visitato[i] = 0;
    }
    Grafo gTrasposto = traspostaMatriceGrafo(g); /* trasposta per il punto (2) */
    DFS(gTrasposto, nodoPartenza, visitato); /* punto (2) */

    for(i = 0; i < g.numNodi; i++){  /* controllo se un nodo non e' riuscito a raggiungere il primo, questo implicherebbe che non e' F.C */
        if (visitato[i] == 0){
            return 0;
        }
    }
    return 1;
}

void DFS(Grafo g, int nodo, int* visitato){
    int i;
    visitato[nodo] = 1;
    for (i = 0; i < g.numNodi; i++) {
        if (g.matrix[nodo][i] == 1 && visitato[i] == 0){
            DFS(g, i, visitato);
        }
    }
    return;
}

Grafo traspostaMatriceGrafo(Grafo g){
    int i,j;
    Grafo gTrasposto;
    gTrasposto.numNodi = g.numNodi;
    for (i = 0; i < gTrasposto.numNodi; i++) {
        for (j = 0; j < gTrasposto.numNodi; j++) {
            gTrasposto.matrix[j][i] = g.matrix[i][j];
        }
    }

    return gTrasposto;
}

void eliminaNodo(Grafo* g){
    int target, i, j;
    printf("Inserisci il nodo da eliminare: ");
    scanf("%d",&target);

    for (i = target; i < (g->numNodi - 1); i++) {
        for (j = 0; j < (g->numNodi -1); j++) {
            if (i == j){
                g->matrix[i][j] = g->matrix[i+1][j+1]; /* shift diagonale */
            }
            else{
                g->matrix[i][j] = g->matrix[i+1][j]; /* shift verso l'alto */
                g->matrix[j][i] = g->matrix[j][i+1]; /* shift verso sx */
            }
        }
    } 
    g->numNodi--;

    return;
}
