//
// Created by Alex on 02.05.2020.
//

#include "hashTable.h"


void initHashTable(int N) {
    size = N * INITIAL_HT_SIZE_FACTOR;
    hashTable=(char**)malloc(size*sizeof(char*));
    for (int i = 0; i < size; i++)
        hashTable[i]=NULL;
}


float getFillFactor(int size) {
    float fillFactor = -1;
    for (int i = 0; i < size; i++) {
        if (hashTable[i] != NULL)
            fillFactor++;
    }
    fillFactor = (fillFactor / size);
    return fillFactor;
}

void resizeHashTable() {
    int osize = size;
    size = size * 2;
    char **TempHashTable=(char**)malloc(size* sizeof(char*));
    for (int i = 0; i < size; i++)
        TempHashTable[i] = NULL;
    for (int i = 0; i < osize; i++) {
        if (hashTable[i] != NULL) {
            int j = 0, ok = 0,c=-1;
            while (ok == 0) {
                int z = hashFunction(hashTable[i], j);
                if (TempHashTable[z] == NULL) {
                    TempHashTable[z] = hashTable[i];
                    ok = 1;
                } else {
                    j++;
                }
                c++;
            }
            if(c>maxcol)
                maxcol=c;
        }
    }
    free(hashTable);
    hashTable = TempHashTable;
}

int insertElement(char *element) {
    int c = -1, ok = 0, i = 0;
    while (ok == 0) {
        c++;
        int z = hashFunction(element, i);
        if (hashTable[z] == NULL) {
            hashTable[z] = element;
            ok = 1;
        } else
            i++;
    }
    return c;
}

int hashFunction(char * content, int i)
{
    int len = strlen(content);
    int sum = 0;
    for (int j = 0; j < len; j++) {
        sum += content[j];
    }
    return (sum*i+len*content[i%(len-2)]+i) % size;
}/*
int hashFunction3(char * content, int i)
{
    int len=strlen(content);
    int sum=0;
    for(int j=0;j<len;j++)
    {
        sum+=content[j];
    }
    return (sum*i*i+len*i+i)%size3;
}*/