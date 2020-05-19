//
// Created by andre on 06.05.2020.
//

#ifndef ASSIGNMENT5_GRAPHTRAVERSALS_H
#define ASSIGNMENT5_GRAPHTRAVERSALS_H

#include "graph.h"

void bfs(FILE *outputFile, int startNode, int noOfVertices, int **adjMatrix);

void dfs(FILE *outputFile, int startNode, int noOfVertices, int **adjMatrix);

void dfsRec(FILE *outputFile, int v, int *visited, int noOfVertices, int **adjMatrix);

void dfsRecursive(FILE *outputFile, int startNode, int noOfVertices, int **adjMatrix);

int *initializeArray(int noOfVertices, int value);

#endif //ASSIGNMENT5_GRAPHTRAVERSALS_H
