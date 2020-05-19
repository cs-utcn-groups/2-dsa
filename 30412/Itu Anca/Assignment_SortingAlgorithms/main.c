#include "SortingAlgorithms.c"
#include <stdio.h>
#define MAX 100


int main() {
    int n, arr[MAX], i;
    printf("Number of elements of array:\n");
    scanf("%d", &n);

    printf("\nElements of array:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nBubble Sort:\n");
    bubbleSort(arr, n);
    printf("Sorted array by Bubble Sort:  ");
    printArray(arr, n);

    printf("\n\nMerge Sort:\n");
    mergeSort(arr, 0, n-1);
    printf("Number of comparisons: %d\n", count1);
    printf("Number of assignments: %d\n", nrP1 + nrP2);
    printf("Sorted array by Merge Sort:  ");
    printArray(arr, n);

    printf("\n\nCounting Sort:\n");
    countingSort(arr, n);
    printf("Sorted array by Counting Sort:  ");
    printArray(arr, n);

    return 0;
}