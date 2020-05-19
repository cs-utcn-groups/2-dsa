//
// Created by Alina Mihut on 5/10/20.
//
#include "sortingAlgorithms.h"

void initializeActions()
{
    actions=0;
    comparisons=0;
    assignments=0;
    arrayAccesses=0;
}
void printActions()
{
actions= comparisons + assignments + arrayAccesses;
printf("The total number of %d comparisons + %d assignments + %d array accesses is %d \n", comparisons, assignments, arrayAccesses, actions);
}

//--------bubble sort------
void swap(int *a, int *b)
{
    int aux= *a;
    *a = *b;
    *b= aux;
}

void bubbleSort ()
{
   initializeActions();
    for (int i = 0; i < sizeOfArray - 1; i++) {
        arrayAccesses++;
        for (int j = 0; j < sizeOfArray - i - 1; j++) {
            arrayAccesses++;
            comparisons++;
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                assignments+=3;
            }
        }
    }
    printArray();
    printActions();
}

//-----------merge sort--------------

void merge(int l, int m, int r)
{

    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int *L, *R;
    L=(int*) malloc (n1* sizeof(int));
    R=(int*) malloc (n2* sizeof(int));

    for (i = 0; i<n1; i++)
    {
        L[i] = array[l+i];
        assignments++;
    }
    for (j = 0; j<n2; j++)
    {
        R[j] = array[m+1+j];
        assignments++;
    }
    i = 0;
    j = 0;
    k = l;
    arrayAccesses++;
    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            assignments++;
            i++;
        }
        else
        {
            array[k] = R[j];
            assignments++;
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        assignments++;
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        assignments++;
        j++;
        k++;
    }
}

void mergeSortRec(int left, int right)
{
    arrayAccesses=1;
    if (left < right)
    {

        int middle = left + (right-left) / 2;
        mergeSortRec(left, middle);;
        mergeSortRec(middle+1, right);
        merge(left, middle, right);
    }

}

void mergeSort()
{
    initializeActions();
    mergeSortRec(0,sizeOfArray-1);
    printArray();
    printActions();     //not sure i got the number of accesses right for this one
}
// ---------radix sort---------------

int getMaxNumber()
{
    int max = array[0];
    arrayAccesses++;
    for (int i=1; i<sizeOfArray; i++) {
        comparisons++;
        if (array[i] > max)
            max = array[i];
        assignments++;
    }
    return max;
}

void countSort(int place)
{
    int *output;
    int *count;
    int range=(array[0]/place)%10;
    arrayAccesses++;
    for (int i = 1; i < sizeOfArray; i++) {
        comparisons++;
        if (((array[i] / place) % 10) > range) {
            range = array[i];
            assignments++;
        }
    }
    output=(int*) malloc ((sizeOfArray)* sizeof(int));
    count=(int*) malloc (range* sizeof(int));
    for(int i=0;i<range;i++)
        count[i]=0;

    arrayAccesses++;
    for (int i = 0; i < sizeOfArray; i++)
        count[(array[i]/place)%10]++;

    for (int i = 1; i <10;i++)
        count[i] += count[i-1];

    arrayAccesses++;
    for (int i=sizeOfArray-1; i>= 0; i--)
    {
        output[count[(array[i]/place)%10]-1] = array[i];
        assignments++;
        count[ (array[i]/place)%10]--;
    }

    arrayAccesses++;
    for (int i = 0; i < sizeOfArray; i++) {
        array[i] = output[i];
        assignments++;
    }
}


void radixSort()
{
    initializeActions();
    int max = getMaxNumber();
    assignments++;

    for (int place = 1; max/place> 0; place *= 10)
        countSort(place);
    printArray();
    printActions();
}