#include "algorithms.h"
#include <stdlib.h>

void allocate()
{
    a = (int*)malloc(sizeof(int) * size);
    for( int i = 0 ; i < size ; i++)
        a[i] = (size - i)%4;
    frequencyArray = (int*)malloc(sizeof(int) * size);
    table = (int*)malloc(sizeof(int) * size);
    for(int i = 0 ; i <size ;i++)
        frequencyArray[i] = 0;
}

void swap(int *x, int *y)
{
    int t = *y;
    *y = *x;
    *x = t;
}

void insertionSort( int *a, int n )
{
    acces = 0;
    assignmets = 0;
    acces = 0;
    for(int i = 1 ; i < n  ; i++)
    {
        int j = i;
        while ( j> 0 && a[j-1] > a[j])
        {
            comparisions++;
            assignmets+=3;
            acces+=4;

            swap(&a[j-1], &a[j]);
            j--;
        }

    }
}

int partition (int *a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    acces++;

    for(int j = low ; j<= high - 1 ; j++,comparisions++)
        if(a[j] < pivot )
        {
            i++;
            swap(&a[i], &a[j]);
            comparisions++;
            acces++;
            assignmets+=3;
        }
        swap(&a[i + 1], &a[high]);
        assignmets++;
        acces++;
        return (i+1);

}

void quicksort(int *a, int low, int high)
{
    if(low < high)
    {
        int t = partition(a, low, high);
        quicksort(a, low, t-1);
        quicksort(a, t+1, high);
    }
}

void countingSort( int *a, int n)
{
    int max=0,j=0;
    for(int i = 0 ; i < n ; i++)
        max = a[i]>max ? a[i] : max;
    for(int i = 0 ; i < n ; i++)
        frequencyArray[a[i]]++;



    for(int i = 0 ; i < n ; i++,comparisions++)
        while(frequencyArray[i]>0)
        {
            table[j]=i;
            j++;
            frequencyArray[i]--;
            acces+=2;
            comparisions++;
            assignmets+=2;
        }

    for(int j = 0 ; j < n ; j++)
        a[j] = table[j];
    acces+=n*3;
    assignmets+=n;


}
