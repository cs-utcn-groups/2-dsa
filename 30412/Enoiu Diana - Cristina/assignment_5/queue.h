//
// Created by Diana on 4/11/2020.
//

#ifndef ASSIGNMENT_5_QUEUE_H
#define ASSIGNMENT_5_QUEUE_H
#include "head.h"

void enqueue(int content);

void dequeue();

NodeL *peekQueue();

int isEmptyQueue();

NodeL *queue;

NodeL *createNode(int content);
#endif //ASSIGNMENT_5_QUEUE_H
