//
// Created by diana on 08/05/2020.
//

#ifndef ASSIGNMENT_5_EXTRA_GRAPH_H
#define ASSIGNMENT_5_EXTRA_GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;
} Node;

typedef struct _list {
    Node *first;
} List;

typedef struct _graph {
    int nrOfVertices;
    List *vertexArray;
} Graph;

void printGraph(Graph *graph);

Graph *createAdjListFromMatrix(int **matrix, int size);

void readAdjMatrix(FILE *inputFile, int **matrix, int size);

int **createEmptyMatrix(int size);

// TASK
List *getLongestPath(Graph *graph);


#endif //ASSIGNMENT_5_EXTRA_GRAPH_H
