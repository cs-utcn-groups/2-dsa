#include <stdio.h>
#include "graphAlgorithms.h"


#define INPUT_FILE_PATH "../input.dat"
#define OUTPUT_FILE_PATH "../output.dat"

int main() {
    FILE *inputFile;
    inputFile = fopen(INPUT_FILE_PATH, "r");
    if (inputFile == NULL) {
        perror("Error opening file.");
        return (-1);
    }

    FILE *outputFile;
    outputFile = fopen(OUTPUT_FILE_PATH, "w");

    int noOfVertices = getNumberOfVertices(inputFile);
    int **adjMatrix = getAdjMatrix(inputFile, noOfVertices);
    printAdjMatrix(outputFile, noOfVertices, adjMatrix);

    prim(outputFile, 'E' - 'A', noOfVertices, adjMatrix);
    dijkstra(outputFile, 'E' - 'A', noOfVertices, adjMatrix);
    kruskal(outputFile, noOfVertices, adjMatrix);
    bellmanFord(outputFile, 'E' - 'A', noOfVertices, adjMatrix);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
