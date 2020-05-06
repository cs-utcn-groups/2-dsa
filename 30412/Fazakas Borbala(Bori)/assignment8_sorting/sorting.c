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
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
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
    int index;
    for (int i = 2; i <= noElements; i++) {
        index = i;
        while (a[index] < a[index - 1] && index >= 2) {
            swap(&a[index], &a[index - 1]);
            index--;
        }
    }
    assert(isSorted(a, noElements));
    actions sortActions;
    return sortActions;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a < b ? b : a;
}

int getMedian(int a, int b, int c) {
    int minim = min(min(a, b), c);
    int maxim = max(max(a, b), c);
    if (a > minim && a < maxim) return a;
    if (b > minim && b < maxim) return b;
    if (c > minim && c < maxim) return c;
    if (a == b || a == c) return a;
    return b;
}

void quickSortHelper(int *a, int startIndex, int endIndex) {
    if (startIndex + 1 < endIndex) { //at least 3 elements
        int pivot = getMedian(a[startIndex], a[endIndex], a[(startIndex + endIndex) / 2]);
        int i = startIndex;
        int j = endIndex;

        while (i < j) {
            while (a[i] < pivot) i++;
            while (a[j] >= pivot) j--;
            if (i < j) {
                swap(&a[i], &a[j]);
            }
        }
        quickSortHelper(a, startIndex, i - 1);
        quickSortHelper(a, i, endIndex);
    } else { //1 or 2 elements
        if (a[startIndex] > a[endIndex]) {
            swap(&a[startIndex], &a[endIndex]);
        }
    }

}

actions quickSort(int *a, int noElements) {
    actions sortActions;
    quickSortHelper(a, 1, noElements);
    assert(isSorted(a, noElements));
    printArray(a, noElements);
    return sortActions;
}

int getCorrespondentDigit(int n, int digitIndex, int radix) {
    return (n / (int) pow(radix, digitIndex - 1)) % radix;
}

void countingSort_digit(int *a, int noElements, int digitIndex, int radix) {
    //create buckets
    int **groupedByDigits = (int **) malloc(sizeof(int *) * radix);
    int *sizeOfGroups = (int *) malloc(sizeof(int) * radix);
    for (int i = 0; i <= 9; i++) {
        groupedByDigits[i] = (int *) malloc(sizeof(int) * (noElements + 1));
        sizeOfGroups[i] = 0;
    }

    //group numbers by the corresponding digit
    int group;
    for (int i = 1; i <= noElements; i++) {
        group = getCorrespondentDigit(a[i], digitIndex, radix);
        sizeOfGroups[group]++;
        groupedByDigits[group][sizeOfGroups[group]] = a[i];
    }

    //rearrange array
    int index = 1;
    for (int i = 0; i < radix; i++) {
        for (int j = 1; j <= sizeOfGroups[i]; j++) {
            a[index] = groupedByDigits[i][j];
            index++;
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
    int maxNoDigits = 0;
    for (int i = 1; i <= noElements; i++) {
        maxNoDigits = max(maxNoDigits, noDigits(a[i]));
    }

    for (int i = 1; i <= maxNoDigits; i++) {
        countingSort_digit(a, noElements, i, 10);
    }

    assert(isSorted(a, noElements));
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
        //swap
        sortActions->accesses += 3;
        sortActions->assignments += 3;
    } else if (noElements >= index * 2 + 1 && a[index] < a[index * 2 + 1]) {
        swap(&a[index], &a[index * 2 + 1]);
        heapify(a, noElements, index * 2 + 1, sortActions);
        sortActions->comparisons += 2;
        sortActions->accesses += 3;
        sortActions->assignments += 3;
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
        heapActions.accesses += 3;
        heapActions.assignments += 3;
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
        mergeActions->accesses += 3;
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
