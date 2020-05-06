#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "generateData.h"
#include <string.h>
#include <time.h>


//time comparisons are not real, due to lots of unnecessary steps(counting actions, check if sort was correct, etc.)

int main() {
    int noArrays = 12;
    //generating data
    writeRandomArraysToFile(10);
    appendSortedArrayToFile_Ascending(1);
    appendSortedArrayToFile_Descending(1);

    //sorting
    int noElements;
    FILE *inFile = fopen("data.in", "r");
    FILE *outFile = fopen("out.txt", "w");
    actions sortActions;
    clock_t start, end;

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

        fprintf(outFile, "Insertion sort: ");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        start = clock();
        sortActions = insertionSort(aCopy, noElements);
        end = clock();
        fprintf(outFile, "Total time was: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);
        printActions(outFile, &sortActions);

        fprintf(outFile, "Merge sort: ");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        start = clock();
        sortActions = mergeSort(aCopy, noElements);
        end = clock();
        fprintf(outFile, "Total time was: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);
        printActions(outFile, &sortActions);

        fprintf(outFile, "Heap sort: ");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        start = clock();
        sortActions = heapSort(aCopy, noElements);
        end = clock();
        fprintf(outFile, "Total time was: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);
        printActions(outFile, &sortActions);

        fprintf(outFile, "Quicksort: ");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        start = clock();
        sortActions = quickSort(aCopy, noElements);
        end = clock();
        fprintf(outFile, "Total time was: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);
        printActions(outFile, &sortActions);

        fprintf(outFile, "Radix sort: ");
        memcpy(aCopy, a, (noElements + 1) * sizeof(int));
        start = clock();
        sortActions = radixSort(aCopy, noElements);
        end = clock();
        fprintf(outFile, "Total time was: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);
        printActions(outFile, &sortActions);
    }
    return 0;
}