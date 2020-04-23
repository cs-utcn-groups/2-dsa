//
// Created by csatl on 4/5/2020.
//

#ifndef A5_GRAPHREPRESENTATION_H
#include "graph.h"

void readFromAdjMatrix(FILE *f);

void readFromList(FILE *f);

void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);

int *getAllNeighborsOfVertex(int v);


#define A5_GRAPHREPRESENTATION_H

#endif //A5_GRAPHREPRESENTATION_H
