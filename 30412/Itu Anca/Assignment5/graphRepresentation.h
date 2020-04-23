//
// Created by Anca on 4/6/2020.
//

#ifndef ASSIGNMENT5_GRAPHREPRESENTATION_H

#include "graph.h"

void readFromAdjMatrix(FILE *f);

void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);

int *getAllNeighborsOfVertex(int v);

void createListFromMatrix();

void createMatrixFromList();

int getNumberOfNeighborsOfVertexFromList(int v);

int *getAllNeighborsOfVertexFromList(int v);

#define ASSIGNMENT5_GRAPHREPRESENTATION_H

#endif //ASSIGNMENT5_GRAPHREPRESENTATION_H
