//
// Created by Bori on 2/25/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

Queue createQueue() {
    Queue newQueue;
    newQueue.first = NULL;
    newQueue.last = NULL;
    return newQueue;
}

static void addFirst(Queue *myQueue, int value) {
    node *newNode = createNodeWithNext(value, myQueue->first);
    myQueue->first = newNode;
    if (myQueue->last == NULL) myQueue->last = myQueue->first;
}

void push(Queue *myQueue, int value) {
    if (myQueue->first == NULL) addFirst(myQueue, value);
    else {
        node *newNode = createNode(value);
        myQueue->last->next = newNode;
        myQueue->last = newNode;
    }
}

int pop(Queue *myQueue) {
    if (myQueue->first != NULL) {
        node *prevFirst = myQueue->first;
        myQueue->first = myQueue->first->next;
        int result = prevFirst->data;
        free(prevFirst);
        if (myQueue->first == NULL) myQueue->last = NULL;
        return result;
    }
    else {
        perror("Queue is empty, you can't pop!");
    }
}

int front(Queue* myQueue)
{
    if(myQueue->first!=NULL) {
        return myQueue->first->data;
    }
    else {
        perror("Queue is empty, you can't access last element");
    }
}

void printAll(Queue *myQueue, FILE *outFile) {
    if (myQueue->first == NULL) fprintf(outFile, "Queue is empty\n");
    else {
        node *curNode = myQueue->first;
        while (curNode != NULL) {
            fprintf(outFile, "%d ", curNode->data);
            curNode = curNode->next;
        }
        fprintf(outFile, "\n");
    }
}
