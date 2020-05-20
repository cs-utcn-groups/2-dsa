//
// Created by Diana on 10/05/2020.
//

#include "hashTable.h"


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    sizeHashTable = (int)(INITIAL_HT_SIZE_FACTOR * (float)N);
    hashTable = (char**) malloc (sizeHashTable * sizeof(char*));
    for (int i=0; i< sizeHashTable; i++) {
        hashTable[i] = NULL;
    }
    noOfResizes = 0;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor;
    int noOfElements = 0;
    for (int i=0; i<sizeHashTable; i++) {
        if (hashTable[i] != NULL) {
            noOfElements++;
        }
    }
    fillFactor = (float)noOfElements/(float)sizeHashTable;

    return fillFactor;
}

void resizeHashTable()
{
    noOfResizes++;
    char ** rehash = hashTable;
    int previousSize = sizeHashTable;
    sizeHashTable = sizeHashTable *2;

    hashTable = (char**) malloc (sizeHashTable * sizeof(char*));
    for(int i=0; i<sizeHashTable; i++) {
        hashTable[i] = NULL;
    }
    for(int i=0; i<previousSize; i++) {
        if(rehash[i] != NULL) {
            insertElement(*(rehash + i));
        }
    }
}

int insertElement(char * element)
{
    int i = 0, elementInserted = 0, key = 0;
    while(!elementInserted) {
        if(state == 0)key = hashFunction1(element, i);
        else if(state == 1)key = hashFunction2(element, i);
        else if(state == 2)key = hashFunction3(element, i);
        if (hashTable[key] != NULL) {
            i++;
        } else {
            hashTable[key] = (char *) malloc (MAX_STRING_LENGTH * sizeof(char));
            hashTable[key] = element;
            float fillFactor = getFillFactor();
            if(fillFactor > MAX_FILL_FACTOR) {
                resizeHashTable();
            }
            elementInserted = 1;
        }
    }
    return i;
}


int hashFunction1(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % sizeHashTable;

}

int hashFunction2(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    sum  = sum * (i * i) + sum * 7 * i +content[0];
    return (sum + i) % sizeHashTable;
}

int hashFunction3(char * content, int i)
{
    int length = strlen(content);
    int k, sum, sum2;
    for (sum=0, k=0, sum2=0; k < length; k++)
    {
        int aux = content[k];
        while(aux) {
            sum2 += aux%10;
            aux = aux/10;
        }
        sum += content[k];
    }
    sum  = (sum * i * i)  + sum * 7 * i  + sum2 * 9 + content[0];
    return (sum + i*i) % sizeHashTable;
}
