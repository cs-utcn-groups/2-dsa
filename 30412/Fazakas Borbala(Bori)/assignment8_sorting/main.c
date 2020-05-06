#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "generateData.h"
#include <string.h>


int main() {
    int noArrays = 12;
    //generating data
    writeRandomArraysToFile(10);
    appendSortedArrayToFile_Ascending(1);
    appendSortedArrayToFile_Descending(1);
    appendRandomArraysToFile_withConstraint(10, 100);
    appendSortedArrayToFile_Ascending_withConstraint(1, 100);
    appendSortedArrayToFile_Descending_withConstraint(1, 100);

    //sorting
    int noElements;
    FILE *inFile = fopen("data.in", "r");
    FILE *outFile = fopen("conclusions.out", "w");
    actions sortActions;

    for (int j = 1; j <= noArrays; j++) {
        fscanf(inFile, "%d", &noElements);
        int *a = (int *) malloc(sizeof(int) * (noElements + 1));
        int *aCopy = (int *) malloc(sizeof(int) * (noElements + 1));
        for (int i = 1; i <= noElements; i++) {
            fscanf(inFile, "%d", &a[i]);
        }

        fprintf(outFile, "--------------Array nr. %d--------------\n", j);
        if (j == noArrays - 1) {
            fprintf(outFile, "!!!this array was sorted in an ascending order!!!\n");
        } else if (j == noArrays) {
            fprintf(outFile, "!!!this array was sorted in a descending order!!!\n");
        }
        fprintf(outFile, "Array size is %d\n", noElements);

        fprintf(outFile, "Insertion sort:\n");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        sortActions = insertionSort(aCopy, noElements);
        printActions(outFile, &sortActions);

        fprintf(outFile, "Merge sort:\n");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        sortActions = mergeSort(aCopy, noElements);
        printActions(outFile, &sortActions);

        fprintf(outFile, "Heap sort:\n");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        sortActions = heapSort(aCopy, noElements);
        printActions(outFile, &sortActions);

        /*fprintf(outFile, "Quicksort:\n");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        sortActions = quickSort(aCopy, noElements);
        printActions(outFile, &sortActions);*/

        fprintf(outFile, "Radix sort:\n");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        sortActions = radixSort(aCopy, noElements);
        printActions(outFile, &sortActions);
    }
    return 0;
}