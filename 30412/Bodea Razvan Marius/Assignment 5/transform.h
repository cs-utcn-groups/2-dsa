//
// Created by razvi on 4/5/2020.
//

#ifndef ADJACENCY_TRANSFORM_H

#include "list.h"
#include <stdio.h>

List *createListFromMatrix(int noOfVertices, int **adjMatrix);

int **createMatrixFromList(int noOfVertices, List *adjList);

int isInList(int data, List adjList);

#define ADJACENCY_TRANSFORM_H

#endif //ADJACENCY_TRANSFORM_H
