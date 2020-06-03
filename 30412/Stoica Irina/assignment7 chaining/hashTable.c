#include <stdio.h>
#include "hashTable.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    sizeTable = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT**)malloc(sizeTable * sizeof(listT*));
    for(int i=0; i<sizeTable; i++){
        hashTable[i] = (listT*)malloc(sizeof(listT));
        hashTable[i]->head = NULL;
        hashTable[i]->tail = NULL;
        hashTable[i]->sizeList = 0;
    }
}

void insertElement(char * element)
{
    //! insert an element
    int position = H3(element);
    addToList(hashTable[position], element);
}

int hashFunction(char * content)
{
    //! keep in mind, size in this case simply means the number of buckets
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % sizeTable;
}

int H0(){
    return rand() % 2 + 5;
}

int H2(char * content){
    int hash = 5381;
    int i = 0;
    int length = strlen(content);
    for (i = 0; i < length; i++) {
        hash = ((hash << 5) + hash) + content[i];
    }
    return abs(hash) % sizeTable;
}

int H3(char * content){
    int result = content[0];
    for(int i=1; i<strlen(content);i++) {
        result = abs(result * 31 + content[i]);
    }
    return result % sizeTable;
}

void computeDistributionsPerBucket(int N)
{
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
    for(int i=0; i<sizeTable; i++){
        float nrOfBuckets = (float)hashTable[i]->sizeList;
        float percentage = (nrOfBuckets/(float)N) * 100;
        //printf("B%d: ********** (~%.2f)\n",  i, percentage);
    }
}
double computeStandardDeviation(){
    double average = 0.00;
    double sumOfDev = 0.00;
    double stdDev;
    for(int i=0; i<sizeTable; i++){
        average = average + (double)hashTable[i]->sizeList;
    }
    average = average / (double)sizeTable;
    double * deviations = (double*)malloc(sizeTable * sizeof(double));
    for(int i=0; i<sizeTable; i++){
        deviations[i] = hashTable[i]->sizeList - average;
        sumOfDev = sumOfDev + (deviations[i] * deviations[i]);
    }
    stdDev = sqrt(sumOfDev/(double)sizeTable);
    return stdDev;
}
