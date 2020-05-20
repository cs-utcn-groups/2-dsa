#include "hashTable.h"


void initHashTable(int N)
{
    size = INITIAL_HT_SIZE_FACTOR * N;
    hashTable = (listT*)malloc(sizeof(listT)*size);
    for (int i = 0; i < size; i++){
        hashTable[i].size = 0;
    }
    for (int i = 0; i < size; i++) {
        hashTable[i].size = 0;
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }
}

void insertElement(char * content)
{
    int aux = hash3(content);
    addToList(&hashTable[aux], content);
}

int hash0(char *content) {
    return (content[0] + content[strlen(content)-1])%2;
}

int hash1(char * content)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;
}

int hash2(char * content)
{
    int length = strlen(content);
    long sum = 0, mul = 1;
    for (int i = 0; i < length; i++) {
        mul = (i % 4 == 0) ? 1 : mul * 256;
        sum += content[i] * mul;
    }
    return labs(sum) % size;
}

int hash3(char * content)
{
    int hash = 5381;

    for (int i = 0; i < strlen(content);i++)
        hash = ((hash << 5) + hash) + content[i];

    return abs(hash) % size;
}

void computeDistributionsPerBucket(int N)
{
    int X = 35;
    for (int i = 0; i < size; i++) {
        float fraction = (float)hashTable[i].size/N;
        float percentage = fraction*100;
        printf("B%d: ", i);
        printf("(~%.2f%%) \n", percentage);
    }
    printf("\n\n");

}

float calculateSD(int N) {
    float sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 0; i < size; ++i) {
        sum += hashTable[i].size;
    }
    mean = sum / size;
    for (i = 0; i < size; ++i)
        SD += pow(hashTable[i].size - mean, 2);
    return sqrt(SD / size);
}
