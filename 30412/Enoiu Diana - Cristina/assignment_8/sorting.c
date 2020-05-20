//
// Created by Diana on 10/05/2020.
//
#include <stdio.h>
#include "sorting.h"
void swap(int * element1,int * element2) {
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;

    noOfAssignments+=2; //assignments when swap
    noOfAccesses+=2;//access when swap
}
int * bubbleSort (int * array) {
    noOfComparisons = 0; noOfAssignments = 0; noOfAccesses = 0;

    int * sortedArray = array;
    for(int i = 0; i < arraySize-1; i++) {
        for(int j = 0; j< arraySize-i-1; j++) {
            if (sortedArray[j] > sortedArray[j+1]) {
                swap(&(*(sortedArray + j)),&(*(sortedArray +j +1)));
            }
            noOfComparisons++; // for each time i compare the elements with if
            noOfAccesses+=2; //access when comparing
        }
    }
    printf("---For BubbleSort---\n"
           "No of comparisons:%d\n"
           "No of assignments:%d\n"
           "No of accesses:%d\n"
           "Total actions:%d\n\n",noOfComparisons,noOfAssignments,noOfAccesses,noOfAccesses+noOfComparisons+noOfAssignments);
    return sortedArray;
}
int medianOfThree(int *arr, int low, int high) {
    int mid = (low + high) / 2;
    if (arr[high] < arr[low]) {
        swap(&arr[high], &arr[low]);
    }
    if (arr[mid] < arr[low]) {
        swap(&arr[mid], &arr[low]);
    }
    if (arr[high] < arr[mid]) {
        swap(&arr[high], &arr[mid]);
    }
    noOfComparisons +=3;
    swap(&arr[mid], &arr[high]);
    return arr[high];
}
int partition (int *arr, int low, int high) {
    int pivot = medianOfThree(arr,low,high); //choosing the median of three elements as a pivot
    noOfAccesses++;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if(arr[j]<pivot) {
            i++;
            swap(&(*(arr + i)),&(*(arr + j)));
        }
        noOfComparisons++;
        noOfAccesses++;//access when comparing
    }
    swap(&(*(arr + i+1)),&(*(arr + high)));
    return (i + 1);
}

void quickSortRec(int *arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr,low,high);
        quickSortRec(arr, low, pi - 1);
        quickSortRec(arr, pi + 1, high);
    }
}

int * quickSort(int * array) {
    noOfComparisons = 0; noOfAssignments = 0; noOfAccesses = 0;
    int * sortedArray = array;

    quickSortRec(sortedArray,0,arraySize-1);
    printf("---For QuickSort---\n"
           "No of comparisons:%d\n"
           "No of assignments:%d\n"
           "No of accesses:%d\n"
           "Total actions:%d\n\n",noOfComparisons,noOfAssignments,noOfAccesses,noOfAccesses+noOfComparisons+noOfAssignments);
    return sortedArray;
}
int getMax(int *arr) {
    int mx = arr[0];
    noOfAccesses++;

    for (int i = 1; i < arraySize; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
        noOfComparisons++;
        noOfAccesses++;
    }
    return mx;
}
void countSort(int *arr, int exp) {
    int output[arraySize];
    int i, count[10] = {0};

    for (i = 0; i < arraySize; i++) {
        count[(arr[i] / exp) % 10]++;
        noOfAccesses++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = arraySize - 1; i >= 0; i--) {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
        noOfAccesses +=2;
    }

    for (i = 0; i < arraySize; i++) {
        arr[i] = output[i];
        noOfAssignments++;
    }
}
int * radixSort(int *arr) {
    noOfComparisons = 0; noOfAssignments = 0; noOfAccesses = 0;
    int m = getMax(arr);

    for (int exp = 1; m/exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
    printf("---For RadixSort---\n"
           "No of comparisons:%d\n"
           "No of assignments:%d\n"
           "No of accesses:%d\n"
           "Total actions:%d\n\n",noOfComparisons,noOfAssignments,noOfAccesses,noOfAccesses+noOfComparisons+noOfAssignments);
    return arr;
}