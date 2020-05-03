//
// Created by razvi on 4/7/2020.
//

#ifndef CODE_HERE_GRAPHREPRESENTATION_H
#include "graph.h"

void readFromAdjMatrix(FILE *f);
void printAdjMatrix();
int getNumberOfNeighborsOfVertex(int v);
int *getAllNeighborsOfVertex(int v);
void printEdges(FILE *fout, edgeT *edges, int n);
int *initializeArray(int noOfVertices,int value);
edgeT *getEdges(int noOfVertices, int noOfEdges);
#define CODE_HERE_GRAPHREPRESENTATION_H

#endif //CODE_HERE_GRAPHREPRESENTATION_H
