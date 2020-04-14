//
// Created by Alina Mihut on 4/12/20.
//

#ifndef ASSIGNMENT_6_1_GRAPHREPRESENTATION_H
#include "graph.h"

void readFromAdjMatrix(FILE *f);

void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);

int *getAllNeighborsOfVertex(int v);

#define ASSIGNMENT_6_1_GRAPHREPRESENTATION_H

#endif //ASSIGNMENT_6_1_GRAPHREPRESENTATION_H
