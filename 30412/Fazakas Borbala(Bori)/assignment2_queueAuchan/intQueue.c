//
// Created by Bori on 2/25/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "intQueue.h"

intQueue createIntQueue() {
    intQueue newintQueue;
    newintQueue.first = NULL;
    newintQueue.last = NULL;
    return newintQueue;
}

static void addFirst(intQueue *myintQueue, int value) {
    intNode *newNode = createIntNodeWithNext(value, myintQueue->first);
    myintQueue->first = newNode;
    if (myintQueue->last == NULL) {
        myintQueue->last = myintQueue->first;
    }
}

void pushInt(intQueue *myintQueue, int value) {
    if (myintQueue->first == NULL) {
        addFirst(myintQueue, value);
    } else {
        intNode *newintNode = createIntNode(value);
        myintQueue->last->next = newintNode;
        myintQueue->last = newintNode;
    }
}

int popInt(intQueue *myintQueue) {
    if (myintQueue->first != NULL) {
        intNode *prevFirst = myintQueue->first;
        myintQueue->first = myintQueue->first->next;
        int result = prevFirst->data;
        free(prevFirst);
        if (myintQueue->first == NULL) myintQueue->last = NULL;
        return result;
    } else {
        perror("intQueue is empty, you can't pop!");
    }
}

int frontInt(intQueue *myintQueue) {
    if (myintQueue->first != NULL) {
        return myintQueue->first->data;
    } else {
        perror("intQueue is empty, you can't access last element");
    }
}

void printAllIntQueue(intQueue *myintQueue, FILE *outFile) {
    if (myintQueue->first == NULL) {
        fprintf(outFile, "intQueue is empty\n");
    } else {
        intNode *curintNode = myintQueue->first;
        while (curintNode != NULL) {
            fprintf(outFile, "%d ", curintNode->data);
            curintNode = curintNode->next;
        }
        fprintf(outFile, "\n");
    }
}

int intQueueIsEmpty(intQueue *myIntQueue) {
    return myIntQueue->first == NULL;
}
