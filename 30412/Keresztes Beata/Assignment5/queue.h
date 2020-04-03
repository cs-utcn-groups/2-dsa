//
// Created by q on 4/2/2020.
//

#ifndef ASSIGNMENT5_QUEUE_H
#define ASSIGNMENT5_QUEUE_H

#include "node.h"

typedef struct QueueT {
    NodeT * first, * last;
}QueueT;
// create empty queue
QueueT * createQueue();
// free queue
void freeQueue(QueueT * queue);
/*
 * queue operations:
 * * enqueue
 * * dequeue
 */
void enqueue(QueueT * queue, int data);
// remove first element and return its content
int dequeue(QueueT * queue);
// print the queue
void printQueue(QueueT * queue);
// check is queue is empty
int isEmptyQueue(QueueT * q);
#endif //ASSIGNMENT5_QUEUE_H
