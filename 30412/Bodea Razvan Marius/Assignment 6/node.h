#ifndef CODE_HERE_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node *next;
    struct node *prev;
} NodeT;

NodeT *createNode(int content);
#define CODE_HERE_NODE_H

#endif //CODE_HERE_NODE_H
