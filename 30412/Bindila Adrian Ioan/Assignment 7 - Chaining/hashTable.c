#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "hashTable.h"

void initHashTable(int N) {
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    double aux;
    aux = INITIAL_HT_SIZE_FACTOR * N;
    size = aux;
    hashTable = (listT *) malloc(size * sizeof(listT));
    for (int i = 0; i < size; ++i) {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
        hashTable[i].size = 0;
    }
}

void insertElement(char *element, int function) {
    //! insert an element
    switch (function) {
        case 0: {
            addToList(&hashTable[hashFunction0(element)], element);
        }
        case 1: {
            addToList(&hashTable[hashFunction1(element)], element);
        }
        case 2: {
            addToList(&hashTable[hashFunction2(element)], element);
        }
        case 3: {
            addToList(&hashTable[hashFunction3(element)], element);
        }
    }

}

int hashFunction0(const char *content) {
    return content[0] % size;
}

int hashFunction1(const char *content) {
    int length = strlen(content);
    int k, sum;
    for (sum = 0, k = 0; k < length; k++) {
        sum += content[k];
    }
    return sum % size;
}

int hashFunction2(const char *content) {
    int length = strlen(content);
    int k;
    int product = 1;
    for (k = 0; k < length; k++) {
        product = (content[k] * product) % size;
    }
    return product;
}

int hashFunction3(const char *content) {
    int length = strlen(content);
    int k;
    int result = 0;
    for (k = 0; k < length; k++) {
        if (result > size) {
            result =content[k];
        } else {
            result += content[k];
        }
    }
    return result%size;
}

void computeDistributionsPerBucket(int N) {
    ///function is not used because of a huge number of buckets for higher files
    ///other than that, it works
    for (int i = 0; i < size; ++i) {
        printf("Bucket%d: ", i);
        double distribution = ((double) hashTable[i].size / N) * 100;
        printf("%.2lf%%\n", distribution);
    }
}

void getStandardDeviation(FILE *out) {
    double avg = 0;

    for (int i = 0; i < size; ++i) {
        avg += hashTable[i].size;
    }
    avg /= size;
    double sum = 0;
    for (int j = 0; j < size; ++j) {
        sum += ((hashTable[j].size - avg) * (hashTable[j].size - avg));
    }
    double result = sqrt(sum / size);
    fprintf(out, "Standard deviation: %lf\n\n", result);
}