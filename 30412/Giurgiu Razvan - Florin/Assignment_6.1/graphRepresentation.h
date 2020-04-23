//
// Created by TheRa on 3/31/2020.
//

#ifndef ASSIGNMENT_5_1_GRAPHREPRESENTATION_H

#include "graph.h"

void readFromAdjMatrix(FILE *f);
void printAdjMatrix();
int getNumberOfNeighborsOfVertex(int v);
int *getAllNeighborsOfVertex(int v);

#define ASSIGNMENT_5_1_GRAPHREPRESENTATION_H

#endif //ASSIGNMENT_5_1_GRAPHREPRESENTATION_H
