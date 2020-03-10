//
// Created by Andreea on 09-Mar-20.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "customer.h"
#include "time.h"

void initializeQueue() {
    firstQ = NULL;
    lastQ = NULL;
}

void createQueue() {
    customerT *currentElC = firstC;
    timeT *currentElT = firstT;
    while (currentElT != NULL) {
        addQueue(currentElT->time, 0);
        currentElT = currentElT->next;
    }
    queueT *currentElQ = firstQ;
    int sumTime = 0, sumRoubles = 0;
    while (currentElC != NULL) {
        sumTime += currentElC->time;
        sumRoubles += currentElC->roubles;
        if (sumTime >= currentElQ->time || sumTime + currentElQ->next->time > currentElQ->time) {
            currentElQ->roubles = sumRoubles;
            currentElQ = currentElQ->next;
        }
        currentElC = currentElC->next;
    }
    while (currentElQ != NULL) {
        currentElQ->roubles = sumRoubles;
        currentElQ = currentElQ->next;
    }

}

void addQueue(int time, int roubles) {
    queueT *newElement = (queueT *) malloc(sizeof(queueT));
    newElement->time = time;
    newElement->roubles = roubles;
    newElement->next = NULL;
    newElement->prev = lastQ;
    if (lastQ != NULL)
        lastQ->next = newElement;
    else
        firstQ = newElement;
    lastQ = newElement;
}

void PRINT_ALL_Q(FILE *outputFile) {
    if (firstC == NULL) {
        fprintf(outputFile, "List is empty!\n");
    } else {
        queueT *currentElement = firstQ;
        while (currentElement != NULL) {
            fprintf(outputFile, "After %d seconds: %d\n ", currentElement->time, currentElement->roubles);
            currentElement = currentElement->next;
        }
        fprintf(outputFile, "\n");
    }
}

