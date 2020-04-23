//
// Created by razvi on 4/5/2020.
//

#ifndef ADJACENCY_MATRIX_H

#define UNVISITED 0
#define VISITED 1

int **readAdjMatrix(FILE *f, int noOfVertices);

void printAdjMatrix(FILE *fptr, int noOfVertices, int **adjMatrix);

int getNoOfNeighbors(int v, int **adjMatrix, int noOfVertices);

int *getNeighbors(int v, int **adjMatrix, int noOfVertices);

#define ADJACENCY_MATRIX_H

#endif //ADJACENCY_MATRIX_H
