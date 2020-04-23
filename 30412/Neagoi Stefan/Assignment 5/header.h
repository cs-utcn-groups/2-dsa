//
// Created by Stefan on 07/04/2020.
//

#ifndef ASSIGNMENT_5_HEADER_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _subset{
    int parent;
    int rank;
}SubsetT;
typedef struct _node {
    int length;
    int dest;
    int source;
    struct _node* next;
} NodeT;
typedef struct _adjList {
    struct _node *head;
} AdjListT;
typedef struct _graph {
    int noVertices, noEdges;
    struct _adjList* array;
    struct _node* edge;
} GraphT;

int edgeIndex;
int noOfVertices;
int **adjMatrix;
void readAdjMatrix(FILE *f);
void printAdjMatrix();
int getNoOfNeighboursOfVertices;
int *getAllNeighboursOfVertices;
NodeT *createNewNode(int dest, int length);
GraphT *createNewGraph(int V);
void addEdge(GraphT* graph, int src, int data, int length);
void printGraph(GraphT* graph);
GraphT* getGraphFromMatrix();
int find(SubsetT subsets[], int i);
void Union(SubsetT subsets[], int x, int y);
int getNoEdges();
int compareEdges(const void* a, const void* b);
void KruskalMST (GraphT *graph);
void sortEdges(GraphT* graph);
void printEdges(GraphT *graph);
void printArr(int dist[], int n);
void BellmanFord(GraphT* graph, int src);

#define ASSIGNMENT_5_HEADER_H

#endif //ASSIGNMENT_5_HEADER_H
