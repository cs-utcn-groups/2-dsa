#include <stdio.h>
#include <stdlib.h>
#include "alg.h"

int main() {

    size = 10;

    allocate();
    countingSort(a, size);

    for(int i = 0 ; i < size ; i++)
        printf("%d ", a[i]);

    printf("\n\nComparisions : %d\nAssignments : %d\nArray was accesed : %d\n",comparisions,assignmets,acces);

    return 0;
}