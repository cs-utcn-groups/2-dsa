//
// Created by bindi on 4/6/2020.
//

#ifndef ASSIGNMENT_5_2___EXTRA_GRAPH_H
#define ASSIGNMENT_5_2___EXTRA_GRAPH_H

#include "vertex.h"

#define UNVISITED 0
#define VISITED 1
typedef struct _graph {
    int noOfVertices;
    vertex **vertices;
} graph;

graph *createGraph(FILE *input);

#endif //ASSIGNMENT_5_2___EXTRA_GRAPH_H
