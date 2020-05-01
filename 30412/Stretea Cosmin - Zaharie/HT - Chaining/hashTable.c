#include "hashTable.h"
#include "io.h"
#include <math.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size = INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (listT **)malloc(sizeof(listT*) * size);
    for (int i = 0; i < size; ++i) {
        hashTable[i] = (listT *)malloc(sizeof(listT));
        hashTable[i]->size = 0;
        hashTable[i]->tail = NULL;
        hashTable[i]->head = NULL;
    }
}

void insertElement(char * element, int i)
{
    //! insert an element
    int pos = hashFunction(element, i);
    addToList(hashTable[pos], element);
    //printf("%s %s %d\n", hashTable[pos]->head->content, hashTable[pos]->tail->content, hashTable[pos]->size);
}

int hashFunction(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }

    return (sum + i + i*i/2 )% size;
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

    int max = N;
    for(int i = 0; i < size; ++i){
        float procent = (hashTable[i]->size / (float) max) * 100;
        int noOfStelutze = procent / 0.5;
        printf("B%d: ", i);
        for(int j = 0; j < noOfStelutze; ++j)
            printf("*");
        for(int i = 0; i < 100 - noOfStelutze; ++i)
            printf(" ");
        printf(" (~%f)\n", noOfStelutze * 0.5);
    }

}
void computeStandardDeviation(int N) {
    float meanValue;
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum+= hashTable[i]->size;
    }
    meanValue = sum / (float) N;
    sum = 0;
    for (int i = 0; i < size; ++i) {
        sum+= (hashTable[i]->size - meanValue) * (hashTable[i]->size - meanValue);
    }
    printf("The standard deviation is: %.2f", sqrt(sum / (float) N));
}
