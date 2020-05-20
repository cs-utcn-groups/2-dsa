//
// Created by andre on 06.05.2020.
//

#ifndef ASSIGNMENT5_LIST_H
#define ASSIGNMENT5_LIST_H

#include "node.h"

typedef struct nodeList {
    int start, destination, weight;
    int *neighbours;
    struct nodeList *next;
} NodeL;

typedef struct _list {
    int noOfNodes;
    NodeL *first, *last;
} ListT;

ListT *createAdjList(int noOfVertices);

NodeL *createNodeList(int start, int destination, int weight);

void addLast(ListT *adjList, int start, int destination, int weight);

void deleteLast(ListT *adjList);

void doomTheList(ListT *adjList);

void printList(FILE *outputFile, ListT adjList);

void printAdjList(FILE *outputFile, ListT *adjList, int noOfVertices);

void printPath(FILE *outputFile, ListT list);

#endif //ASSIGNMENT5_LIST_H
