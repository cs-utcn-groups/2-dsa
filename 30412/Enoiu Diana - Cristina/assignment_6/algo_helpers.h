//
// Created by Diana on 05/05/2020.
//

#ifndef GRAPH_ALGORITHMS_ALGO_HELPERS_H

#include "edge.h"

edgeT getMinimumEdgeForCurrentVisitedNodes(const int *visited);
void printEdges(edgeT *edges, int n);
int getMinDistanceVertex (const int *distances, const int *visited);
int getNoOfEdges();
edgeT * getEdges (int noOfEdges);
edgeT * sortEdges (edgeT * edges, int noOfEdges);
int find(int *belongs, int vertex);
void matchVertices(int vertex1, int vertex2,int * belongs);
#define GRAPH_ALGORITHMS_ALGO_HELPERS_H

#endif //GRAPH_ALGORITHMS_ALGO_HELPERS_H
