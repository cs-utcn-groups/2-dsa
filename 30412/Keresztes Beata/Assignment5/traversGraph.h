//
// Created by q on 4/2/2020.
//

#ifndef ASSIGNMENT5_TRAVERSGRAPH_H
#define ASSIGNMENT5_TRAVERSGRAPH_H

#include "list.h"
#include "stack.h"
#include "queue.h"
#define VISITED 1
#define UNVISITED 0

// iterative BFS
void BFS(int N, ListT * AL, int startNode);
// iterative DFS
void DFS(int N, ListT * AL, int startNode);
// recursive DFS
void DFSRec(int N, ListT * AL, int startNode);
// auxiliary recursive function for DFS
void auxRec(int node, ListT * AL, int * v);
// create visited array
int * createVisitedArray(int N);
// function which returns an array of neighbours of a node
int * getNeighbours(ListT list);

#endif //ASSIGNMENT5_TRAVERSGRAPH_H
