//
// Created by User on 04.04.2020.
//

#ifndef LAB5_GRAPHREPRESENTATION_H
#include "graph.h"
void readFromAdjMatrix(FILE *f);
void printMatrix(int **matrix);
int getNumberOfNeighborsOfVertex(int v);
int *getAllNeighborsOfVertex(int v);
void matrixToList();
void listToMatrix();
void initializeMatrix();
int getNumberOfNeighborsOfVertexfromList(int v);
int * getAllNeighborsOfVertexFromList(int v);

#define LAB5_GRAPHREPRESENTATION_H


#endif //LAB5_GRAPHREPRESENTATION_H
