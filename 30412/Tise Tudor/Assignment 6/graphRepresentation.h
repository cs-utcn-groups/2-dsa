//
// Created by Alex on 3/31/2020.
//

#ifndef GRAPHS___TRAVERSALS_GRAPHREPRESENTATION_H

#include "graph.h"

void readFromAdjMatrix(FILE *f);

void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);

int *initArray(int noOfVertices,int value);

int *getAllNeighborsOfVertex(int v);

edgeT *getEdges(int noOfVertices, int noOfEdges);

#define GRAPHS___TRAVERSALS_GRAPHREPRESENTATION_H

#endif //GRAPHS___TRAVERSALS_GRAPHREPRESENTATION_H
