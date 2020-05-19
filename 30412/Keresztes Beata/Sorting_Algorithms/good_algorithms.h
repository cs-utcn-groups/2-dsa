//
// Created by q on 5/7/2020.
//

#ifndef SORTING_ALGORITHMS_GOOD_ALGORITHMS_H
#define SORTING_ALGORITHMS_GOOD_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bad_algorithms.h"

void merge_sort(int * array, int left, int right);

void merge(int * array, int left, int middle, int right);

void quick_sort(int * array, int left, int right);

int partition_middle(int * array, int left, int right);

int partition_last(int * array, int left, int right);

#endif //SORTING_ALGORITHMS_GOOD_ALGORITHMS_H
