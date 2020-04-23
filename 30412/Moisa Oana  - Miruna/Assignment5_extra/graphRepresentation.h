//
// Created by User on 06.04.2020.
//

#ifndef ASSIGNMENT5_EXTRA_GRAPHREPRESENTATION_H

#include "graph.h"
void readFromAdjMatrix(FILE *f);
void printMatrix(int **matrix);
int getNumberOfNeighborsOfVertex(int v);
int *getAllNeighborsOfVertex(int v);
void dfsRecurs(int startNode, int destination);
#define ASSIGNMENT5_EXTRA_GRAPHREPRESENTATION_H

#endif //ASSIGNMENT5_EXTRA_GRAPHREPRESENTATION_H
