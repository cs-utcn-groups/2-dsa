#include <stdlib.h>
#include <math.h>
#include "hashTable.h"
#include "io.h"

static int (*hashFunctionArray[])(char *, int) ={hashFunction1, hashFunction2, hashFunction3};

void initHashTable(int N) {
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    double aux = INITIAL_HT_SIZE_FACTOR * N;
    size = aux;
    initialSize = size;
    hashTable = (char **) malloc(size * sizeof(char *));
    for (int i = 0; i < size; ++i) {
        hashTable[i] = (char *) calloc((MAX_STRING_LENGTH + 1), sizeof(char));
    }
}

double getFillFactor() {
    //! return the fill factor of the hash table
    double fillFactor = -1;
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (hashTable[i][0] != FREE) {
            ///is occupied
            counter++;
        }
    }
    fillFactor = (double) counter / size;
    return fillFactor;
}

void resizeHashTable(int t) {
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    char **auxHashTable = (char **) malloc(2 * size * sizeof(char *));
    for (int i = 0; i < 2 * size; ++i) {
        auxHashTable[i] = (char *) calloc((MAX_STRING_LENGTH + 1), sizeof(char));
    }

    ///rehash the table
    for (int i = 0; i < size; ++i) {
        char *element = hashTable[i];
        if (element[0] != FREE) {
            ///bucket isn't empty
            int j = 0;
            while (auxHashTable[hashFunctionArray[t](element, j)][0] != FREE) {
                ///collision detected
                j++;
            }
            strcpy(auxHashTable[hashFunctionArray[t](element, j)], element);
        }

    }
    size *= 2;
    hashTable = auxHashTable;
}

int insertElement(char *element, int t) {
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int noOfCollisions;
    if (getFillFactor() > MAX_FILL_FACTOR) {
        resizeHashTable(t);
    }
    int i = 0;
    int initialIndex=hashFunctionArray[t](element, i);
    i++;
    while (hashTable[hashFunctionArray[t](element, i)][0] != FREE) {
        ///collision detected
        i++;
    }
    strcpy(hashTable[hashFunctionArray[t](element, i)], element);
    noOfCollisions = i;
    return noOfCollisions;
}


int hashFunction1(char *content, int i) {
    int length = strlen(content);
    int k, result;
    for (result = 0, k = 0; k < length; k++) {
        result += content[k];
        result%=size;
    }
    return (result + i) % size;
}

int hashFunction2(char *content, int i) {
    int result,k;
    int length = strlen(content);
    for (result = 0, k = 0; k < length; k++) {
        result += content[k]+rand();
        result%=size;
    }
    return abs((result + i) % size);
}

int hashFunction3(char *content, int i) {
    int length = strlen(content);
    int k, result;
    for (result = 0, k = 0; k < length; k++) {
        result += content[k]+rand()*rand()%size;
    }
    return abs((result + i) % size);
}
