#include "hashTable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size=N*INITIAL_HT_SIZE_FACTOR;
    hashTable=(listT*)malloc(size* sizeof(listT));
    for(int i=0;i<=size;i++)
    {
        hashTable[i].head=hashTable[i].tail=NULL;
    }
}

void insertElement(char * element)
{
    //! insert an element
    for(int i=0;i<size;i++)
    {
        if(i==hashFunction(element)) {
            addToList(&hashTable[i], element);
            break;
        }
    }
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
int badHashFunction(char * content)
{

    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
            sum += content[k];
    }
        return sum % 2;
}
int hashFunction2(char * content)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
            sum =sum*3+content[k];
    }
        return sum % size;
}
int hashFunction3(char * content)
{
    //! keep in mind, size in this case simply means the number of buckets
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        if(k%2==0)
            sum =sum*3+content[k];
        else
         sum =sum*5+content[k];

    }
        return sum % size;
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
    float percent;

   for(int i=0;i<size;i++)
   {
       if(hashTable[i].head==NULL) {
           printf("No list!");
           printf("\n");
       }
       else{
           for(int j=0;j<hashTable[i].size;j++)
           {

               printf("*");
           }
           percent=(hashTable[i].size*100)/N;
           printf("%.2f",percent);
           printf("%%\n");
       }
   }

}
void standardDeviation()
{

    int sum=0;
    float dif=0,sum2=0;
    float mean=0,sd=0,sdValue=0;
    for(int i=0;i<size;i++)
    {

        sum+=hashTable[i].size;
    }
    mean=(float)sum/size;
     for(int i=0;i<size;i++)
    {
        dif=(float)hashTable[i].size-mean;
        sum2=sum2+dif*dif;

    }
    sd=(float)(sum2/size);
    sdValue=sqrt(sd);
    printf("The standard deviation is %.2f ",sdValue);
}
