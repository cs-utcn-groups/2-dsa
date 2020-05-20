//
// Created by Bori on 5/6/2020.
//

#include "sorting.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(int *x, int *y) {
    int a = *y;
    *y = *x;
    *x = a;
}

bool isSorted(int *a, int noElements) {
    for (int i = 1; i < noElements; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

void printArray(int *a, int noElements) {
    for (int i = 1; i <= noElements; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

actions insertionSort(int *a, int noElements) {
    actions sortActions;
    sortActions.comparisons = 0;
    sortActions.assignments = 0;
    sortActions.accesses = 0;
    int index;
    for (int i = 2; i <= noElements; i++) {
        index = i;
        while (a[index] < a[index - 1] && index >= 2) {
            swap(&a[index], &a[index - 1]);
            index--;
            sortActions.comparisons++;
            //swap
            sortActions.accesses += 3; //plus above comparison
            sortActions.assignments += 2;
        }
        sortActions.comparisons++;
        sortActions.accesses++;
    }
    assert(isSorted(a, noElements));
    sortActions.total = sortActions.assignments + sortActions.comparisons + sortActions.accesses;
    return sortActions;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a < b ? b : a;
}

void quickSortHelper(int *a, int startIndex, int endIndex, actions *sortActions) {
    if (startIndex + 1 < endIndex) { //at least 3 elements
        int pivotIndex = endIndex;
        int noSmallerElements = 0;
        for (int i = startIndex; i < endIndex; i++) {
            if (a[i] < a[pivotIndex]) {
                noSmallerElements++;
                if (noSmallerElements <
                    i) { //in this case, a[noSmallerElements] is for sure >= pivotvalue, I don't need to check it again
                    swap(&a[startIndex + noSmallerElements - 1], &a[i]);
                    sortActions->assignments += 2;
                    sortActions->accesses += 2;
                }
            }
        }
        sortActions->comparisons += (endIndex - startIndex);
        sortActions->accesses += (endIndex - startIndex);
        swap(&a[startIndex + noSmallerElements], &a[pivotIndex]); //get the pivotvalue on the right place
        quickSortHelper(a, startIndex, startIndex + noSmallerElements - 1, sortActions);
        quickSortHelper(a, startIndex + noSmallerElements + 1, endIndex, sortActions);

    } else { //1 or 2 elements
        if (startIndex < endIndex && a[startIndex] > a[endIndex]) { //2 elements
            swap(&a[startIndex], &a[endIndex]);
            sortActions->accesses += 2;
            sortActions->assignments += 2;
        }
        sortActions->comparisons += 1;
        sortActions->accesses += 1;
    }
}

actions quickSort(int *a, int noElements) {
    actions sortActions;
    sortActions.comparisons = 0;
    sortActions.assignments = 0;
    sortActions.accesses = 0;
    quickSortHelper(a, 1, noElements, &sortActions);
    assert(isSorted(a, noElements));
    sortActions.total = sortActions.accesses + sortActions.assignments + sortActions.comparisons;
    return sortActions;
}

int getCorrespondentDigit(int n, int digitIndex, int radix) {
    return (n / (int) pow(radix, digitIndex - 1)) % radix;
}

void countingSort_digit(int *a, int noElements, int digitIndex, int radix, actions *sortActions) {
    //create buckets
    int **groupedByDigits = (int **) malloc(sizeof(int *) * radix);
    int *sizeOfGroups = (int *) malloc(sizeof(int) * radix);
    for (int i = 0; i <= 9; i++) {
        groupedByDigits[i] = (int *) malloc(sizeof(int) * (noElements + 1));
        sizeOfGroups[i] = 0;
    }
    sortActions->assignments += 20;

    //group numbers by the corresponding digit
    int group;
    for (int i = 1; i <= noElements; i++) {
        group = getCorrespondentDigit(a[i], digitIndex, radix);
        sizeOfGroups[group]++;
        groupedByDigits[group][sizeOfGroups[group]] = a[i];
        sortActions->accesses += 4;
        sortActions->assignments++;
    }

    //rearrange array
    int index = 1;
    for (int i = 0; i < radix; i++) {
        for (int j = 1; j <= sizeOfGroups[i]; j++) {
            a[index] = groupedByDigits[i][j];
            index++;
            sortActions->assignments++;
            sortActions->accesses++;
        }
    }

    //free memory
    for (int i = 0; i < radix; i++) {
        free(groupedByDigits[i]);
    }
    free(groupedByDigits);
    free(sizeOfGroups);
}

int noDigits(int n) {
    int result = 0;
    while (n > 0) {
        n /= 10;
        result++;
    }
    return result;
}

actions radixSort(int *a, int noElements) {
    actions sortActions;
    sortActions.comparisons = 0;
    sortActions.assignments = 0;
    sortActions.accesses = 0;
    int maxValue = 0;
    for (int i = 1; i <= noElements; i++) maxValue = max(a[i], maxValue);
    sortActions.accesses += noElements;
    int maxNoDigits = noDigits(maxValue);

    for (int i = 1; i <= maxNoDigits; i++) {
        countingSort_digit(a, noElements, i, 10, &sortActions);
    }

    assert(isSorted(a, noElements));
    sortActions.total = sortActions.accesses + sortActions.assignments + sortActions.comparisons;
    return sortActions;
}

void heapify(int *a, int noElements, int index, actions *sortActions) {
    if (noElements >= index * 2 && a[index] < a[index * 2]) {
        if (noElements >= index * 2 + 1 && a[index * 2 + 1] > a[index * 2]) {
            swap(&a[index], &a[index * 2 + 1]);
            heapify(a, noElements, index * 2 + 1, sortActions);
        } else {
            swap(&a[index], &a[index * 2]);
            heapify(a, noElements, index * 2, sortActions);
        }
        sortActions->comparisons += 2;
        sortActions->accesses += 2;
        //swap
        sortActions->accesses += 2;
        sortActions->assignments += 2;
    } else if (noElements >= index * 2 + 1 && a[index] < a[index * 2 + 1]) {
        swap(&a[index], &a[index * 2 + 1]);
        heapify(a, noElements, index * 2 + 1, sortActions);
        sortActions->comparisons += 2;
        sortActions->accesses += 2;
        //swap
        sortActions->accesses += 2;
        sortActions->assignments += 2;
    }
}

actions heapSort(int *a, int noElements) {
    actions heapActions;
    heapActions.accesses = 0;
    heapActions.assignments = 0;
    heapActions.comparisons = 0;

    //conrstruct heap
    for (int i = noElements / 2; i >= 1; i--) {
        heapify(a, noElements, i, &heapActions);
    }

    //get the ith largest element and the heapify
    for (int i = 1; i <= noElements - 1; i++) {
        swap(&a[1], &a[noElements - i + 1]);
        heapActions.accesses += 2;
        heapActions.assignments += 2;
        heapify(a, noElements - i, 1, &heapActions);
    }

    assert(isSorted(a, noElements));
    heapActions.total = heapActions.assignments + heapActions.accesses + heapActions.comparisons;
    return heapActions;
}

void merge(int *a, int start1, int start2, int end2, actions *mergeActions) {
    // int end1 = start2-1;
    int index_result = 1;
    int index_subarray1 = start1;
    int index_subarray2 = start2;

    int *result = (int *) malloc(sizeof(int) * (end2 - start1 + 2));
    while (index_result <= end2 - start1 + 1) {
        if ((index_subarray1 < start2 && a[index_subarray1] < a[index_subarray2]) || index_subarray2 > end2) {
            result[index_result++] = a[index_subarray1++];
        } else {
            result[index_result++] = a[index_subarray2++];
        }
        mergeActions->comparisons++;
        mergeActions->assignments++;
        mergeActions->accesses += 2;
    }

    memcpy(a + start1, result + 1, (end2 - start1 + 1) * sizeof(int));
    mergeActions->accesses += (end2 - start1 + 1);
    mergeActions->assignments += (end2 - start1 + 1);
    free(result);
}

void mergeSortHelper(int *a, int startIndex, int endIndex, actions *mergeActions) {
    if (endIndex > startIndex) {
        int middleIndex = (endIndex + startIndex) / 2;
        mergeSortHelper(a, startIndex, middleIndex, mergeActions);
        mergeSortHelper(a, middleIndex + 1, endIndex, mergeActions);
        merge(a, startIndex, middleIndex + 1, endIndex, mergeActions);
    }
}

actions mergeSort(int *a, int noElements) {
    actions mergeActions;
    mergeActions.accesses = 0;
    mergeActions.assignments = 0;
    mergeActions.comparisons = 0;
    mergeSortHelper(a, 1, noElements, &mergeActions);
    assert(isSorted(a, noElements));
    mergeActions.total = mergeActions.assignments + mergeActions.accesses + mergeActions.comparisons;
    return mergeActions;
}

void printActions(FILE *outFile, actions *sortingActions) {
    fprintf(outFile, "This sort needed %d array accesses, %d assignments and %d comparisons, %d actions in total\n",
            sortingActions->accesses, sortingActions->assignments, sortingActions->comparisons, sortingActions->total);
}
