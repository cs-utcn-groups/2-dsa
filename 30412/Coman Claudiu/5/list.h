#ifndef ADJACENCY_LIST_H
#include "node.h"
#include <stdlib.h>

typedef struct list {
    NodeT *first, *last;
} List;

void initList(List *list);
void enqueue(int data, List *list);
int dequeue(List *list);

#define ADJACENCY_LIST_H

#endif