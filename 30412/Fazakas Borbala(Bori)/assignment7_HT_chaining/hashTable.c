//
// Created by Bori on 4/29/2020.
//

#include "hashTable.h"
#include <stdlib.h>
#include <string.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = N*INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT*) malloc(sizeof(listT)*size);
    for(int i=0; i<size; i++){
        hashTable[i]=createList();
    }
}

void insertElement(char * element)
{
    //! insert an element
    addToList(&hashTable[hashFunction(element, 1)], element);
}

int hashFunction(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    unsigned int hash = 0;
    for(int i=0; i<strlen(content); i++){
        hash = hash*7 + content[i];
    }
    return hash%size;
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
