//
// Created by Irina on 08/05/2020.
//

#ifndef ASSIGNMENT5_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
} NodeT;

NodeT *createNode(int content);

#define ASSIGNMENT5_NODE_H

#endif //ASSIGNMENT5_NODE_H
