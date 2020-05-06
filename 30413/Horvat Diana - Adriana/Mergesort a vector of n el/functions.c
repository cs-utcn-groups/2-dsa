#include "head.h"

int array[MAX_LENGTH];

void readFile(FILE *f,int *n)
{
    fscanf(f,"%d",n);

    for(int i=0;i<*n;i++)
    fscanf(f,"%d",&array[i]);
}

void merge(int *n,int lBound,int mid,int rBound)
{
    int i=lBound,j=mid+1,k=lBound,temp[MAX_LENGTH];


    while(i<=mid && j<=rBound)
    {
        if(array[i]<array[j])
        {
            temp[k]=array[i];
            i++;
        }
        else {
            temp[k]=array[j];
            j++;
        }
        k++;
    }

    for(int t=i;t<=mid;t++)
    {
        temp[k]=array[t];
        k++;
    }

    for(int t=j;t<=rBound;t++)
    {
        temp[k]=array[t];
        k++;
    }

    for(int t=lBound;t<=rBound;t++)
        array[t]=temp[t];
}

void mergesort(int *n,int lBound,int rBound)
{
    int mid;

    if(lBound<rBound)
    {
        mid=(lBound+rBound)/2;
        mergesort(n,lBound,mid);
        mergesort(n,mid+1,rBound);
        merge(n,lBound,mid,rBound);
    }
}

void printArray(int *n)
{
    printf("Sorted vector:\n");
    for(int i=0;i<*n;i++)
        printf("%d ",array[i]);
}

