//
// Created by Bori on 3/6/2020.
//

#ifndef ASSIGNMENT2_QUEUEAUCHAN_INTQUEUE_H
#define ASSIGNMENT2_QUEUEAUCHAN_INTQUEUE_H


#include "intNode.h"

typedef struct {
    intNode *first, *last;
} intQueue;

intQueue createIntQueue();

void pushInt(intQueue *myintQueue, int value);

int popInt(intQueue *myintQueue);

int frontInt(intQueue *myintQueue);

void printAllIntQueue(intQueue *myintQueue, FILE *outFile);

int intQueueIsEmpty(intQueue *myIntQueue);

#endif //ASSIGNMENT2_QUEUEAUCHAN_INTQUEUE_H