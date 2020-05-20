//
// Created by Tudor Tise on 11/05/2020.
//

#ifndef ASSIGNMENT_8___SORTING_SORTING_H
#define ASSIGNMENT_8___SORTING_SORTING_H

#include "stdio.h"

int quickSortComparisons, quickSortAssignements, quickSortAccesToArray;
int radixComparisons, radixAssignements, radixAccesToArray;



void printArray(int array[], int lastIndex);

void swap(int *x, int *y);

void bubbleSort(int array[], int lastIndex);

int partition (int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

int findMax(int arr[], int n);

void countSort(int arr[], int n, int exp);

void radixSort(int arr[], int n);




#endif //ASSIGNMENT_8___SORTING_SORTING_H
