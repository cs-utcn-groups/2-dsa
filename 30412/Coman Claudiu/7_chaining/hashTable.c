#include "hashTable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    size = (INITIAL_HT_SIZE_FACTOR * N);
    hashTable = (listT*)malloc(sizeof(listT) * size);
    for(int i=0;i<size;i++)
    {
        hashTable[i].size = 0;
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }

    //! also the size variable has to be initialized
}

void insertElement(char * element)
{
    //! insert an element
    int x = hashFunction(element);
    hashTable[x].size++;
    addToList(hashTable[x],element);
}

int h0(char * content)
{
    return (rand() % 8 + rand() % 22) % size;
}
int h1(char * content)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];

    }
    return sum % size;
}
int h2(char * content)
{
    return (rand() % strlen(content)) % size;
}
int h3(char * content)
{
    int sum = 0;
    for(int i = 0; i < strlen(content); i+=5)
    {
        sum +=content[i];
        sum = sum%size;
    }
    sum = ( rand() * content[rand() % strlen(content)] ) % size;
    return sum;
}

int hashFunction(char * content)
{
    //! keep in mind, size in this case simply means the number of buckets
    return h3(content);
}
void computeDistributionsPerBucket(int N)
{
    int sum=0;
    int medie = N/size;
    int distribution = 0;
    for(int i=0; i<size; i++)
    {
        printf("hashtable size = %d   -", hashTable[i].size);
        printf("B%d: ",i);
        for(int j=0;j<hashTable[i].size;j++)
        {
            printf("*");
        }
        distribution = (hashTable[i].size*100)/N;
        sum = sum + (hashTable[i].size - medie) * (hashTable[i].size - medie);
        printf(" (%d)\n",distribution);
    }
    float standardDeviation = sum/N;
    standardDeviation = sqrt(standardDeviation);
    printf("Standard deviation = %.2f",standardDeviation);
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

}
