//
// Created by Andreea on 4/7/2020.
//

#ifndef ADJACENCY_LIST_GRAPHTRAVERSALS_H

#include "queue.h"
#include "stack.h"
void bfs(int startNode, int nrOfVertexes, int **adjMatrix);

void dfsRec(int v, int *visited, int nrOfVertexes, int **adjMatrix);

void dfsRecurs(int startNode, int nrOfVertexes, int **adjMatrix);

int getNumberOfNeighborsOfVertex(int v, int nrOfVertexes, int **adjMatrix);

int *getAllNeighborsOfVertex(int v, int nrOfVertexes, int **adjMatrix);

void bfsList(int startNode, int nrOfVertexes, nodeT **adjList);

void dfsRecList(int v, int *visited, nodeT **adjList);

void dfsRecursList(int startNode, int nrOfVertexes, nodeT **adjList);
#define ADJACENCY_LIST_GRAPHTRAVERSALS_H

#endif //ADJACENCY_LIST_GRAPHTRAVERSALS_H
