#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int main() {
    FILE *output = fopen("../output.txt", "w");
    int (*sortingFunction[])(int *, int, FILE *) ={doBubbleSort, doQuickSort, doCountingSort};
    for (int i = 0; i < 3; ++i) {
        int actions = 0;
        ///read Array
        FILE *input = fopen("../input.txt", "r");
        int size = 0;
        fscanf(input, "%d", &size);
        int *array = malloc(size * sizeof(int));
        for (int j = 0; j < size; ++j) {
            fscanf(input, "%d", &array[j]);
        }
        ///sort
        actions = sortingFunction[i](array, size, output);

        switch (i) {
            case 0: {
                fprintf(output, "Bubble Sort took %d actions\n", actions);
                break;
            }
            case 1: {
                fprintf(output, "Quick Sort took %d actions\n", actions);
                break;
            }
            case 2: {
                fprintf(output, "Counting Sort took %d actions\n", actions);
                break;
            }
        }
    }
    fclose(output);
    return 0;
}
