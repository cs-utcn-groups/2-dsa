//
// Created by Diana on 04/05/2020.
//

#include "queue.h"

void enqueue (int key) {
    if (queue == NULL) {
        queue = createNode(key);
    }
    else {
        NodeT * aux = queue;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = createNode(key);
    }
}

void dequeue() {
    if (queue != NULL) {
        queue = queue->next;
    }
}
NodeT* peekQueue() {
    return queue;
}

int isEmptyQueue() {
    return queue == NULL;
}