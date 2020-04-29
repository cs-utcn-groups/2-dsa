//
// Created by Bori on 4/29/2020.
//

#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>


void initHashTable(int N, int functionNr)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = N*INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT*) malloc(sizeof(listT)*size);
    for(int i=0; i<size; i++){
        hashTable[i]=createList();
    }
    hashFunctionNr = functionNr;
}

void setInitialSizeFactor(float factor){
    INITIAL_HT_SIZE_FACTOR = factor;
}

void insertElement(char * element)
{
    int index;
    switch(hashFunctionNr) {
        case 0: index = hashFunction0(element);
        break;
        case 1: index = hashFunction1(element);
        break;
        case 2: index = hashFunction2(element);
            break;
        case 3: index = hashFunction3(element);
            break;
        case 4: index = hashFunction4(element);
            break;
    }
    addToList(&hashTable[index], element);
}

int hashFunction0(char * content){ //really bad
    return content[0]%2%size;
}

int hashFunction1(char * content){
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;
}

int hashFunction2(char* content)
{
    //! keep in mind, size in this case simply means the number of buckets
    int hash = 0;
    for(int i=0; i<strlen(content); i++){
        hash = hash*31 + content[i];
    }
    if(hash<0) hash=-hash;
    return hash%size;
}

int hashFunction3(char * content){
    int fnvPrime = 16777619u;
    int fnv_offset_basis = 2166136261u;
    unsigned int hash = fnv_offset_basis;
    for(int i=0; i<strlen(content); i++)
    {
        hash *= fnvPrime;
        hash ^= content[i];
    }
    return hash%size;
}

int hashFunction4(char * content){
    int fnvPrime = 16777619u;
    int fnv_offset_basis = 2166136261u;
    unsigned int hash = fnv_offset_basis;
    for(int i=0; i<strlen(content); i++)
    {
        hash *= fnvPrime;
        hash ^= content[i];
        hash ^= content[i]*((int)pow(2, 8));
        hash ^= content[i]*((int)pow(2, 16));
        hash ^= content[i]*((int)pow(2, 24));

    }
    return hash%size;
}


void computeDistributionsPerBucket(int n)
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
    for(int i=0; i<size; i++){
        printf("size of list %d is %.10lf\%\n", i, ((double)hashTable[i].size/n));
    }
}

double standartDeviationOfBucketLengths(){
    double expectedValue = 0;
    for(int i=0; i<size; i++){
        expectedValue+=hashTable[i].size;
    }
    expectedValue/=size;

    double sd_square = 0;
    for(int i=0; i<size; i++){
        sd_square+=pow(hashTable[i].size-expectedValue, 2);
    }
    sd_square/=size;
    return sqrt(sd_square);
}
