//
// Created by Bori on 3/19/2020.
//

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue createQueue() {
    Queue newQueue;
    newQueue.first = NULL;
    newQueue.last = NULL;
    return newQueue;
}

static void addFirst(Queue *myQueue, char *value) {
    node *newNode = createNode(value, myQueue->first);
    myQueue->first = newNode;
    if (myQueue->last == NULL) {
        myQueue->last = myQueue->first;
    }
}

void push(Queue *myQueue, char *value) {
    if (myQueue->first == NULL) {
        addFirst(myQueue, value);
    } else {
        node *newNode = createNode(value, NULL);
        myQueue->last->next = newNode;
        myQueue->last = newNode;
    }
}

char *pop(Queue *myQueue) {
    if (myQueue->first != NULL) {
        node *prevFirst = myQueue->first;
        myQueue->first = myQueue->first->next;
        char *result = prevFirst->data;
        free(prevFirst);
        if (myQueue->first == NULL) myQueue->last = NULL;
        return result;
    } else {
        perror("Queue is empty, you can't pop!");
    }
}

char *front(Queue *myQueue) {
    if (myQueue->first != NULL) {
        return myQueue->first->data;
    } else {
        perror("Queue is empty, you can't access first element");
    }
}

void printAllQueue(Queue *myQueue, FILE *outFile) {
    if (myQueue->first == NULL) {
        fprintf(outFile, "Queue is empty\n");
    } else {
        node *curnode = myQueue->first;
        while (curnode != NULL) {
            fprintf(outFile, "%s ", curnode->data);
            curnode = curnode->next;
        }
        fprintf(outFile, "\n");
    }
}

int QueueIsEmpty(Queue *myQueue) {
    return myQueue->first == NULL;
}
