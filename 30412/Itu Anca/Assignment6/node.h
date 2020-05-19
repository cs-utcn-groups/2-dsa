//
// Created by Anca on 4/27/2020.
//

#ifndef ASSIGNMENT6_NODE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
} NodeT;

NodeT *createNode(int content);

#define ASSIGNMENT6_NODE_H

#endif //ASSIGNMENT6_NODE_H
