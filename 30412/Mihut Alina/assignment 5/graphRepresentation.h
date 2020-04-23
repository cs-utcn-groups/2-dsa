//
// Created by Alina Mihut on 4/5/20.
//

#ifndef ASSIGNMENT_5_GRAPHREPRESENTATION_H
#define ASSIGNMENT_5_GRAPHREPRESENTATION_H
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
void readFromAdjMatrix(FILE *f);
int getNumberOfNeighborsOfVertex(int v);
int *getAllNeighborsOfVertex(int v);
#endif //ASSIGNMENT_5_GRAPHREPRESENTATION_H
