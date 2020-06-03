//
// Created by Irina on 18/05/2020.
//

#ifndef ASSIGNMENT5_EDGE_H
#define ASSIGNMENT5_EDGE_H

#include "graph.h"

typedef struct edge {
    int source;
    int destination;
    int weight;
} edgeT;

int nrOfEdges;
edgeT ** allEdges;

int getNumberOfEdges();

edgeT * createEdge(int s, int d, int w);

void getEdges();

void printWeightOfEdges();

void sortEdges();

#endif //ASSIGNMENT5_EDGE_H
