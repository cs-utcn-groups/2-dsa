#include "head.h"


int main() {
    FILE *input;
    input = fopen("input.txt", "r");
    int numberOfVertices;
    int **adjMatrix = readAdjMatrix(input, &numberOfVertices);
    printf("\nKruskal algorithm for MST:\n");
    kruskal(adjMatrix, numberOfVertices);
    adjMatrix = readAdjMatrix(input, &numberOfVertices);
    bellmanFord(1 ,adjMatrix, numberOfVertices);
    return 0;
}



