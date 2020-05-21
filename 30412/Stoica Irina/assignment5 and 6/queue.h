//
// Created by Irina on 08/05/2020.
//

#ifndef ASSIGNMENT5_QUEUE_H
#define ASSIGNMENT5_QUEUE_H

#include "node.h"

void enqueue(int content);

void dequeue();

NodeT *peekQueue();

int isEmptyQueue();

NodeT *queue;

#endif //ASSIGNMENT5_QUEUE_H
