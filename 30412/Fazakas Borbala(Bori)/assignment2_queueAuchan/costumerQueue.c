//
// Created by Bori on 3/6/2020.
//

#include "costumerQueue.h"
#include <stdio.h>
#include <stdlib.h>

costumerQueue createCostumerQueue() {
    costumerQueue newcostumerQueue;
    newcostumerQueue.first = NULL;
    newcostumerQueue.last = NULL;
    return newcostumerQueue;
}

static void addFirst(costumerQueue *mycostumerQueue, costumer *c) {
    costumerNode *newNode = createCostumerNodeWithNext(c, mycostumerQueue->first);
    mycostumerQueue->first = newNode;
    if (mycostumerQueue->last == NULL) {
        mycostumerQueue->last = mycostumerQueue->first;
    }
}

void pushCostumer(costumerQueue *mycostumerQueue, costumer *c) {
    if (mycostumerQueue->first == NULL) {
        addFirst(mycostumerQueue, c);
    } else {
        costumerNode *newcostumerNode = createCostumerNode(c);
        mycostumerQueue->last->next = newcostumerNode;
        mycostumerQueue->last = newcostumerNode;
    }
}

costumer popCostumer(costumerQueue *mycostumerQueue) {
    if (mycostumerQueue->first != NULL) {
        costumerNode *prevFirst = mycostumerQueue->first;
        mycostumerQueue->first = mycostumerQueue->first->next;
        costumer result = prevFirst->thisCostumer;
        free(prevFirst);
        if (mycostumerQueue->first == NULL) mycostumerQueue->last = NULL;
        return result;
    } else {
        perror("costumerQueue is empty, you can't pop!");
    }
}

costumer frontCostumer(costumerQueue *mycostumerQueue) {
    if (mycostumerQueue->first != NULL) {
        return mycostumerQueue->first->thisCostumer;
    } else {
        perror("costumerQueue is empty, you can't access last element");
    }
}

void printAllCostumers(costumerQueue *mycostumerQueue, FILE *outFile) {
    if (mycostumerQueue->first == NULL) {
        fprintf(outFile, "costumerQueue is empty\n");
    } else {
        costumerNode *curcostumerNode = mycostumerQueue->first;
        while (curcostumerNode != NULL) {
            fprintf(outFile, "(%d, %d) ", curcostumerNode->thisCostumer.amount, curcostumerNode->thisCostumer.time);
            curcostumerNode = curcostumerNode->next;
        }
        fprintf(outFile, "\n");
    }
}

int costumerQueueIsEmpty(costumerQueue *costumers) {
    return costumers->first == NULL;
}
