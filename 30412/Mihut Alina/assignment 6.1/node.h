//
// Created by Alina Mihut on 4/12/20.
//

#ifndef ASSIGNMENT_6_1_NODE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
} NodeT;

NodeT *createNode(int content);
#define ASSIGNMENT_6_1_NODE_H

#endif //ASSIGNMENT_6_1_NODE_H
