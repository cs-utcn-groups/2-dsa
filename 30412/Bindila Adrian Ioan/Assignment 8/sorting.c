//
// Created by bindi on 5/9/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "sorting.h"

void swap(int *x, int *y) {
    ///3 assignments required to make a swap
    int aux = *x;
    *x = *y;
    *y = aux;
}

int doBubbleSort(int *array, int size, FILE *output) {
    int actions=0;
    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                ///comparison +1
                ///accessing array[i] and array[i+1] +2
                ///swapping requires 3 assignments +3
                actions+=6;
                swap(&array[i], &array[i + 1]);
                sorted = 0;
            } else{
                ///comparison +1
                ///accessing array[i] and array[i+1] +2
                actions+=3;
            }
        }
    } while (sorted == 0);

    ///print the results
    for (int k = 0; k < size; ++k) {
        fprintf(output, "%d ", array[k]);
    }
    fprintf(output, "\n");
    return actions;
}

int doQuickSort(int *array, int size, FILE *output) {
    int actions=quickSort(array, 0, size - 1);
    ///print the array
    for (int k = 0; k < size; ++k) {
        fprintf(output, "%d ", array[k]);
    }
    fprintf(output, "\n");
    return actions;
}

int quickSort(int *array, int low, int high) {
    int actions=0;
    if (low < high) {///comparison +1

        ///partitioning
        int pivot = array[high];
        int i = low;
        ///assignments +2
        for (int j = low; j < high; ++j) {
            if (array[j] < pivot) {///access, comparison +2
                swap(&array[i], &array[j]);///swap +3
                i++;
            }
        }
        swap(&array[i], &array[high]);///swap +3
        int partitionIndex = i;///assignment +1
        actions+=12;
        actions+=quickSort(array, low, partitionIndex - 1);
        actions+=quickSort(array, partitionIndex + 1, high);
    }
    return actions;
}

int doCountingSort(int *array, int size, FILE *output) {
    int actions=0;
    int max = 0;
    for (int i = 0; i < size; ++i) {
        ///determine range
        if (array[i] > max) {
            actions+=3;///comparison+access+assignment
            max = array[i];
        } else{
            actions+=2;///comparison+access
        }
    }

    int *freqArray = calloc((max+2) , sizeof(int));
    for (int j = 0; j < size; ++j) {
        freqArray[array[j]]++;
        actions+=2;///assignment+access
    }
    int index=0;
    for (int k = 0; k <= max; ++k) {
        while (freqArray[k]>0) {
            array[index++]=k;
            k++;
            freqArray[k]--;
            actions+=6;
        }
    }
    for (int k = 0; k < size; ++k) {
        fprintf(output, "%d ", array[k]);
    }
    fprintf(output, "\n");
    return actions;
}
