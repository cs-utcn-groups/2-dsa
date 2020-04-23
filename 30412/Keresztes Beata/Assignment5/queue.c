//
// Created by q on 4/2/2020.
//

#include "queue.h"


QueueT * createQueue() {
    // create queue
    QueueT * queue = (QueueT *)malloc(sizeof(QueueT));
    if(queue == NULL) {
        errMessage();
    }
    else {
        queue->first = queue->last = NULL;
    }
    return queue;
}

void freeQueue(QueueT * queue) {
    // free queue
    NodeT * temp = queue->first;
    while(temp) {
        queue->first = temp->next;
        free(temp);
        temp = queue->first;
    }
    free(queue);
}

void printQueue(QueueT * queue) {
    // print the queue
    NodeT * temp = queue->first;
    while(temp) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    new_line;
}

void enqueue(QueueT * queue, int data) {
    // append new node
    NodeT * new = createNode(data);
    if(queue->last == NULL) {
        // empty queue
        queue->first = new;
    }
    else {
        queue->last->next = new;
    }
    queue->last = new;
}

int dequeue(QueueT * queue) {
    // remove first element of the queue
    if(queue->first) {
        // if list is not empty
        int returnValue = queue->first->data;
        NodeT * temp = queue->first;
        if(queue->first == queue->last) {
            // delete last element
            queue->first = queue->last = NULL;
        }
        else {
            queue->first = queue->first->next;
        }
        free(temp);
        return returnValue;
    }
}

int isEmptyQueue(QueueT * q) {
    // check if queue is empty
    return (q->first == NULL);
}