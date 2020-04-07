//
// Created by Stefan on 07/04/2020.
//

#ifndef ASSIGNMENT_5_HEADER_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _node {
    int length;
    int dest;
    struct _node* next;
} NodeT;
typedef struct _adjList {
    struct _node *head;
} AdjListT;
typedef struct _graph {
    int noVertices;
    struct _adjList* array;
} GraphT;

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
#define ASSIGNMENT_5_HEADER_H

#endif //ASSIGNMENT_5_HEADER_H
