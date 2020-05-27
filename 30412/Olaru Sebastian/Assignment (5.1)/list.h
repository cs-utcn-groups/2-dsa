//
// Created by acer on 4/5/2020.
//

#ifndef ASSIGNMENT__5_1__LIST_H
#define ASSIGNMENT__5_1__LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
}Node;

typedef struct _list{
    Node *first, *last;
}List;

List *getListFromMatrix(int **matrix, int noOfVertices);
void addLastList(List *list, int value);
void printAdjList(List *pList, int noOfVertices);
void enqueue(List *list, int value);
int dequeue(List *list);

#endif //ASSIGNMENT__5_1__LIST_H
