//
// Created by andre on 06.05.2020.
//

#include <stdlib.h>
#include "graphRepresentation.h"

int **createMatrix(int noOfVertices) {
    int **adjMatrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i < noOfVertices; i++) {
        adjMatrix[i] = (int *) malloc(noOfVertices * sizeof(int));
    }
    return adjMatrix;
}

void initializeMatrix(int n, int **adjMatrix) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
}

int getNumberOfVertices(FILE *inputFile) {
    int noOfVertices;
    fscanf(inputFile, "%d", &noOfVertices);
    return noOfVertices;
}

int **getAdjMatrix(FILE *inputFile, int noOfVertices) {
    int **adjMatrix = createMatrix(noOfVertices);
    for (int i = 0; i < noOfVertices; i++)
        for (int j = 0; j < noOfVertices; j++)
            fscanf(inputFile, "%d", &adjMatrix[i][j]);
    return adjMatrix;

}

void printAdjMatrix(FILE *outputFile, int noOfVertices, int **adjMatrix) {
    fprintf(outputFile, "The adjacency matrix is:\n     ");
    for (int i = 0; i < noOfVertices; i++) {
        fprintf(outputFile, "%c    ", 'A' + i);
    }
    fprintf(outputFile, "\n");
    for (int i = 0; i < noOfVertices; i++) {
        fprintf(outputFile, "%c  ", 'A' + i);
        for (int j = 0; j < noOfVertices; j++)
            fprintf(outputFile, "%3d  ", adjMatrix[i][j]);
        fprintf(outputFile, "\n");
    }
    fprintf(outputFile, "\n");
}

int getNumberOfNeighboursOfVertex(int noOfVertices, int **adjMatrix, int v) {
    if (v < noOfVertices) {
        int nrOfNeighbors = 0;
        int i;
        for (i = 0; i < noOfVertices; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    } else {
        return 0;
    }
}

int *getAllNeighboursOfVertex(int noOfVertices, int **adjMatrix, int v) {
    if (v < noOfVertices) {
        int nrOfNeighbors = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, v);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int i, j = 0;
        for (i = 0; i < noOfVertices; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                neighbors[j] = i;
                j++;
            }
        }
        return neighbors;
    } else {
        return NULL;
    }
}

void freeAdjMatrix(int noOfVertices, int **adjMatrix) {
    for (int i = 0; i < noOfVertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

ListT *convertMatrixToList(int noOfVertices, int **adjMatrix) {
    ListT *adjList = createAdjList(noOfVertices);
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (adjMatrix[i][j]) {
                addLast(&adjList[i], i, j, adjMatrix[i][j]);
            }
        }
    }
    freeAdjMatrix(noOfVertices, adjMatrix);
    return adjList;
}


int **convertListToMatrix(int noOfVertices, ListT *adjList) {
    int **adjMatrix = createMatrix(noOfVertices);
    initializeMatrix(noOfVertices, adjMatrix);
    for (int i = 0; i < noOfVertices; i++) {
        NodeL *currentElement = adjList[i].first;
        for (int j = 0; j < noOfVertices && currentElement != NULL; j++) {
            if (j == currentElement->destination) {
                adjMatrix[i][j] = currentElement->weight;
                currentElement = currentElement->next;
            } else {
                adjMatrix[i][j] = 0;
            }
        }
    }
    free(adjList);
    return adjMatrix;
}

