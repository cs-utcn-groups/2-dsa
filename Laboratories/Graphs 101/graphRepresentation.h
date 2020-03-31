//
// Created by Alex on 3/30/2020.
//

#ifndef GRAPHS_101_GRAPHREPRESENTATION_H

#include "graph.h"

void readFromAdjMatrix(FILE *f);

void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);

int *getAllNeighborsOfVertex(int v);

#define GRAPHS_101_GRAPHREPRESENTATION_H

#endif //GRAPHS_101_GRAPHREPRESENTATION_H

