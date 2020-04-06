//
// Created by ileana on 4/5/2020.
//

#include "queue.h"


void enqueue(int label) {
    if (queue == NULL) {
        queue = createNode(label);
    } else {
        NodeT *aux = queue;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = createNode(label);
    }
}

void dequeue() {
    if (queue != NULL) {
        queue = queue->next;
    }
}

NodeT *peekQueue() {
    return queue;
}

int isEmptyQueue() {
    return queue == NULL;
}

