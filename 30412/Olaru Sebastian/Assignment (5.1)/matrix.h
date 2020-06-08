//
// Created by acer on 4/5/2020.
//

#ifndef ASSIGNMENT__5_1__MATRIX_H
#define ASSIGNMENT__5_1__MATRIX_H

#include "list.h"

int **inputAdjMatrix(FILE *input, int *noOfVertices);
void printAdjMatrix(int **adjMatrix, int noOfVertices);
int **getMatrixFromList(List *pList, int noOfVertices);
int noOfNeighborsOfVertex(List *pList, int indexNode);
int *getAllNeighborsOfVertex(List *pList, int indexNode, int noOfNeighbors);


#endif //ASSIGNMENT__5_1__MATRIX_H
