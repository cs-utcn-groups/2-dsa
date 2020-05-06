#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "generateData.h"
#include <string.h>


int main() {
    int noArrays = 12;
    writeRandomArraysToFile(10);
    appendSortedArrayToFile_Ascending(1);
    appendSortedArrayToFile_Descending(1);
    int noElements;
    FILE *inFile = fopen("data.in", "r");

    for (int j = 1; j <= noArrays; j++) {
        fscanf(inFile, "%d", &noElements);
        int *a = (int *) malloc(sizeof(int) * (noElements + 1));
        for (int i = 1; i <= noElements; i++) {
            fscanf(inFile, "%d", &a[i]);
        }

        int *aCopy = (int *) malloc(sizeof(int) * (noElements + 1));
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        insertionSort(a, noElements);

        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        mergeSort(a, noElements);

        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        heapSort(a, noElements);

        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        quickSort(a, noElements);

        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        radixSort(a, noElements);

        memcpy(aCopy, a, noElements * sizeof(int));
        heapSort(a, noElements);

        memcpy(aCopy, a, noElements * sizeof(int));
        heapSort(a, noElements);
    }


    // mergeSort(a, noElements);
    return 0;
}