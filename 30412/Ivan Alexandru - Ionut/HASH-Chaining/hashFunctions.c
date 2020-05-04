#include "hashFunctions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    hashTable = (listT*)malloc(sizeof(listT)*(INITIAL_HT_SIZE_FACTOR*N));
    size = INITIAL_HT_SIZE_FACTOR*N;
    for(int i = 0; i < size; i++)
    {
        hashTable[i].size = 0;
        hashTable[i].head = hashTable[i].tail = NULL;
    }

}
int hashFunction1(char * content, int i);

void insertElement(char * element)
{
    int index = hashFunction1(element, 0);
    if(hashTable[index].size == 0)
    {
        nodeT* p = (nodeT*)malloc(sizeof(nodeT));
        p->content = (char*)malloc(sizeof(char)*1000);
        strcpy(p->content, element);
        p->next = NULL;
        hashTable[index].head = hashTable[index].tail = p;
        hashTable[index].size = 1;
    }else
    {
        nodeT* p = (nodeT*)malloc(sizeof(nodeT));
        p->content = (char*)malloc(sizeof(char)*1000);
        strcpy(p->content, element);
        p->next = NULL;
        hashTable[index].tail->next = p;
        hashTable[index].tail = p;
        hashTable[index].size++;
    }

}

int hashFunction3(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int sum = 0;
    for(int i = 0; i < strlen(content); i++)
        if(content[i] >= 70)
        {
            sum = sum + 28 + content[i]*content[i]*content[i];
        }else
        {
            sum = sum - content[i]*i;
        }

    return (sum + i*i) % size;
}

int hashFunction2(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int sum = 0, c = 69;
    for(int i = 0; i < strlen(content); i++)
        sum += (content[i]*content[i]) + c;

    return (sum + i) % size;
}

int hashFunction1(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int sum = 0;
    for(int i = 0; i < strlen(content); i++)
        sum += content[i];

    return (sum + i) % size;
}

int hashFunction0(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int sum = rand() % 5 + 1 ;
    return (sum + i) % size;
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
    float mean = 0;
    for(int i = 0; i < size; i++)
    {
        mean += hashTable[i].size;
    }
    mean = (float)(mean/size);
    float s = 1;
    for(int i = 0; i < size; i++)
    {
        if(hashTable[i].size > 0)
        {
            s = (float)s + (hashTable[i].size - mean)*(hashTable[i].size - mean);
            int p = (100*hashTable[i].size)/N;
            printf("B[%d] -> (~%d)\n", i, p);
        }else printf("B[%d] -> (~0)\n", i);
    }
    s = (float)s / (size);
    s = sqrt(s);
    printf("Standard Deviation : %f", s);
}
