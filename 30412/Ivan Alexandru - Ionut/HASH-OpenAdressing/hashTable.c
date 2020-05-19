#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    hashTable = (char**)malloc(sizeof(char*)*INITIAL_HT_SIZE_FACTOR*N);
    size = INITIAL_HT_SIZE_FACTOR*N;
    for(int i = 0; i < size; i++)
        hashTable[i] = NULL;
}

float getFillFactor(int N)
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int nr = 0;
    for(int i = 0; i < size; i++)
    {
        if(hashTable[i] != NULL)
            nr++;
    }
    if(nr > 0)
        fillFactor = (float)nr/(size);
    return fillFactor;
}

void resizeHashTable(int N, int i, char** content)
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    n++;
    free(hashTable);
    size = size*2;
    hashTable = (char**)malloc(sizeof(char*)*size);
    for(int j = 0; j < i; j++)
        insertElement(content[i], N);
}

int insertElement(char * element, int N)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int i = 0;
    int index = hashFunction3(element, i);
    while(hashTable[index] != NULL)
    {
        i++;
        index = hashFunction3(element, i);
    }
    if(i > m){
        m = i;
    }
    hashTable[index] = (char*)malloc(sizeof(char)*1000);
    strcpy(hashTable[index], element);
    return i;
}


int hashFunction1(char * content, int i)
{
    int sum = 0;
    for(int i = 0; i < strlen(content); i++)
        sum += content[i];

    //printf("%d\n", (sum + i) % size);
    return (sum + i) % size;
}

int hashFunction3(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int sum = 0;
    for(int i = 0; i < strlen(content); i++)
        if(content[i] >= 70)
        {
            sum = sum + 28 + content[i]*content[i];
        }else
        {
            sum = sum - content[i]*i;
        }

    return (sum + i) % size;
}

int hashFunction2(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int sum = 0, c = 69;
    for(int i = 0; i < strlen(content); i++)
        sum += (content[i]*content[i]) + c;

    return (sum + i) % size;
}

