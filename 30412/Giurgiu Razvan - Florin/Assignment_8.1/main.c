#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

int main() {

    size = 10;

    allocate();
    //insertionSort(a, size);
    //quicksort(a, 0, size-1);
    countingSort(a, size);

    for(int i = 0 ; i < size ; i++)
        printf("%d ", a[i]);

    printf("\n\nComparisions : %d\nAssignments : %d\nArray was accesed : %d\n",comparisions,assignmets,acces);

    return 0;
}