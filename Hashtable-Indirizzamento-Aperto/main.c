#include <stdio.h>
#include "hashtable.h"

int main(){
    insert(1, 'A');
    insert(21, 'B');
    insert(41, 'C');
    insert(2, 'D');
    insert(3, 'E');
    insert(4, 'F');
    insert(5, 'G');
    printHashTable();   /* {[1,A] [21,B] [41,C] [2,D] [3,E] [4,F] [5,G]} */
    
    printf("\n[*]Eliminazione: delete(21)\n");
    delete(21);
    printHashTable();   /* {[1,A] [21,#] [41,C] [2,D] [3,E] [4,F] [5,G]} */
    printf("[*]Ricerca: search(21) -> %c\n",search(21)); /*Cerchiamo [21,#], ci aspettiamo che non trovi nulla in quanto e' cancellato*/
    printf("[*]Ricerca: search(41) -> %c\n",search(41)); /*Cerchiamo il [41,C], notare che si trova dopo il [21,#]*/
    
    printf("\n[*]Inserimento: insert(21,B)\n");
    insert(21, 'B'); /* Reinserisco [21,B], notiamo che riprendera' il posto di [21,#]*/
    printHashTable();

    return 0;
}