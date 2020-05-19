#include <stdio.h>
#include "sorting.h"

void printSortedArray(int * sortedArray);

int main() {
    int array[] = {45, 67, 23, 4, 156, 6872, 11, 19, 35, 1765, 827, 2, 55, 34, 190, 1, 99, 999, 477, 736, 72, 28, 10, 17, 15, 8787, 8, 4000};
    arraySize = sizeof(array) / sizeof(array[0]);
    int * sortedArray;

    sortedArray = bubbleSort(array);
    printf("Array after Bubble Sort:\n");
    printSortedArray(sortedArray);

    sortedArray = quickSort(array);
    printf("Array after Quick Sort:\n");
    printSortedArray(sortedArray);

    sortedArray = radixSort(array);
    printf("Array after Radix Sort:\n");
    printSortedArray(sortedArray);

    return 0;
}

void printSortedArray(int * sortedArray) {
    for(int i = 0; i < arraySize - 1; i++) {
        printf("%d, ",sortedArray[i]);
    }
    printf("%d\n\n",sortedArray[arraySize - 1]);
}
