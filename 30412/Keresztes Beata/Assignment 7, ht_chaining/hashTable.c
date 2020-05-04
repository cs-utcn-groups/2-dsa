//
// Created by q on 5/1/2020.
//

#include "hashTable.h"



void initHashTable(int N) {
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = (int)( N * INITIAL_HT_SIZE_FACTOR);
    hashTable = (listT *) malloc(sizeof(listT) * size);
    if (hashTable == NULL) {
        perror("Error allocating memory\n");
        exit(EXIT_FAILURE);
    } else {
            for (int i = 0; i < size; i++)
            {
                hashTable[i].size = 0;
                hashTable[i].head = hashTable[i].tail = NULL;
            }
    }
}

void insertElement(char * element)
{
    //! insert an element
    int key = hashFunction(element,hash3);
    addToList(&hashTable[key],element);
}

int hashFunction(char * content, hashF h)
{
   switch(h) {
       case hash0 : return h0(content);
       case hash1 : return h1(content);
       case hash2 : return h2(content);
       case hash3 : return h3(content);
       default: break;
   }
}
int h0(char * content) {
    // bad hash function
    return strlen(content) % size;
}
int h1(char * content) {
    //! keep in mind, size in this case simply means the number of buckets
    unsigned int length = strlen(content);
    unsigned long sum = 0;
    for (unsigned int i=0; i < length; i++)
    {
        sum += content[i];
    }
    return (int)sum % size;
}

int h2(char * content) {
    // Bernstein
    unsigned long hashValue = 5381;
    for(unsigned int i = 0; i < strlen(content); i++) {
        hashValue *= 33;
        hashValue += content[i];
    }
    return (int)(abs(hashValue) % size);
}
int h3(char * content) {
    // Jenkins one at a time
    unsigned long hashValue = 0;
    for(unsigned int i = 0; i < strlen(content); i++) {
        hashValue += content[i];
        hashValue += hashValue << 10;
        hashValue ^= hashValue >>6;
    }
    hashValue += hashValue << 3;
    hashValue ^= hashValue >> 11;
    hashValue += hashValue << 15;
    return (int)(abs(hashValue) % size);
}
void printHashTable() {
    for(int i=0;i<size;i++) {
        printf("B%d: ",i);
        printList(hashTable[i]);
    }
}
void computeDistributionsPerBucket(int N)
{
    // computes the distribution of elements for each bucket
    int MAX = 20;
    printf("MAX:");
    for(int i=0;i<MAX;i++) {
        printf("*");
    }
    printf("\n");
    for(int i = 0; i < size; i++) {
        printf("B%d: ",i);
        printf(" -> bucket size: %d - ",hashTable[i].size);
        int stars = (hashTable[i].size * MAX) / N;
        double distribution = (hashTable[i].size / (N * 1.0)) * 100;
        for(int k = 0; k < stars; k++) {
            printf("*");
        }
        printf(" (~%.2lf%%)\n", distribution);
    }
}

long int calculateAverage(int N) {
    long int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += hashTable[i].size;
    }
    return sum / N;
}

double calculateStandardDeviation(int N) {
    // compute the standard deviation
    long int dev = 0;
    long int mean = calculateAverage(N);
    for(int i = 0; i < size; i++) {
        int element = hashTable[i].size - mean;
        dev += element * element;
    }
    dev /= size;
    return sqrt(dev);
}