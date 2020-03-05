//
// Created by Bori on 2/25/2020.
//

#ifndef ASSIGNMENT1_Queue_H
#define ASSIGNMENT1_Queue_H

#include "node.h"

typedef struct {
    node *first, *last;
} Queue;

Queue createQueue();

void push(Queue *myQueue, int value);

int pop(Queue *myQueue);

int front(Queue* myQueue);

void printAll(Queue *myQueue, FILE *outFile);

#endif //ASSIGNMENT1_Queue_H
