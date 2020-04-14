//
// Created by ileana on 4/14/2020.
//

#ifndef ASSIGNMENT_6_2_EDGE_H

#include "graph.h"

typedef struct edge {
    int source;
    int destination;
} edgeT;

edgeT * getEdges();
int getNrOfEdges();
void deleteIncidentEdges(edgeT * edges, int node,int * nrEdges);

#define ASSIGNMENT_6_2_EDGE_H

#endif //ASSIGNMENT_6_2_EDGE_H
