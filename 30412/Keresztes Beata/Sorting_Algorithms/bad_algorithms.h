//
// Created by q on 5/7/2020.
//

#ifndef SORTING_ALGORITHMS_BAD_ALGORITHMS_H
#define SORTING_ALGORITHMS_BAD_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comparison, assignment,access;

typedef bool comp_fct(int,int);
bool descending(int a, int b);
bool ascending(int a, int b);
void swap(int * a, int * b);

void bubble_sort(int N, int * array,comp_fct compare);

void selection_sort(int N, int * array, comp_fct compare);

void insertion_sort(int N, int * array, comp_fct compare);

#endif //SORTING_ALGORITHMS_BAD_ALGORITHMS_H
