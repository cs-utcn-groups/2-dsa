//
// Created by andre on 06.05.2020.
//

#include "queue.h"

Queue createQueue() {
    Queue newQueue;
    newQueue.first = NULL;
    newQueue.last = NULL;
    return newQueue;
}

void enqueue(Queue *queue, int data) {
    NodeT *newElement = createNode(data);
    if (queue->last == NULL) {
        queue->first = newElement;
    } else {
        queue->last->next = newElement;
    }
    queue->last = newElement;
}

void dequeue(Queue *queue) {
    if (queue->first) {
        NodeT *aux = queue->first;
        if (queue->first == queue->last) {
            queue->first = queue->last = NULL;
        } else {
            queue->first = queue->first->next;
        }
        free(aux);
    }
}

int isEmptyQueue(Queue *queue) {
    return (queue->first == NULL);
}
