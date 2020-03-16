//
// Created by Bori on 3/6/2020.
//

#ifndef ASSIGNMENT2_QUEUEAUCHAN_COSTUMERQUEUE_H
#define ASSIGNMENT2_QUEUEAUCHAN_COSTUMERQUEUE_H

#include "costumerNode.h"
#include <stdio.h>

typedef struct {
    costumerNode *first, *last;
} costumerQueue;

costumerQueue createCostumerQueue();

void pushCostumer(costumerQueue *mycostumerQueue, costumer *c);

costumer popCostumer(costumerQueue *mycostumerQueue);

costumer frontCostumer(costumerQueue *mycostumerQueue);

void printAllCostumers(costumerQueue *mycostumerQueue, FILE *outFile);

int costumerQueueIsEmpty(costumerQueue *costumers);

#endif //ASSIGNMENT2_QUEUEAUCHAN_COSTUMERQUEUE_H
