#include "hashTable.h"


void initHashTable(int N)
{//! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized

}

void insertElement(char * element)
{//! insert an element
int index=H1(element);
addToList(&hashTable[index],element);

}

int hashFunction(char * content, int i)
{//! keep in mind, size in this case simply means the number of buckets
    return i % size;
}

int H1(char *content){
    //bad
    return 3;
}

int H2(char *content){
    int S=0;
    int length=strlen(content);
    for(int i=0;i<length;i++){
        S+=content[i];
    }
    return S%size;
}

int H3(char *content){
    //FNV hash function
  const int FNV_PRIME_32=16777619;
  unsigned int hash=2166136261U;
    for(int i=0; i<strlen(content); i++)
    {
        hash *= FNV_PRIME_32;
        hash ^= content[i];
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