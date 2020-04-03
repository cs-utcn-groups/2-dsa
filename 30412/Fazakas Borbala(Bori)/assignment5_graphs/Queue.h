//
// Created by Bori on 4/2/2020.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "Node.h"
#include <stdio.h>
#include <stdbool.h>

//implemented with a circular list

typedef struct {
    node  *last;
} Queue; 

Queue createQueue();

void enqueue(Queue *myQueue, int value);

int dequeue(Queue *myQueue);

int front(Queue* myQueue);

void printAllQueue(Queue *myQueue, FILE *outFile);

bool isEmpty(Queue* myQueue);

#endif //QUEUE_QUEUE_H
