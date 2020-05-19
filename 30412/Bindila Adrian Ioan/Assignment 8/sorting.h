//
// Created by bindi on 5/9/2020.
//

#ifndef ASSIGNMENT_8_SORTING_H
#define ASSIGNMENT_8_SORTING_H

void swap(int *x, int *y);

int doBubbleSort(int *array, int size, FILE *output);

int doQuickSort(int *array, int size, FILE *output);

int quickSort(int *array, int low, int high);

int doCountingSort(int *array, int size, FILE *output);

#endif //ASSIGNMENT_8_SORTING_H
