//
// Created by csatl on 4/8/2020.
//

#ifndef A6_GRAPHREPRESENTATION_H
#include "graph.h"

void readFromListOfWeightedGraph(FILE *f);

void printEdges();

void readFromAdjMatrix(FILE *f);

void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);

int *getAllNeighborsOfVertex(int v);

void sortEdgeByWeight(edgeT* edge);

#define A6_GRAPHREPRESENTATION_H

#endif //A6_GRAPHREPRESENTATION_H
