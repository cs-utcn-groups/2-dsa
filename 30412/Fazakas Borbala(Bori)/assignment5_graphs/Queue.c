//
// Created by Bori on 4/2/2020.
//

#include "Queue.h"

//
// Created by Bori on 2/25/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

Queue createQueue() {
    Queue newQueue;
    newQueue.last = NULL;
    return newQueue;
}

void enqueue(Queue *myQueue, int value) {
    node *newNode = createNode(value);
    if (myQueue->last != NULL) {
        newNode->next = myQueue->last->next;
        myQueue->last->next = newNode;
    } else {
        newNode->next = newNode;
    }
    myQueue->last = newNode;
}

int front(Queue *myQueue) {
    return myQueue->last->next->data;
}

int dequeue(Queue *myQueue) {
    node *prevFirst = myQueue->last->next;
    int toReturn = prevFirst->data;
    if (myQueue->last->next == myQueue->last) {
        myQueue->last = NULL;
    } else {
        myQueue->last->next = myQueue->last->next->next;
    }
    free(prevFirst);
    return toReturn;
}

void printAllQueue(Queue *myQueue, FILE *outFile) {
    if (myQueue->last == NULL) fprintf(outFile, "Queue is empty\n");
    else {
        node *curNode = myQueue->last->next;
        int found = 0;
        while (!found) {
            fprintf(outFile, "%d ", curNode->data);
            if (curNode == myQueue->last) found = 1;
            curNode = curNode->next;
        }
        fprintf(outFile, "\n");
    }
}

bool isEmpty(Queue *myQueue) {
    return myQueue->last == NULL;
}

