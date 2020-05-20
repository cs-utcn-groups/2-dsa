#include <stdio.h>
#include <stdbool.h>
#include "sortingFunctions.h"

int main() {
    int array[6] = {7, 3, 9, 0, 10, 2}, L = 0, H = 5, N = 6;
    bubbleSort(array, N, false);
    //countingSort(array, N);
    //int q = quickSort(array, L, H);
    //printf("Number of actions for quickSort: %d\n", q);
    printArray(array, N);
}