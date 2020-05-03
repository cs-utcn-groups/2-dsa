#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initHashTable(int N) {
    size = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT *) malloc(size * sizeof(listT));
    for (int i = 0; i < size; i++) {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
}

void insertElement(char *element) {
    int z = hashFunction(element);
    hashTable[z]=addToList(hashTable[z], element);
}

int hashFunction(char *content) {
    return content[0]%2;
}

void computeDistributionsPerBucket(int N) {
    for(int i=0;i<size;i++)
    {
        float x=(hashTable[i].size/N)*100;
        printf("B%d: %f%c\n",i,x,'%');
    }
}
