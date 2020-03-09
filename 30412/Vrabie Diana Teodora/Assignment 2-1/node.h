//
// Created by diana on 07/03/2020.
//

#ifndef ASSIGNMENT_2_1_NODE_H
#define ASSIGNMENT_2_1_NODE_H

#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} Node;

Node* initializeEmptyNode();

#endif //ASSIGNMENT_2_1_NODE_H
