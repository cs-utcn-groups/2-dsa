#include "hashTable.h"
#include"io.h"


void initHashTable(int N)
{
    size=N*INITIAL_HT_SIZE_FACTOR;
    hashTable=(char**)malloc(size* sizeof(char*));
    for(int i=0;i<=size;i++)
    {
        hashTable[i]=(char*)malloc(MAX_STRING_LENGTH*sizeof(char));
        strcpy(hashTable[i],"*");
    }
}

float getFillFactor()
{
    int count=0;
    float fillFactor = -1;
    for(int k=0;k<size;k++)
    {

        if(strcmp(hashTable[k],"*")!=0)
        {
            count++;
        }
    }
    fillFactor=(float)count/size;
    fillFactor=fillFactor*100;
    return fillFactor;
}

void resizeHashTable()
{
      int  newSize=size*2;
      size=newSize;
        char ** newHashTable=(char**)malloc(newSize*sizeof(char*));
        for(int i=0;i<size;i++)
        {

        newHashTable[i]=(char*)malloc(MAX_STRING_LENGTH*sizeof(char));
         strcpy(newHashTable[i],"*");
        }

        for(int i=0;i<size/2;i++)
        {

            if(strcmp(hashTable[i],"*")!=0)
            {
                 int value,k=0;
                 value=hashFunction2(hashTable[i],k);
                while (strcmp(newHashTable[value],"*")!=0)
                {
                    value=hashFunction2(hashTable[i],++k);

                }
                strcpy(newHashTable[value],hashTable[i]);
            }
        }
        for(int i=0;i<size/2;i++)
            free(hashTable[i]);
        free(hashTable);
        hashTable=newHashTable;

}



int insertElement(char *element)
{
    int collisions=0;
    int value,k=0;
    value=hashFunction2(element,k);
    while (strcmp(hashTable[value],"*")!=0)
    {
        value=hashFunction2(element,++k);
        collisions++;
    }
    strcpy(hashTable[value],element);
    return collisions;
}
int hashFunction(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;
}
int hashFunction2(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum = sum+content[k];
    }
    return (sum*i) % size;
}
int hashFunction3(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum =sum*i+ content[k];
    }
    return sum % size;
}

