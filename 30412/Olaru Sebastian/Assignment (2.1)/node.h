#ifndef ASSIGNMENT__2_1__NODE_H
#define ASSIGNMENT__2_1__NODE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *createNode(int data, Node *prev, Node *next);

#endif //ASSIGNMENT__2_1__NODE_H
