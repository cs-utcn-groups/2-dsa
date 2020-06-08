#ifndef ASSIGNMENT__3_1__NODE_H
#define ASSIGNMENT__3_1__NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeT {
    char data;
    struct nodeT *left, *right;
} NodeT;

typedef struct nodeL {
    char data;
    struct nodeL *next;
} NodeL;

NodeL *createNewListNode(char data);

NodeT *createNewTreeNode(char data);

#endif //ASSIGNMENT__3_1__NODE_H
