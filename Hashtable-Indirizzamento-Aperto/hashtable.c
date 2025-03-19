#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

Entry* hashTable[DIM_MAX];

int hash(int k){
    return k % DIM_MAX; /* h(k) = k % m */
}

int linearHash(int k, int i){
    return (hash(k) + i) % DIM_MAX; /* c(k) = (h(k)+i) % m */
}

void insert(int k, char e){
    for (int i = 0; i < DIM_MAX; i++)
    {
        Entry* entry = hashTable[linearHash(k, i)];
        if(entry == NULL || entry->element == VALORE_CANCELLAZIONE){ /*Possiamo inserire se non esiste il puntatore oppure esiste ma e' stato cancellato*/
            Entry* newEntry = malloc(sizeof(Entry));
            newEntry->key = k;
            newEntry->element = e;
            hashTable[linearHash(k, i)] = newEntry;
            return;
        }
    }
    printf("[!] La HashTable risulta piena.");
}

int search(int k){
    for (int i = 0; i < DIM_MAX; i++)
    {
        Entry* entry = hashTable[linearHash(k, i)];
        if(entry == NULL)
            return 0;
        if(entry->key == k && entry->element != VALORE_CANCELLAZIONE)
            return entry->element;   
    }
    return 0;
}

void delete(int k){
    for (int i = 0; i < DIM_MAX; i++)
    {
        Entry* entry = hashTable[linearHash(k, i)];
        if(entry == NULL){
            printf("[!] Chiave non presente nell'HashTable");
            return;
        }
        if(entry->key == k && entry->element != VALORE_CANCELLAZIONE){
            entry->element = VALORE_CANCELLAZIONE;   
            return;
        }
    }
    printf("[!] Chiave non presente nell'HashTable");
}

void printHashTable() {
    printf("HashTable:\n");
    for (int i = 0; i < DIM_MAX; i++) {
        if (hashTable[i] != NULL && hashTable[i]->element != VALORE_CANCELLAZIONE) { // Verifica se l'entry è stata inizializzata
            printf("Index %d: Key = %d, Element = %c\n", i, hashTable[i]->key, hashTable[i]->element);
        }
    }
}
