//
// Created by acer on 4/2/2020.
//

#ifndef ASSIGNMENT__8_1__SORTINGALGO_H
#define ASSIGNMENT__8_1__SORTINGALGO_H

#include <stdio.h>
#include <stdlib.h>

int comp, assign, access;

void selectionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void countSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
void printArray(FILE *f, int arr[], int size);
void initializeArray(int arr[], int n, int seed);

#endif //ASSIGNMENT__8_1__SORTINGALGO_H
