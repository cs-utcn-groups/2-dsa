//
// Created by ileana on 5/8/2020.
//

#include "sortingAlgorithms.h"
#include <stdio.h>
#include <stdlib.h>

int findMax(const int * a, int n);
void mergeParts(int * arr, int s, int m, int d, int * comparison, int * assignment, int * access);
void mergeSortRec(int * array, int s, int d,int *comparison,int * assignment, int * access);
void quickSortRec(int * array, int p, int r,int *comparison,int * assignment, int * access);
int partition(int * arr, int p, int r,int *comparison,int * assignment, int * access);

void insertionSort(int * array, int n)
{
    int comparison, assignment, access,actions;
    comparison=assignment=access=0;
    printf("\n*Insertion sort started*\n");
    for(int i = 1;i<n;i++)
    {
        int j=i-1;
        int aux=array[i];
        access++;
        while(array[j]>aux && j>=0) {
            array[j+1] = array[j];
            comparison++;
            assignment++;
            access++;
            j--;
        }
        array[j+1]=aux;
        assignment++;
    }
    printf("Sorted array:");
    printArray(array,n);
    printf("*Insertion sort ended*\n");
    actions = comparison+assignment+access;
    printf("Total number of actions: %d\n",actions);
    printf("Number of comparisons: %d, assignments: %d, accesses: %d\n",comparison,assignment,access);
}

void mergeSort(int * array,int n)
{
    int comparison, assignment, access,actions;
    comparison=assignment=access=0;
    printf("\n*Merge sort started*");

    mergeSortRec(array,0,n-1,&comparison,&assignment,&access);
    printArray(array,n);
    printf("*Merge sort ended*\n");
    actions = comparison+assignment+access;
    printf("Total number of actions: %d\n",actions);
    printf("Number of comparisons: %d, assignments: %d, accesses: %d\n",comparison,assignment,access);
}

void mergeSortRec(int * array, int s, int d,int *comparison,int * assignment, int * access)
{
    if(s<d)
    {
        int m=(s+d)/2;
        mergeSortRec(array,s,m,comparison,assignment,access);
        mergeSortRec(array,m+1,d,comparison,assignment,access);
        mergeParts(array,s,m,d,comparison,assignment,access);
    }
}

void mergeParts(int * arr, int s, int m, int d, int * comparison, int * assignment, int * access)
{

    int n1=m-s+1;        // nr of elem in first array
    int n2=d-(m+1)+1;   //nr of elem in second array
    int i,j,k;

    int * leftArr = (int *)malloc(n1* sizeof(int));
    int * rightArr = (int *)malloc(n2* sizeof(int));

    for(i=0;i<n1;i++) {
        leftArr[i] = arr[s + i];
        (*access)++;
    }

    for(i=0;i<n2;i++) {
        rightArr[i] = arr[i + m + 1];
        (*access)++;
    }

    i=j=0;
    k=s;

    while(i<n1 && j<n2) {
        if (leftArr[i] < rightArr[j]) {
            (*comparison)++;
            arr[k] = leftArr[i++];
            (*assignment)++;
        }
        else {
            (*comparison)++;
            arr[k] = rightArr[j++];
            (*assignment)++;
        }
        k++;
    }

    while(i<n1) {
        arr[k++] = leftArr[i];
        (*assignment)++;
        i++;
    }
    while(j<n2) {
        arr[k++] = rightArr[j++];
        (*assignment)++;
    }
}

void countingSort(int * a, int n)
{
    int comparison, assignment, access,actions;
    comparison=assignment=access=0;

    printf("\n*Counting sort started*");
    int i,j,maxv;
    maxv = findMax(a,n);
    comparison=n;
    int * countArray = (int *)malloc((maxv+1)* sizeof(int));

   for(i=0;i<=maxv;i++)
       countArray[i]=0;

   for(i=0;i<n;i++) {
       access++;
       countArray[a[i]]++;
   }

    int k=0;
    for(i=0; i<=maxv;i++)
        for(j=0;j<countArray[i];j++) {
            a[k++] = i;
            assignment++;
        }

    printArray(a,n);
    printf("*Counting sort ended*\n");
    actions = comparison+assignment+access;
    printf("Total number of actions: %d\n",actions);
    printf("Number of comparisons: %d, assignments: %d, accesses: %d\n",comparison,assignment,access);
}

int findMax(const int * a, int n)
{
    int maxv = a[0];
    for(int i=1;i<n;i++)
        if(a[i]>maxv)
            maxv=a[i];
    return  maxv;
}


void quickSort(int * array,int n)
{
   int comparison, assignment, access,actions;
    comparison=assignment=access=0;
    printf("\n*Quick sort last element as pivot started*");

    quickSortRec(array,0,n-1,&comparison,&assignment,&access);
    printArray(array,n);
    printf("*Quick sort last element as pivot ended*\n");
    actions = comparison+assignment+access;
    printf("Total number of actions: %d\n",actions);
    printf("Number of comparisons: %d, assignments: %d, accesses: %d\n",comparison,assignment,access);

}

void quickSortRec(int * array, int p, int r,int *comparison,int * assignment, int * access)
{
    if(p<r) {
        int q = partition(array, p, r,comparison,assignment,access);
        quickSortRec(array, p, q - 1,comparison,assignment,access);
        quickSortRec(array, q + 1, r,comparison,assignment,access);
    }
}

int partition(int * arr, int p, int r,int *comparison,int * assignment, int * access)
{
    int pivot = arr[r];     //last element as pivot
    int i = p-1,aux;
    for(int j=p; j<r;j++) {
        if (arr[j] <= pivot) {
            i++;
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            *assignment = *assignment+2;
            (*comparison)++;
            *access = *access+4;
        }
    }
    aux=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=aux;
    *access = *access+4;
    *assignment = *assignment+2;
    return  i+1;
}



void printArray(int * arr, int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
