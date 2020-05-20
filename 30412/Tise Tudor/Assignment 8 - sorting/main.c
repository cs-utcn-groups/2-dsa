#include <stdio.h>
#include "sorting.h"

int main() {
    int arr[] = {2,5,1,6,7,123,3,9,14};
    int lastIndexToCompare = 9;

    //bubble sort
    bubbleSort(arr,lastIndexToCompare);
    printArray(arr,lastIndexToCompare);

    //quick sort
    int arr2[] = {2,5,1,6,7,123,3,9,14};
    quickSort(arr2,0,lastIndexToCompare -1);
    printf("For the quick sort there are %d comparisons, %d assignments and %d acceses to the array\n",quickSortComparisons,quickSortAssignements,quickSortAccesToArray);
    printArray(arr2,lastIndexToCompare);

    //radix sort
    int arr3[] = {2,5,1,6,7,123,3,9,14};
    radixSort(arr3,lastIndexToCompare);
    printf("For the radix sort there are %d comparisons, %d assignments and %d acceses to the array\n",radixComparisons,radixAssignements,radixAccesToArray);
    printArray(arr3,lastIndexToCompare);


    return 0;
}