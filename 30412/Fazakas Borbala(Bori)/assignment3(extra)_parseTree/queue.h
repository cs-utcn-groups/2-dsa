//
// Created by Bori on 3/19/2020.
//

#ifndef ASSIGNMENT3_EXTRA__PARSETREE_QUEUE_H
#define ASSIGNMENT3_EXTRA__PARSETREE_QUEUE_H

#include <stdio.h>
#include "node.h"

typedef struct {
    node *first, *last;
} Queue;

Queue createQueue();

void push(Queue *myQueue, char* value);

char* pop(Queue *myQueue);

char* front(Queue *myQueue);

void printAllQueue(Queue *myQueue, FILE *outFile);

int QueueIsEmpty(Queue *myQueue);

#endif //ASSIGNMENT3_EXTRA__PARSETREE_QUEUE_H
