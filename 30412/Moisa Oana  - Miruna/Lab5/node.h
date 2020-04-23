//
// Created by User on 04.04.2020.
//

#ifndef LAB5_NODE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int content;
    struct node *next;
} NodeT;

typedef struct nodeList {
    int *key;
    struct nodeList *next;
} NodeL;

typedef struct list{
    struct nodeList *first;
    struct nodeList *last;
}ListT;
ListT *adjList;

NodeT *createNode(int content);
NodeL * createNodeforList(int key, int weight);
void initializeList(ListT *L);
#define  GRAPHS_101_NODE_H
#define LAB5_NODE_H

#endif //LAB5_NODE_H
