//
// Created by ileana on 4/5/2020.
//

#ifndef ASSIGNMENT_5_2_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
} NodeT;

NodeT *createNode(int content);


#define ASSIGNMENT_5_2_NODE_H

#endif //ASSIGNMENT_5_2_NODE_H
