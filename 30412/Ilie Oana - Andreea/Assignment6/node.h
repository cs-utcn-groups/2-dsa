//
// Created by andre on 06.05.2020.
//

#ifndef ASSIGNMENT6_NODE_H
#define ASSIGNMENT6_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NodeT;

NodeT *createNode(int data);

#endif //ASSIGNMENT6_NODE_H
