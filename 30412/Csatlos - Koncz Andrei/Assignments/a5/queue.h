//
// Created by csatl on 4/5/2020.
//

#ifndef A5_QUEUE_H
#include "node.h"

void enqueue(int content);

void dequeue();

NodeT *peekQueue();

int isEmptyQueue();

NodeT *queue;
#define A5_QUEUE_H

#endif //A5_QUEUE_H
