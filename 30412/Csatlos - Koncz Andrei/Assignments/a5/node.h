//
// Created by csatl on 4/5/2020.
//

#ifndef A5_NODE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
} NodeT;

NodeT *createNode(int content);

#define GRAPHS_101_NODE_H

#define A5_NODE_H

#endif //A5_NODE_H
