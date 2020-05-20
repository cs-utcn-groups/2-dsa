#include <stdio.h>
#include <stdlib.h>

int nrElements;

void read(FILE * in);
void mergeSort(int lBound, int rBound, int * arr);
int * merge(int left, int mid, int right, int * arr);

void read(FILE * in)
{
    fscanf(in,"%d",&nrElements);

    int * arr=(int *) malloc(sizeof(int) * nrElements);

    for(int i=0; i<nrElements; i++)
    {
        fscanf(in,"%d",&arr[i]);
    }

    mergeSort(0,nrElements-1,arr);

    for(int i=0; i<nrElements; i++)
    {
        printf("%d ",arr[i]);
    }
}

void mergeSort(int lBound, int rBound, int * arr)
{
    if(lBound<rBound)
    {
        int mid=(lBound+rBound)/2;
        mergeSort(lBound,mid,arr);
        mergeSort(mid+1,rBound,arr);

        arr=merge(lBound,mid,rBound,arr);
        /// printf("%d %d %d\n",lBound,mid,rBound);
    }
}

int * merge(int left, int mid, int right, int * arr)
{
    int * auxArray=(int *) malloc(sizeof(int) * (right-left+1));
    int indexOfAuxArray=left;
    int leftArrayIndex=left,rightArrayIndex=mid+1;

    while(leftArrayIndex<=mid && rightArrayIndex<=right)
    {
        if(arr[leftArrayIndex] <= arr[rightArrayIndex])
        {
            auxArray[indexOfAuxArray]=arr[leftArrayIndex];
            leftArrayIndex++;
        }
        else
        {
            auxArray[indexOfAuxArray]=arr[rightArrayIndex];
            rightArrayIndex++;
        }
        indexOfAuxArray++;
    }

    for(int i=leftArrayIndex; i<=mid; i++)
    {
        auxArray[indexOfAuxArray]=arr[i];
        indexOfAuxArray++;
    }

    for(int i=rightArrayIndex; i<=right; i++)
    {
        auxArray[indexOfAuxArray]=arr[i];
        indexOfAuxArray++;
    }

    for(int i=left; i<=right; i++)
    {
        arr[i]=auxArray[i];
    }

    return arr;
}

int main()
{
    FILE * in=fopen("in.txt","r");
    read(in);

    return 0;
}
