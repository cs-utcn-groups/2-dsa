//
// Created by Irina on 18/05/2020.
//

#ifndef ASSIGNMENT5_GRAPH_H
#define ASSIGNMENT5_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "queue.h"
#include "edge.h"

#define UNVISITED 0
#define VISITED 1

typedef struct graph{
    int nrOfVertexes;
    int nrOfEdges;
    struct edge ** edges;
} Graph;

int **adjMatrix;
int **adjMatrixFromList;
int nrOfVertexes;

Graph * createGraph();

#endif //ASSIGNMENT5_GRAPH_H
