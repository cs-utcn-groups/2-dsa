#include <stdio.h>
#include "graphTraversals.h"
#include "graphRepresentation.h"
#include "longestPath.h"


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

    bfs(outputFile, 'G' - 'A', noOfVertices, adjMatrix);

    dfs(outputFile, 'G' - 'A', noOfVertices, adjMatrix);

    dfsRecursive(outputFile, 'G' - 'A', noOfVertices, adjMatrix);

    ListT *adjList = convertMatrixToList(noOfVertices, adjMatrix);
    printAdjList(outputFile, adjList, noOfVertices);

    longestPath(outputFile, adjList, noOfVertices, 'B' - 'A', 'D' - 'A');

    int **adjMatrixFromList = convertListToMatrix(noOfVertices, adjList);
    printAdjMatrix(outputFile, noOfVertices, adjMatrixFromList);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}