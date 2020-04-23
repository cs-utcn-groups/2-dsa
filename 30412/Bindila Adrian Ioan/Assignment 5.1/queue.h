//
// Created by bindi on 4/2/2020.
//

#ifndef ASSIGNMENT_5_1_QUEUE_H
#define ASSIGNMENT_5_1_QUEUE_H

#include "list.h"

list *queue;

void enqueue(int data);

void dequeue();

list *peekQueue();

int isEmptyQueue();

#endif //ASSIGNMENT_5_1_QUEUE_H
