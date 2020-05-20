//
// Created by q on 5/1/2020.
//

#include "hashTable.h"

int getInitialSize(int N) {
    // compute the initial size of the table
    return (int)(N * INITIAL_HT_SIZE_FACTOR);
}

hashT * initHashTable(int size)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    hashT * h = (hashT *)malloc(sizeof(hashT));
    h->size = size;
    h->hashTable = (char  **)malloc(sizeof(char *)* h->size);
    if(h->hashTable == NULL) {
        perror("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    else {
        h->nrElements = 0; // initially the table is empty
        for(int i = 0; i < h->size; i++) {
            h->hashTable[i] = NULL;
        }
    }
    return h;
}

float getFillFactor(hashT * h)
{
    //! return the fill factor of the hash table
    return (float)((h->nrElements * 1.0) / h->size);
}

hashT * resizeHashTable(hashT * oldH)
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR
    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    if(getFillFactor(oldH) > MAX_FILL_FACTOR) {
        // need to increase the size of the table (find the closest prime to 2*size)
        hashT * newH = initHashTable(getNewSize(oldH->size));
        for(int i = 0; i < oldH->size; i++) {
            if(oldH->hashTable[i]) {
                // move elements form the old hash table to the new onr
                insertElement(oldH->hashTable[i], newH);
            }
        }
        nrResize ++;
        return newH;
    }
    return oldH;
}

int isPrime(int n) {
    // check if it's a prime number
    for(int i=2;i < sqrt(n);i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int getNewSize(int size) {
    // find the closest prime greater than twice the number given
    int new = 2 * size + 1; // prime nr's > 2 are odd
    while(isPrime(new) == 0) {
        new++;
    }
    return new;
}
int insertElement(char * element, hashT * h)
{    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int i = 0; // number of tries = number of collisions
    int key;
    fnp * hashFunction = chooseFunction(hash3);
    do {
        key = hashFunction(element,i,h->size);
        i++;
    }
    while(h->hashTable[key] != NULL && i < h->size);

    if(h->hashTable[key] == NULL && i<= h->size) {
        // found an empty slot
        h->hashTable[key] = (char *)malloc(sizeof(char) * strlen(element));
        strcpy(h->hashTable[key],element);
        h->nrElements++;
    }
    if(i-1 > maxCollisions) {
        maxCollisions = i-1;
    }
    return i-1;
}


fnp * chooseFunction(hashF h) {
    switch(h) {
        case hash1 : return h1;
        case hash2 : return h2;
        case hash3 : return h3;
        default: break;
    }
}
int h1(char * content, int i, int size)
{
    // by linear probing
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;

}
int h2(char * content, int i, int size)
{
    // by quadratic probing
    long int key = 0;
    const int prime = 31;
    for(unsigned int k = 0; k < strlen(content); k++) {
        key += content[k] * prime;
    }
    return (int) (key + i*i) % size;
}

int h3(char * content, int i, int size)
{
    long int key = 0;
    for(unsigned int k = 0; k < strlen(content); k++) {
        key += content[k] * pow(3,i);
        key ^= 31;
    }
    return (int)(abs(key) % size);
}

void printHashTable(hashT * h) {
    for(int i = 0; i < h->size; i++) {
        if(h->hashTable[i]) {
            printf("B%d: %s\n",i,h->hashTable[i]);
        }
        else {
            printf("B%d: empty slot\n",i);
        }
    }
}

