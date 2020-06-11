//
// Created by Alex on 3/31/2020.
//

#ifndef GRAPHS___TRAVERSALS_GRAPHREPRESENTATION_H

#include "graph.h"

void readFromAdjMatrix(FILE *f);

void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);

int *getAllNeighborsOfVertex(int v);


#define GRAPHS___TRAVERSALS_GRAPHREPRESENTATION_H

#endif //GRAPHS___TRAVERSALS_GRAPHREPRESENTATION_H
