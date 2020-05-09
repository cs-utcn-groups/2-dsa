//
// Created by diana on 09/05/2020.
//

#ifndef EVERYTHING_GRAPHS_ADJ_MATRIX_H
#define EVERYTHING_GRAPHS_ADJ_MATRIX_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _adjMatrix {
    int nrOfVertices;
    int **matrix;
} AdjMatrix;

AdjMatrix *createAdjMatrix(int nrOfVertices);

void readAdjMatrix (AdjMatrix *adjMatrix, struct _iobuf *buffer);

void freeAdjMatrix(AdjMatrix **adjMatrix);

#endif //EVERYTHING_GRAPHS_ADJ_MATRIX_H
