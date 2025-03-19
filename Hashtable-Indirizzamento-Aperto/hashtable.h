#define DIM_MAX 10
#define VALORE_CANCELLAZIONE '#'

typedef struct {
    int key;
    char element;
} Entry;

void insert(int k, char e);
int search(int k);
void delete(int k);
void printHashTable();
