#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LENGTH 100

int *initializeArray()
{
    int *array=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return array;
}

void readFile(int *nrOfEl,int *array,int *target,FILE *f)
{
    fscanf(f,"%d",nrOfEl);
    int n=*nrOfEl;
    for(int i=0; i<n; i++)
        fscanf(f,"%d",&array[i]);
    fscanf(f,"%d",target);
}

void binarySearch(int n,int target, int *array)
{
    int left=0,right=n-1,mid;
    bool ok=false;

    while(ok==false && left<=right)
    {
        mid=(left+right)/2;

        if(array[mid]==target)
        {
            ok=true;
            printf("The target was found at index %d",mid);
        }
        else if(array[mid]>target)
            right=mid-1;
        else
            left=mid+1;
    }

    if(ok==false)
        printf("The target was not found");
}

int main()
{
    FILE *f=fopen("input.in","r");
    int nrOfEl,target;
    int *array=initializeArray();
    readFile(&nrOfEl,array,&target,f);
    binarySearch(nrOfEl,target,array);

    return 0;
}
