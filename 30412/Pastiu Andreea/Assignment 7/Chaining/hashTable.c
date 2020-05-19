#include "hashTable.h"

void initHashTable(int N)
{
    size = N * INITIAL_HT_SIZE_FACTOR;
    hashTable = (listT**) malloc(size * sizeof(listT*));
    for(int i = 0; i < size; i++)
    {
        hashTable[i] = (listT*) malloc(sizeof(listT));
        hashTable[i]->head = NULL;
        hashTable[i]->tail = NULL;
        hashTable[i]->size = 0;
    }
}

void insertElement(char * element)
{
    int no = hashFunction(element);
    addToList(hashTable[no], element);
}

int hashFunction(char * content)
{
    /*int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;*/
    /*long sum = 0, mul = 1;
    for (int j = 0; j < strlen(content); j++) {
        mul = (j % 4 == 0) ? 1 : mul * 256;
        sum += (content[j]) * mul;
    }
    return (int)(abs(sum) % size);*/
    /*long sum = 0;
    for (int j = 0; j < strlen(content); j++)
    {
        sum += content[j];
        sum += (sum << 5);
        sum ^= (sum >> 3);
    }
    sum += (sum << 3);
    sum ^= (sum >> 6);
    sum += (sum << 4);
    return (int)(abs(sum) % size);*/
    return strlen(content) % size;
}

double computeDistributionsPerBucket()
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
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += hashTable[i]->size;
    }
    double avg = sum * 1.0 / size;
    double meanSum = 0;
    for(int i = 0; i< size; i++)
    {
        meanSum += (hashTable[i]->size - avg) * (hashTable[i]->size - avg);
    }
    double standardDeviation = sqrt(meanSum/size);
    printf("%.2lf, ", standardDeviation);
    return  standardDeviation;
}
