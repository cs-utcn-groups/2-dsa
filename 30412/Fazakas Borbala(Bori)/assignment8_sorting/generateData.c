//
// Created by Bori on 5/6/2020.
//

#include "generateData.h"
#include <stdlib.h>
#include <time.h>


#define MAX_ELEMENTS 10000

void writeRandomArraysToFile(int noArrays) {
    FILE *outFile = fopen("data.in", "w");
    srand(time(0));
    for (int i = 1; i <= noArrays; i++) {
        int noElements = rand() % MAX_ELEMENTS;
        fprintf(outFile, "%d\n", noElements);
        for (int j = 1; j <= noElements; j++) {
            fprintf(outFile, "%d ", rand());
        }
        fprintf(outFile, "\n");
    }
    fclose(outFile);
}

int compareInt(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void appendSortedArrayToFile_Ascending(int noArrays) {
    FILE *outFile = fopen("data.in", "a");
    for (int i = 1; i <= noArrays; i++) {
        int noElements = rand() % MAX_ELEMENTS;
        fprintf(outFile, "%d\n", noElements);
        int *a = (int *) malloc(sizeof(int) * noElements);
        for (int j = 0; j < noElements; j++) {
            a[j] = rand();
        }
        qsort(a, noElements, sizeof(int), compareInt);
        for (int j = 0; j < noElements; j++) {
            fprintf(outFile, "%d ", a[j]);
        }
        fprintf(outFile, "\n");
    }
    fclose(outFile);
}

int compareIntDescending(const void *a, const void *b) {
    return -*(int *) a + *(int *) b;
}

void appendSortedArrayToFile_Descending(int noArrays) {
    FILE *outFile = fopen("data.in", "a");
    for (int i = 1; i <= noArrays; i++) {
        int noElements = rand() % MAX_ELEMENTS;
        fprintf(outFile, "%d\n", noElements);
        int *a = (int *) malloc(sizeof(int) * noElements);
        for (int j = 0; j < noElements; j++) {
            a[j] = rand();
        }
        qsort(a, noElements, sizeof(int), compareIntDescending);
        for (int j = 0; j < noElements; j++) {
            fprintf(outFile, "%d ", a[j]);
        }
        fprintf(outFile, "\n");
    }
    fclose(outFile);
}
