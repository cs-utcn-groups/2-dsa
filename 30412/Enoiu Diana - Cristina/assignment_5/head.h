//
// Created by Diana on 4/7/2020.
//

#ifndef ASSIGNMENT_5_HEAD_H
#define ASSIGNMENT_5_HEAD_H
#include <stdio.h>
FILE * inp;
int ** adjMatrix;
int nrOfVertices;
typedef struct list{
    int vertex;
    int distance;
    struct list * next;
}NodeL;
NodeL ** firstVertex;
NodeL ** currVertex;
void readGraph();
void transformGraphToList();
void printLists();
void bfsList(int startNode);
void dfsRecList(int v, int *visited);
void dfsRecursList(int startNode);
#endif //ASSIGNMENT_5_HEAD_H
