//
// Created by andre on 06.05.2020.
//

#ifndef ASSIGNMENT5_QUEUE_H
#define ASSIGNMENT5_QUEUE_H

#include "node.h"

typedef struct list {
    NodeT *first;
    NodeT *last;
} Queue;

Queue createQueue();

void enqueue(Queue *queue, int data);

void dequeue(Queue *queue);

int isEmptyQueue(Queue *queue);

#endif //ASSIGNMENT5_QUEUE_H
