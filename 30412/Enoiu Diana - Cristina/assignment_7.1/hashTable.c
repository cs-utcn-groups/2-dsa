//
// Created by Diana on 07/05/2020.
//

#include "hashTable.h"

listT * initHashTable(int N)
{
    sizeHashTable = (int)((float)N * INITIAL_HT_SIZE_FACTOR);
    hashTable = (listT *) malloc (sizeHashTable * sizeof(listT));
    for (int i=0; i<sizeHashTable; i++) {
        hashTable[i].sizeList = 0;
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }
    return hashTable;
}

void insertElement(char * element)
{
    int key = 0;
    if(state == 0)key = hashFunction0(element);
    else if(state == 1)key = hashFunction1(element);
    else if(state == 2)key = hashFunction2(element);
    else if(state == 3)key = hashFunction3(element);
    addToList(&hashTable[key],element);
}
int hashFunction0(const char *content) {  //depends on luck
    int length = (int)strlen(content);
    long long prod;
    int k;
    for (prod=1, k=0; k < length; k+=8)
    {
        prod = prod * content[k];
    }
    int key = (int)(prod % sizeHashTable);
    return key;
}
int hashFunction1(char * content)
{
    int length = (int)strlen(content);
    int k,sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    int key = sum % sizeHashTable;
    return key;
}
int hashFunction2(char * content)
{
    int length = (int)strlen(content);
    int k,sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    sum = sum*9 + content[0] + content[1] + content [2];
    int key = sum % sizeHashTable;
    return key;

}
int hashFunction3(char * content)
{
    int length = (int)strlen(content);
    int k,sum,sum2;

    for (sum=0,sum2=0, k=0; k < length-1; k++)
    {
        int aux = content[k];
        while(aux) {
            sum2 += aux % 10;
            aux = aux/10;
        }
        sum += content[k];
    }

    sum = sum * 99 + sum2 * 7 + content[0];

    int key = sum % sizeHashTable;
    return key;

}

void computeDistributionsPerBucket(int N)
{
    printf("//////////////////////////////////////////////////////////////////////////////////////////////\n"
                "Hash Function %d --- ISF:%.2lf\n",state,INITIAL_HT_SIZE_FACTOR);
    double x = .5;
    for(int i=0; i<sizeHashTable; i++) {
        double percentage = (double)hashTable[i].sizeList/N;
        percentage = percentage*100;
        printf("B%d: ",i);
        for(double k = x; k<=percentage;) {
            printf("*");
            k +=x;
        }
        printf(" (~%.lf%%)\n",percentage);
    }
}
double calculateStandardDeviation () {
    double mean = 0;
    int noOfElements = 0;
    for (int i=0; i< sizeHashTable; i++) {
        if(hashTable[i].sizeList != 0) {
            mean += hashTable[i].sizeList;
            noOfElements++;
        }
    }
    mean = mean/noOfElements;
    double sumOfSqDif = 0;
    double * squaredDifferences = (double*) malloc (sizeHashTable * sizeof(double));
    for (int i = 0; i<sizeHashTable; i++) {
        squaredDifferences[i] = (hashTable[i].sizeList - mean) * (hashTable[i].sizeList - mean);
        sumOfSqDif += squaredDifferences[i];
    }
    return sqrt(sumOfSqDif / sizeHashTable);
}


