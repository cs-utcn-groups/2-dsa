//
// Created by diana on 08/05/2020.
//

#include "adj_matrix.h"

void readAdjMatrix(FILE *inputFile, int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            fscanf(inputFile, "%d", &matrix[i][j]);
        }
    }
}

void printAdjMatrix(int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **createEmptyMatrix(int size) {
    int **newMatrix = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; ++i) {
        newMatrix[i] = (int *) malloc(size * sizeof(int));
    }
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            newMatrix[i][j] = 0;
        }
    }
    return newMatrix;
}

int **createMatrixFromList(Graph *graph) {
    int **newMatrix = createEmptyMatrix(graph->nrOfVertices);
    for (int i = 0; i < graph->nrOfVertices; ++i) {
        ListNode *node = graph->vertexArray[i].first;
        while (node != NULL) {
            newMatrix[i][node->value] = 1;
            node = node->next;
        }
    }
    return newMatrix;
}
