//
// Created by Bori on 4/29/2020.
//

#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>


void initHashTable(int N, int functionNr)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = N*INITIAL_HT_SIZE_FACTOR;
    hashTable = (char**) malloc(sizeof(char*)*size);
    for(int i=0; i<size; i++){
        hashTable[i]=NULL;
    }
    hashFunctionNr = functionNr;
    noInsertedElements = 0;
    noResizes=0;
}

void initHashTableWithGivenSize(int newSize){
    size = newSize;
    hashTable = (char**) malloc(sizeof(char*)*size);
    for(int i=0; i<size; i++){
        hashTable[i]=NULL;
    }
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    return (float) noInsertedElements/(float)size;
}


void resizeHashTable()
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR
    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
    noResizes++;
    char** oldHashTable = hashTable;
    int oldSize = size;
    initHashTableWithGivenSize(size*2);
    for(int i=0; i<oldSize; i++){
        if(oldHashTable[i]!=NULL){
            noInsertedElements--;
            insertElement(oldHashTable[i]);
            free(oldHashTable[i]);
        }
    }
    free(oldHashTable);
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int index;
    int hashCode = getHashCode(element);
    for (int i = 1;; i++) {
        index = hashFunction(hashCode, i);
        assert(index >= 0 && index < size);
        if(hashTable[index]==NULL){
            hashTable[index] = (char*) malloc(sizeof(char)*(strlen(element)+1));
            strcpy(hashTable[index], element);
            noInsertedElements++;
            if(getFillFactor()>MAX_FILL_FACTOR){
                resizeHashTable();
            }
            return i-1; //no of collisions
        }
        if (i > size * 3 / 4) {
            //I cheated here a little, but I observed that this modification increases the performance a lot,
            // without breaking any of the laws concerning hashing
            resizeHashTable();
            insertElement(element);
        }
    }
}

int hashFunction(int hashCode, int i) {
    int prime = 79;
    int result = abs((hashCode + i * i) % size);
    return result;
}

int getHashCode(char *content) {
    switch (hashFunctionNr) {
        case 0:
            return hashCode0(content);
            break;
        case 1:
            return hashCode1(content);
            break;
        case 2:
            return hashCode2(content);
            break;
        case 3:
            return hashCode3(content);
            break;
        case 4:
            return hashCode4(content);
            break;
    }
}


int hashCode0(char * content){ //really bad
    int result = 0;
    result = content[0]%2;
    return result%size;
}

int hashCode1(char * content){
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;
}

int hashCode2(char* content)
{
    //! keep in mind, size in this case simply means the number of buckets
    int hash = 0;
    for(int i=0; i<strlen(content); i++){
        hash = hash*31 + content[i];
    }
    if(hash<0) hash=-hash;
    return hash%size;
}

int hashCode3(char * content){
    int fnvPrime = 16777619u;
    int fnv_offset_basis = 2166136261u;
    int hash = fnv_offset_basis;
    for(int i=0; i<strlen(content); i++)
    {
        hash *= fnvPrime;
        hash ^= content[i];
    }
    return hash%size;
}

int hashCode4(char *content) {
    int fnvPrime = 16777619u;
    int fnv_offset_basis = 2166136261u;
    int hash = fnv_offset_basis;
    for (int i = 0; i < strlen(content); i++) {
        hash ^= content[i];
        hash *= fnvPrime;
    }
    return hash % size;
}


void setInitialSizeFactor(float sizeFactor){
    INITIAL_HT_SIZE_FACTOR = sizeFactor;
}

void setMaxFillFactor(float maxFillFactor){
    MAX_FILL_FACTOR = maxFillFactor;
}

void freeHashTable() {
    for (int i = 0; i < size; i++) {
        free(hashTable[i]);
    }
    free(hashTable);
}