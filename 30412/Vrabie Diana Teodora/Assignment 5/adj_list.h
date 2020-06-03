//
// Created by diana on 08/05/2020.
//

#ifndef ASSIGNMENT_5_ADJ_LIST_H
#define ASSIGNMENT_5_ADJ_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _listNode {
    int value;
    struct _listNode *next;
} ListNode;

typedef struct _adjList {
    ListNode *first;
} AdjList;

typedef struct _graph {
    int nrOfVertices;
    AdjList *vertexArray;
} Graph;

ListNode *newListNode(int value);

Graph *createEmptyGraph(int nrOfVertices);

void addEdge(Graph *graph, int head, int tail);

void printGraph(Graph *graph);

//MAIN PURPOSE
Graph *createAdjListFromMatrix(int **matrix, int size);

#endif //ASSIGNMENT_5_ADJ_LIST_H
