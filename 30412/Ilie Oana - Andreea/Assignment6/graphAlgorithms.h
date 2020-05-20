//
// Created by andre on 06.05.2020.
//

#ifndef ASSIGNMENT6_GRAPHALGORITHMS_H
#define ASSIGNMENT6_GRAPHALGORITHMS_H

#include "node.h"
#include "graphRepresentation.h"
#include "edge.h"

#define UNDEFINED -1
#define MAX_LIMIT 9999

void prim(FILE *output, int startNode, int noOfVertices, int **adjMatrix);

edgeT getMinEdgeForCurrentlyVisitedNodes(const int *visited, int noOfVertices, int **adjMatrix);

void printEdges(FILE *output, edgeT *edges, int n);


void dijkstra(FILE *output, int startNode, int noOfVertices, int **adjMatrix);

int getMinDistanceVertex(int noOfVertices, const int *distances, const int *visited);


void kruskal(FILE *outputFile, int noOfVertices, int **adjMatrix);

int *initializeParentArray(int noOfVertices);

int getParent(const int *parent, int vertex);

edgeT getMinimumEdgeForAdjMatrix(int noOfVertices, int **adjMat, int *parent);

void unite(int *parent, int i, int j);

int **getCopyOfAdjacencyMatrix(int noOfVertices, int **adjMatrix);

void bellmanFord(FILE *output, int startNode, int noOfVertices, int **adjMatrix);

int getNoOfEdges(int noOfVertices, int **adjMatrix);

edgeT *getEdges(int noOfVertices, int **adjMatrix, int noOfEdges);

int checkNegativeCycles(const int *distances, int noOfEdges, edgeT *edges);

void printShortestPath(FILE *output, int noOfVertices, int startNode, const int *previous, const int *distances);

int *initializeArray(int noOfVertices, int value);



#endif //ASSIGNMENT6_GRAPHALGORITHMS_H
