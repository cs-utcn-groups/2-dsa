//
// Created by Alina Mihut on 5/2/20.
//

#include "hashTable.h"


void initHashTable(int N)
{

    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
     size=(INITIAL_HT_SIZE_FACTOR * N);
     hashTable=(listT*) malloc (sizeof(listT)*size);
     for (int i=0;i<size;i++)
     {
         hashTable[i].head=NULL;
         hashTable[i].tail=NULL;
         //hashTable[i].size=0;
     }
}

void insertElement(char * element)
{
    //! insert an element
    int i=hashFunction3(element);
    addToList(&hashTable[i], element);
    hashTable[i].size++;
}

int hashFunction0(char *content)
{
    //! keep in mind, size in this case simply means the number of buckets


    return content[0]%4;
}


int hashFunction1(char * content)
{

    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;
}

int hashFunction2 (char *content) {
   long  sum = 0;
    for (int i = 0; i < strlen(content); i++) {
        sum+=content[i]*i;
    }
    return sum%size;
}

int hashFunction3 (char *content) {
    int xor = 0;
    for (int i = 0; i < strlen(content); i++) {
        xor^=content[i]*i;
    }
    return xor;
}
void computeDistributionsPerBucket(int N, char **content)
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
    size=(int)(INITIAL_HT_SIZE_FACTOR * N);

    int count;
    float *distribution=(float*)malloc(size*sizeof(float));
    for(int i=0;i<size;i++)
    {
        nodeT *currentElement= hashTable[i].head;
        count=0;
        while (currentElement!=NULL)
        {
            count++;
            currentElement=currentElement->next;
        }

        distribution[i]=((float) 100*count)/N;
    }
    for(int i=0;i<size;i++)
        printf("B%d - %.2f %%  \n", i, distribution[i]);

}

void computeStandardDeviation()
{
        float sum=0.0;
        float miu,standardDev;
        for (int i=0;i<size;i++)
        {
            sum = sum + hashTable[i].size;
        }
        miu=(float)(sum/size);
        for (int i=0;i<size;i++)
        {
            sum=sum+(hashTable[i].size-miu)*(hashTable[i].size-miu);
        }
        standardDev=sqrt(sum/size);
        printf("The standard deviation is %.2f", standardDev);

}