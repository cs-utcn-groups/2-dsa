//
// Created by Bori on 5/6/2020.
//

#ifndef ASSIGNMENT8_SORTING_SORTING_H
#define ASSIGNMENT8_SORTING_SORTING_H

#include <stdio.h>

typedef struct {
    int comparisons, accesses, assignments, total;
} actions;

void printActions(FILE *outFile, actions *sortingActions);

actions insertionSort(int *a, int noElements);

actions quickSort(int *a, int noElements);

actions heapSort(int *a, int noElements);

actions mergeSort(int *a, int noElements);

actions radixSort(int *a, int noElements);

#endif //ASSIGNMENT8_SORTING_SORTING_H
