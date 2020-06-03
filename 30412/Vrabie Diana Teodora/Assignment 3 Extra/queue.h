//
// Created by diana on 07/05/2020.
//

#ifndef ASSIGNMENT_3_EXTRA_QUEUE_H
#define ASSIGNMENT_3_EXTRA_QUEUE_H

#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_CHAR_LENGTH 6

typedef struct _queue {
    QueueNode *first, *last;
} Queue;

Queue* initializeQueue();

void enqueue(QueueNode *node, Queue *queue);

QueueNode *dequeue (Queue *queue);

bool isEmpty (Queue queue);

void readQueue(FILE *inputFile, Queue *queue);

#endif //ASSIGNMENT_3_EXTRA_QUEUE_H
