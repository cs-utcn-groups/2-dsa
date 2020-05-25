#include <stdio.h>
#include <stdlib.h>
#include "matri.h"

int **readAdjMatrix(FILE *f, int noOfVertices) {
    int **adjMatrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i < noOfVertices; i++)
        adjMatrix[i] = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        for (int j = 0; j < noOfVertices; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    return adjMatrix;
}

void printAdjMatrix(FILE *fptr, int noOfVertices, int **adjMatrix) {
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++)
            fprintf(fptr, "%d ", adjMatrix[i][j]);
        fprintf(fptr, "\n");
    }
}

int getNoOfNeighbors(int v, int **adjMatrix, int noOfVertices) {
    int noOfNeighbors = 0;
    for (int i = 0; i < noOfVertices; i++)
        if (adjMatrix[v][i] > 0)
            noOfNeighbors++;
    return noOfNeighbors;
}

int *getNeighbors(int v, int **adjMatrix, int noOfVertices) {
    int noOfNeighbors = getNoOfNeighbors(v, adjMatrix, noOfVertices);
    int *neighbors = (int *) malloc(noOfNeighbors * sizeof(int));
    int j = -1;
    for (int i = 0; i < noOfVertices; i++)
        if (adjMatrix[v][i] > 0) {
            neighbors[++j] = i;
        }
    return neighbors;
}