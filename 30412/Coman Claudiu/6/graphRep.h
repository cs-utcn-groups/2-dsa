#ifndef ASSIGNMENT_6_GRAPHREP_H

#include "graph.h"

void readFromAdjMatrix(FILE *f);
void printAdjMatrix();
int getNumberOfNeighborsOfVertex(int v);
int *getAllNeighborsOfVertex(int v);

#define ASSIGNMENT_6_GRAPHREP_H

#endif