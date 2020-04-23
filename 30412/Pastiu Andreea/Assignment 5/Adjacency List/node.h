//
// Created by Andreea on 4/7/2020.
//

#ifndef ADJACENCY_LIST_NODE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
} NodeT;

typedef struct nodeA{
    int key;
    struct node *next;
}nodeT;

NodeT *createNode(int content);
#define ADJACENCY_LIST_NODE_H

#endif //ADJACENCY_LIST_NODE_H
