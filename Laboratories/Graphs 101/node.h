//
// Created by Alex on 3/30/2020.
//

#ifndef GRAPHS_101_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
} NodeT;

NodeT *createNode(int content);

#define GRAPHS_101_NODE_H

#endif //GRAPHS_101_NODE_H

