//
// Created by Anca on 4/27/2020.
//

#ifndef ASSIGNMENT6_GRAPHREPRESENTATION_H

#include "graph.h"

void readFromAdjMatrix(FILE *f);

void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);

int *getAllNeighborsOfVertex(int v);

#define ASSIGNMENT6_GRAPHREPRESENTATION_H

#endif //ASSIGNMENT6_GRAPHREPRESENTATION_H
