//
// Created by Tudor Tise on 11/05/2020.
//

#include "sorting.h"

void printArray(int array[], int lastIndex){
    for (int i =0; i <9; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}


void swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

void bubbleSort(int array[], int lastIndex){
    int bubbleComparisons = 0, bubbleAssignements = 0, bubbleAccesToArray = 0;
    for (int j = 0; j < lastIndex - 1; j++){
        for (int i = 0; i < lastIndex - j - 1; i++){
            bubbleComparisons++;
            if (array[i] > array[i+1]){
                swap(&array[i+1],&array[i]);
                bubbleAssignements +=3;
                bubbleAccesToArray += 2;
            }

        }
    }
    printf("For the bubble sort there are %d comparisons, %d assignments and %d acceses to the array\n",bubbleComparisons,bubbleAssignements,bubbleAccesToArray);

}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        quickSortComparisons++;
        if (arr[j] < pivot)
        {
            i++;
            quickSortAssignements += 3;
            quickSortAccesToArray +=2;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        radixComparisons++;
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++){
        count[ (arr[i]/exp)%10 ]++;
        radixAccesToArray++;
        radixAssignements++;
    }


    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        radixAccesToArray++;
        radixAssignements++;
    }
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
        radixAccesToArray += 4;
        radixAssignements += 2;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int m = findMax(arr, n);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}