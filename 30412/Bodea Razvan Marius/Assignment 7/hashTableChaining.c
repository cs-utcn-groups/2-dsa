/*

#include "hashTableChaining.h"
#include "hashTableOpenAddressing.h"

void insertElement(char * element)
{//! insert an element
    int index=H3(element);
    addToList(&hashTable[index],element);
}

void initHashTable(int N)
{//! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = (int)( N * INITIAL_HT_SIZE_FACTOR);
    hashTable = (listT *) malloc(sizeof(listT) * size);
    for (int i = 0; i < size; i++){
        hashTable[i].size = 0;
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }
}

int H0(char *content){
    //bad
    return content[0]%size;
}

int H1(char * content)
{ //example
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum) % size;
}

int H2(char *content){
    unsigned h = 0;
    unsigned int i;

    for (i = 0; i < strlen(content); i++)
    {
        h ^= content[i];
    }

    return h%size;
}

int H3(char *content){
    //FNV hash function
  const int FNV_PRIME_32=16777619;
  unsigned int hash=2166136261U;
    for(unsigned int i=0; i<strlen(content); i++)
    {
        hash *= FNV_PRIME_32;
        hash ^= content[i];
    }
    return hash%size;
}

void computeDistributionsPerBucket(int N)
{//! computes the distribution of elements for each bucket
    for(int i=0;i<size;i++){
        float fraction = (float)hashTable[i].size/N;
        float percentage = fraction*100;
        printf("B%d: ", i);
        printf("(~%.2f%%) \n", percentage);
    }
    printf("\n\n");
    }

double calculateStandardDeviation(int N) {
    // compute the standard deviation
    long int dev = 0;
    long int avg = calculateAverage(N);
    for(int i = 0; i < size; i++) {
        int element = hashTable[i].size - avg;
        dev += element * element;
    }
    dev /= size;
    return sqrt(dev);
}

long int calculateAverage(int N) {
    long int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += hashTable[i].size;
    }
    return sum / N;
}

*/