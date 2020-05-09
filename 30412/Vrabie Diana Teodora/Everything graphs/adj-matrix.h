//
// Created by diana on 09/05/2020.
//

#ifndef EVERYTHING_GRAPHS_ADJ_MATRIX_H
#define EVERYTHING_GRAPHS_ADJ_MATRIX_H

#include <stdlib.h>
#include <stdio.h>

/*
 * Convention
 * Weight 0     -> no edge between node i and node j
 * Weight 1     -> unweighted graph
 * Weight >= 1  -> weighted graph
 *
 *
 */

typedef struct _adjMatrix {
    int nrOfVertices;
    int **matrix;
} AdjMatrix;

AdjMatrix *createAdjMatrix(int nrOfVertices);

void readAdjMatrix (AdjMatrix *adjMatrix, struct _iobuf *buffer);

void addEdgeToMatrix (AdjMatrix *adjMatrix, int source, int dest, int weight);

void freeAdjMatrix(AdjMatrix **adjMatrix);

void printAdjMatrix (AdjMatrix *adjMatrix, struct _iobuf *buffer);

#endif //EVERYTHING_GRAPHS_ADJ_MATRIX_H
