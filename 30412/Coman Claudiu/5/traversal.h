#ifndef ADJACENCY_TRAVERSAL_H

#include <stdio.h>
#include "matrix.h"
#include "list.h"

void BFS(FILE *fptr, int startNode, int noOfVertices, int **adjMatrix);

void recDFS(FILE *fptr, int *visited, int v, int **adjMatrix, int noOfVertices);

void DFS(FILE *fptr, int startNode, int noOfVertices, int **adjMatrix);

void BFSonList(FILE *fptr, int startNode, int noOfVertices, List *adjList);

void recDFSonList(FILE *fptr, int *visited, int v, List *adjList);

void DFSonList(FILE *fptr, int startNode, int noOfVertices, List *adjList);

#define ADJACENCY_TRAVERSAL_H

#endif