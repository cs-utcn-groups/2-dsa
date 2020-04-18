//
// Created by bindi on 4/7/2020.
//

#ifndef ASSIGNMENT_6_1_GRAPH_H
#define ASSIGNMENT_6_1_GRAPH_H

#include "edge.h"

typedef struct _graph {
    int noOfVertices;
    int noOfEdges;
    edge **edges;
} graph;

graph *readGraph(FILE *input);

#endif //ASSIGNMENT_6_1_GRAPH_H
