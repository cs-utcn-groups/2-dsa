//
// Created by q on 4/10/2020.
//

#ifndef ASSIGNMENT5_GRAPHALGORITHMS_H
#define ASSIGNMENT5_GRAPHALGORITHMS_H


#include "matrix.h"
#include "node.h"
#include "traversGraph.h"
#include "edge.h"
#define UNDEFINED -1
#define MAX_LIMIT 9999

/*
 * kruskal
 */
void kruskal(int N, int ** A);
// find parent of node
int findParent(int * parents, int node);
// create array of parents
int * createParentArray(int M);
// unite two components
void unite(int *parents, EdgeT edge);
// find min edge which doesn't close a cycle
EdgeT findMinEdge(int N, int ** A, int * parents);
/*
 * bellman-ford
 */
//bellman
void bellmanFord(int N, int ** A, int start);
// create array
int * createAndInitializeArray(int N, int init);
// print array pf distances
void printDistances(int N, int * distances);
// print the shortest distance path
void printPath(int i, int * previous);
// get the number of edges
int getNoOfEdges(int N, int ** A);
// create array of edges
EdgeT * getAllEdges(int N, int ** A, int noOfEdges);
// function to detect if there are any negative cycles
int detectNegativeCycle(int M,EdgeT * edges, int * distances);

#endif //ASSIGNMENT5_GRAPHALGORITHMS_H
