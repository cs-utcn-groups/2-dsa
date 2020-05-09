//
// Created by diana on 09/05/2020.
//

#include "adj-matrix.h"

AdjMatrix *createAdjMatrix(int nrOfVertices) {
    AdjMatrix *newMatrix = (AdjMatrix*) malloc(sizeof(AdjMatrix));
    newMatrix->nrOfVertices = nrOfVertices;
    newMatrix->matrix = (int**) malloc(nrOfVertices* sizeof(int*));
    for (int i = 0; i < nrOfVertices; ++i) {
        newMatrix->matrix[i] = (int*) malloc(nrOfVertices* sizeof(int));
    }
    return newMatrix;
}

void freeAdjMatrix(AdjMatrix **adjMatrix) {
    for (int i = 0; i < (*adjMatrix)->nrOfVertices; ++i) {
        free((*adjMatrix)->matrix[i]);
    }
    free((*adjMatrix)->matrix);
    free(*adjMatrix);
}

void readAdjMatrix(AdjMatrix *adjMatrix, struct _iobuf *buffer) {
    for (int i = 0; i < adjMatrix->nrOfVertices; ++i) {
        for (int j = 0; j < adjMatrix->nrOfVertices; ++j) {
            fscanf(buffer, "%d", &adjMatrix->matrix[i][j]);
        }
    }
}
