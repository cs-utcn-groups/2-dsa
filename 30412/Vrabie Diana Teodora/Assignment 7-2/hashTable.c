//
// Created by diana on 26/05/2020.
//

#include "hashTable.h"


void initHashTable(int N) {
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (listT*)malloc(sizeof(listT)*size);
    for (int i = 0; i < size; i++){
        hashTable[i].size = 0;
    }
    for (int i = 0; i < size; i++) {
        hashTable[i].size = 0;
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }
}

void insertElement(char *element, int i) {
    //! insert an element
    int aux = hashFunction(element, i);
    addToList(hashTable[aux], element);
}

int hashFunction(char *content, int i) {
    //! keep in mind, size in this case simply means the number of buckets
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;
}

void computeDistributionsPerBucket(int N) {
    //! computes the distribution of elements for each bucket
    //! the output should look something like:
    /**
        MAX = 'x' * 20
        B0: ********** (~50%)
        B1: ************ (~60%)
        B2: ****** (~30%)
        B3: ******* (~35%)
        .....
        hint : the bigger you choose X, the better approximation
        hint2: choose it somewhere between 20-40 such that it fits in one row in the console nicely
    */
    int X = 30;
    for (int i = 0; i < size; i++) {
        float fraction = (float)hashTable[i].size/N;
        float percentage = fraction*100;
        printf("B%d: ", i);
        printf("(~%.2f%%) \n", percentage);
    }
    printf("\n\n");
}
