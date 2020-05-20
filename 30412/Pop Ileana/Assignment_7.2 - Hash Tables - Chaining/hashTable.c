#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<math.h>

int getNumberOfDistributionPerBucket(listT bucket);
void printBucketContent(listT bucket);

void initHashTable(int N)
{

    size = INITIAL_HT_SIZE_FACTOR*N;
    hashTable = (listT*)malloc(sizeof(listT)*size);
    for(int i=0;i<size;i++)
    {
        hashTable[i].head=hashTable[i].tail= NULL;
    }

    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
}

void insertElement(char * element,int (*hashFunction)(char *))
{
    //! insert an element
    int h = hashFunction(element);
    if(checkIfExists(hashTable[h],element)==0)
        addToList(&hashTable[h],element);
    else
    {
        printf("***\nDouble key error*** Press Enter to continue\n");
        getchar();
    }
}


int hashFunction0(char * content)
{

    return (content[0] + content[1]) % 2;
}

int hashFunction1(char * content)
{
    int lenght = strlen(content);
    int k,sum=0;

    for(k=0;k<lenght;k++)
        sum+=content[k];

    return sum % size;
}

int hashFunction2(char * content)
{
    int lenght = strlen(content);
    int k;
    unsigned int sum=0;

    for(k=0;k<lenght;k++)
        if(k%2==0)
            sum = sum*31+ content[k];
        else
            sum = sum*17+content[k];
    return sum%size;
}

int hashFunction3(char * content)
{
    int result = content[0];
    for(int i=1;i<strlen(content);i++)
        result = abs(result * 31 + content[i]);

    return result % size;
}


int hashFunction3r(char * content)
{
    int lenght = strlen(content);
    int k,sum=0;

    for(k=0;k<lenght;k++)
        if(content[k]%2==0)
            sum = sum*31+ content[k];
        else
            sum = sum*11+content[k];
    return sum%size;
}

int hashFunction4(char * content)
{
    int lenght = strlen(content);
    int k,sum=0;

    for(k=0;k<lenght;k++)
        if(k%3==0)
            sum=sum*31 + content[k];
        else
            if(k%3==1)
                sum = abs(sum*19 +content[k]);
            else
                sum = abs(sum*33+ content[k]);
    return sum%size;
}

int hashFunction5(char * content)      //Fowler–Noll–Vo hash function
{
    const unsigned int fnv_prime = 0x811C9DC5;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < strlen(content); content++, i++)
	{
		hash *= fnv_prime;
		hash ^= (*content);
	}

	return hash%size;
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
    //int MAX = 30*20;
    printf("\n");
    for(int i=0;i<size;i++)
    {
        float bucketDistribution =(float) (getNumberOfDistributionPerBucket(hashTable[i])*100)/N;
        printf("B%d: ",i);
        printBucketContent(hashTable[i]);
        printf(" (~%.30f%%)",bucketDistribution);
        printf("\n");
    }

}

int getNumberOfDistributionPerBucket(listT bucket)
{
    int distributions = 0;
    if(bucket.head!= NULL)
    {
        nodeT * node = bucket.head;
        while(node!=NULL)
        {
            distributions++;
            node=node->next;
        }
    }
    return distributions;
}

void printBucketContent(listT bucket)
{
    nodeT * node = bucket.head;
    while(node!=NULL)
    {
        printf("*");
        node=node->next;
    }
}

void computeStandardDeviation(int N)
{
    int s=0;
    float mean,SD=0;

    for(int i = 0; i < size; i++)
        s=s+getNumberOfDistributionPerBucket(hashTable[i]);

    mean = (float) s/size;
    for(int i = 0; i < size; i++)
        SD += pow((getNumberOfDistributionPerBucket(hashTable[i])-mean),2);
    SD = sqrt((float) SD/(size-1));
    printf("\n\n***The standard deviation is %0.5f***",SD);

    /*float CV = (float) SD/mean;     //coefficient of variation
    if(CV >1)
        printf(" - high Standard Deviation***");
    else
        printf(" - low Standard Deviation***");*/
}
