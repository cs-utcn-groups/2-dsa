#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define SIZE 5

int main() {
    FILE *input = fopen("../in.txt", "r");
    int **matrix = createEmptyMatrix(SIZE);
    readAdjMatrix(input, matrix, SIZE);
    Graph *graph = createAdjListFromMatrix(matrix, SIZE);
    printGraph(graph);

    List *longestPath = getLongestPath(graph);
    return 0;
}