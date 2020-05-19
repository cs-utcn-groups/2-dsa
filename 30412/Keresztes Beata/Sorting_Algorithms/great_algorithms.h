//
// Created by q on 5/7/2020.
//

#ifndef SORTING_ALGORITHMS_GREAT_ALGORITHMS_H
#define SORTING_ALGORITHMS_GREAT_ALGORITHMS_H

#include "good_algorithms.h"
#include <math.h>

void radix_sort(int N, int * array);

void sort_by_digit(int N, int div, int * array);

int findGreatestNumber(int N, int * array);

int getNumberOfDigits(int N);

int getMaxNumber(int N);

void counting_sort(int N, int * array);

#endif //SORTING_ALGORITHMS_GREAT_ALGORITHMS_H
