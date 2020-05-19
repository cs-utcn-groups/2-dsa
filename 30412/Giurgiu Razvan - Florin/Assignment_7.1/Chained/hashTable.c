#include "hashTable.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = 100;
    hashTable = (listT*)malloc(sizeof(listT) * size);
    for ( int i = 0 ; i < size ; i++)
    {
        hashTable[i].head = (nodeT*)malloc(sizeof(nodeT) * size);
        hashTable[i].head->content = NULL;
        hashTable[i].head->next = NULL;
        hashTable[i].head=NULL;
        hashTable[i].tail = hashTable[i].head;


    }
}

void insertElement(char * element)
{
    int index = hashFunction(element);
    nodeT *p = (nodeT*)malloc(sizeof(nodeT));
    p->content = element;
    if(hashTable[index].tail == NULL)
    {
        hashTable[index].tail = p;
        hashTable[index].tail -> next = NULL;
        hashTable[index].head = hashTable[index].tail;
    }
    else
    {
        hashTable[index].tail->next = p;
        hashTable[index].tail = p;
        hashTable[index].tail -> next = NULL;
    }

   // printf("%s ",hashTable[index].tail->content );

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
        return sum % size;
}

void printTable()
{
    int i = 0,ok=0;

    for( i = 0 ; i < size ; i++) {
        if (hashTable[i].head != NULL)
            while (hashTable[i].head != NULL) {
                printf("\n%d. %s ", i, hashTable[i].head->content);
                hashTable[i].head = hashTable[i].head->next;
            }
    }


}

void computeDistributionsPerBucket()
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
}
