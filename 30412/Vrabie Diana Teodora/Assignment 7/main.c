#include <stdio.h>
#include "io.h"
#include "hash-table.h"
#include "files.h"

int main() {
    int N = _100000;

    char **content = readFromFile(N);

    int size = N * INITIAL_HT_SIZE_FACTOR;
    HashTable *hashTable = initHashTable(size);

    maxNrOfCollisions = 0;
    nrOfResize = 0;

    for (int i = 0; i < N; ++i) {
        int collisions = insertElement(content[i], hashTable);
        printf("Element: %d- collisions:%d\n", i, collisions);
        hashTable = resizeHashTable(hashTable);
    }

    printf("Biggest size:%d\n",hashTable->size);
    printf("Max collisions: %d\n nr of resizes:%d\n",maxNrOfCollisions,nrOfResize);

    return 0;
}