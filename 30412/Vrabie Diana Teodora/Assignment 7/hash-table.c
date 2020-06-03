//
// Created by diana on 26/05/2020.
//

#include "hash-table.h"

int prime(int nr);

HashTable *initHashTable(int size) {
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    HashTable *hashTable = (HashTable *) malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->hashT = (char **) malloc(hashTable->size * sizeof(char *));
}

float getFillFactor(HashTable *hashTable) {
    //! return the fill factor of the hash table
    float fillFactor = (hashTable->nrOfElements * 1.0) / hashTable->size;
    return fillFactor;
}

HashTable *resizeHashTable(HashTable *oldHashTable) {
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR
    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    if (getFillFactor(oldHashTable) > MAX_FILL_FACTOR) {
        int newSize = 2 * oldHashTable->size;
        while (prime(newSize) == 0) {
            newSize++;
        }
        HashTable *newHashTable = initHashTable(newSize);
        for (int i = 0; i < oldHashTable->size; ++i) {
            insertElement(oldHashTable->hashT[i], NULL);
        }
        nrOfResize++;
        return newHashTable;
    }
    return oldHashTable;
}

int prime(int nr) {
    for (int i = 2; i < sqrt(nr); i++) {
        if (nr % i == 0)
            return 0;
    }
    return 1;
}

int insertElement(char *element, HashTable *hashTable) {
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int nrOfCollisions = 0;
    int index;

    index = hashFunction(element, nrOfCollisions, hashTable->size);
    nrOfCollisions++;

    while (hashTable->hashT[index] != NULL && nrOfCollisions < hashTable->size) {
        index = hashFunction(element, nrOfCollisions, hashTable->size);
        nrOfCollisions++;
    }

    if (hashTable->hashT[index] == NULL && nrOfCollisions < hashTable->size) {
        hashTable->hashT[index] = (char *) malloc(strlen(element) * sizeof(char));
        strcpy(hashTable->hashT[index], element);
        hashTable->nrOfElements++;
    }

    if (nrOfCollisions - 1 > maxNrOfCollisions) {
        maxNrOfCollisions = nrOfCollisions - 1;
    }

    return nrOfCollisions - 1;
}


int hashFunction(char *content, int i, int size) {
    // H1

    int length = strlen(content);
    int k, sum;
    for (sum = 0, k = 0; k < length; k++) {
        sum += content[k];
    }
    return (sum + i) % size;


    // H2
    /*
    int length = strlen(content);
    int k, sum;
    for (sum = 0, k = 0; k < length; k++) {
        sum += content[k];
    }
    return (sum + i * i) % size;
    */
    // H3
    /*
    int length = strlen(content);
    int k, sum;
    for (sum = 0, k = 0; k < length; k++) {
        sum += content[k] + rand();
    }
    return (sum + i) % size;
    */
}
