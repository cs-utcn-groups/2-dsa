#ifndef GRAPH_TRAVERSALS_LIST_H
#include "graph.h"
typedef struct listNode
{
    char letter;
    int content;
    struct listNode *next;
}nodeL;
typedef struct listType
{
    struct listNode *first;
    struct listNode *last;
}listT;
listT *adjList;

void initializeListArray();
void matrixToList();
void listToMatrix();
void printAdjList();
#define GRAPH_TRAVERSALS_LIST_H
#endif // GRAPH_TRAVERSALS_LIST_H
