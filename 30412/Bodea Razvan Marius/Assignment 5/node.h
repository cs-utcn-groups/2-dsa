//
// Created by razvi on 4/5/2020.
//

#ifndef ADJACENCY_NODE_H

#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NodeT;

NodeT *createNode(int content);

#define ADJACENCY_NODE_H

#endif //ADJACENCY_NODE_H
