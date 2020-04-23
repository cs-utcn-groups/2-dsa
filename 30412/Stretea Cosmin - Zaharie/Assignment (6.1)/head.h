//
// Created by Cosmin on 09-Apr-20.
//

#ifndef ASSIGNMENT__6_1__HEAD_H
#define ASSIGNMENT__6_1__HEAD_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 999999999
#define VISITED 1
#define UNVISITED 0

typedef struct edge {
    int source;
    int destination;
    int weight;
} edgeT;

typedef struct _list{
    edgeT *first, *last;
}List;

void bellmanVolkswagen(int start, int **adjMatrix, int noOfVertices);

edgeT *getAllDirectedEdges(int **adjMatrix, int noOfVertices);

int getNoOfDirectedEdges(int **adjMatrix, int noOfVertices);

void kruskal(int **adjMatrix, int noOfVertices);

edgeT *getAllEdgesSorted(int **adjMatrix, int noOfVertices);

int getNoOfEdges(int **adjMatrix, int noOfVertices);

int validEdge(int *visited, edgeT edge);

int allVerticesVisited(int *visited, int noOfVertices);

int **readAdjMatrix(FILE *input, int *numberOfVertices);

void printMatrix(int **adjMatrix, int numberOfVertices);


#endif //ASSIGNMENT__6_1__HEAD_H
