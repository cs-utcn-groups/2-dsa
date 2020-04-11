//
// Created by csatl on 4/8/2020.
//

#ifndef A6_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
} NodeT;

NodeT *createNode(int content);

#define GRAPHS_101_NODE_H

#define A6_NODE_H

#endif //A6_NODE_H
