#include <stdio.h>
#include "adj_matrix.h"
#include "adj_list.h"

#define PATH "../in.txt"

FILE *inputFile;

int main() {
    inputFile = fopen(PATH, "r");
    int **adjMatrix = createEmptyMatrix(5);
    readAdjMatrix(inputFile, adjMatrix, 5);
    printAdjMatrix(adjMatrix, 5);

    Graph *mGraph = createAdjListFromMatrix(adjMatrix, 5);
    printGraph(mGraph);

    int **newMatrix = createMatrixFromList(mGraph);
    printAdjMatrix(newMatrix, 5);

    return 0;
}