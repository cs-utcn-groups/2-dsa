//
// Created by Alina Mihut on 5/10/20.
//

#ifndef ASSIGNMENT_8_SORTINGALGORITHMS_H
#include <stdio.h>
#include "array.h"

void swap(int *a, int *b);
void bubbleSort ();
void mergeSortRec(int left, int right);
void mergeSort();
void merge(int l, int m, int r);
void radixSort();
void countSort(int exp);
int getMaxNumber();
int actions, comparisons, assignments, arrayAccesses;

void initializeActions();
void printActions();
#define ASSIGNMENT_8_SORTINGALGORITHMS_H

#endif //ASSIGNMENT_8_SORTINGALGORITHMS_H
