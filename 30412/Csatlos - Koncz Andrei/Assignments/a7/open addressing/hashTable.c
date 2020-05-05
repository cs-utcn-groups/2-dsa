//
// Created by csatl on 5/5/2020.
//

#include "hashTable.h"
#include "io.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = (INITIAL_HT_SIZE_FACTOR * N);
    hashTable = (char**)malloc(sizeof(char*) * size);
    for(int i=0;i<size;i++)
    {
        hashTable[i] = (char*)calloc(MAX_STRING_LENGTH + 1,sizeof(char));
    }
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    float counter = 0;
    for(int i=0; i < size; i++)
    {
        if (strlen(hashTable[i]) > 0)
        {
            counter++;
        }
    }
    fillFactor = counter / size;
    return fillFactor;
}

void resizeHashTable()
{
    numberOfResizes++;
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    int oldSize = size;
    char ** tempHashTable;
    tempHashTable = (char**)malloc(sizeof(char*) * oldSize);

    for(int i=0;i<oldSize;i++)
    {
        tempHashTable[i] = (char*)calloc(MAX_STRING_LENGTH + 1,sizeof(char));
        strcpy(tempHashTable[i],hashTable[i]);
        hashTable[i] = NULL;
        free(hashTable[i]);
    }
    free(hashTable);
    size *= 2;
    hashTable = (char**)malloc(sizeof(char*) * size);
    for(int i=0;i<size;i++)
    {
        hashTable[i] = (char*)calloc(size,sizeof(char));
    }
    for (int i = 0; i < oldSize; ++i)
    {
        if(strlen(tempHashTable[i])!=0)
        {
            if(strlen(tempHashTable[i]) > 0)
                insertElement(tempHashTable[i]);
        }

    }
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    if(getFillFactor() > MAX_FILL_FACTOR)
        resizeHashTable();
    int i=0;
    int index = hashFunction(element,i);
    while(strlen(hashTable[index])!=0)
    {
        i++;
        index = hashFunction(element,i);
    }
    strcpy(hashTable[index],element);
    return i;
}

int h1(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;

}
int h2(char * content, int i)
{
    return (strlen(content)+i) % size;
}
int h3(char * content, int i)
{
    int sum = 0;
    for(int i = 0; i < strlen(content); i+=5)
    {
        sum +=content[i];
        sum = sum%size;
    }
    sum = sum + i % size;
    sum = content[i] + sum;
    return sum % size;
}

int hashFunction(char * content, int i)
{
    return h1(content,i);
}
