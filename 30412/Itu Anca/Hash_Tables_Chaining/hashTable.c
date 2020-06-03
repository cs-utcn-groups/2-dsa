//
// Created by Anca on 5/2/2020.
//

#include "hashTable.h"
#include "io.h"
#include "list.h"
#include <unistd.h>

void initHashTable(int N)
{
    size = (int)(N* INITIAL_HT_SIZE_FACTOR);
    hashTable = (listT*) malloc (size * sizeof(listT));

    for(int i = 0; i < size-1; i++){
        hashTable[i].head = createNode("");
        hashTable[i].tail = createNode("");
        hashTable[i].size = 0;
    }
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
}

void insertElement(char * element)
{
    int index = hashFunction4(element);
    addToList(&hashTable[index], element);
    hashTable[index].size++;
    //! insert an element
}

int hashFunction0(char * content){
    return (content[0]*2)%5+5;
}

int hashFunction1(char * content)
{
    unsigned int length = strlen(content);
    int sum;
    unsigned int k;

    for (sum = 0, k = 0; k < length; k++){
        sum += content[k];
    }
    return sum % size;
}

int hashFunction2(char * content){
    int sum;
    unsigned int k;
    for(sum = 0, k = 0; k < strlen(content); k++){
        content[k] = content[0];
        sum += content[k];
    }
    return sum % size;
}

int hashFunction3(char * content){
    int hash = 0;
    for(unsigned int i = 0; i < strlen(content); i++){
        hash = ((hash * 8) + content[i]) % size;
    }
    return hash;
}

int hashFunction4(char * content) {
    long sum = 0, mul = 1;
    unsigned int length = strlen(content), i;

    for (i = 0; i < length; i++) {
        if(i%4==0){
            mul = 1;
        }
        else{
            mul = mul*256;
        }
        sum += content[i] * mul;
    }
    return (int)(abs(sum) % size);
}

void computeDistributionsPerBucket(int N)
{
    int nr;
    for(int i=0; i<size; i++){
        nr = hashTable[i].size;
        printf("B%d : ", i);
        for(int k = 0; k < nr; k++){
            printf("*");
        }
        printf(" ( %d%%)\n", (int)((100*nr) / N));
    }
    printf("\n");
/*
    ! computes the distribution of elements for each bucket
    ! the output should look something like:

        MAX = 'x' * 20
        B0: ********** (~50%)
        B1: ************ (~60%)
        B2: ****** (~30%)
        B3: ******* (~35%)
        .....
        hint : the bigger you choose X, the better approximation
        hint2: choose it somewhere between 20-40 such that it fits in one row in the console nicely
*/
}

double standardDeviation(int N){
    double sum = 0.0, mean, sd = 0.0;
    int i;

    for(i=0; i<size; i++){
        sum += hashTable[i].size;
    }
    mean =(float)(sum/size);

    for(i = 0; i < size; i++){
        sd = sd + pow(hashTable[i].size - mean, 2);
    }
    sd = sqrt(sd/size);

    return sd;
}