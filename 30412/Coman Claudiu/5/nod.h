#ifndef ADJACENCY_NODE_H

#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NodeT;