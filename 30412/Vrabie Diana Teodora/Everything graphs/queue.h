//
// Created by diana on 09/05/2020.
//

#ifndef EVERYTHING_GRAPHS_QUEUE_H
#define EVERYTHING_GRAPHS_QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_CHAR_LENGTH 6

typedef struct _queueNode {
    int value;
    struct _queueNode *next;
} QueueNode;

typedef struct _queue {
    QueueNode *first, *last;
} Queue;

Queue* initializeQueue();

void enqueue(QueueNode *node, Queue *queue);

QueueNode *dequeue (Queue *queue);

bool isEmpty (Queue queue);

void readQueue(FILE *inputFile, Queue *queue);

#endif //EVERYTHING_GRAPHS_QUEUE_H
