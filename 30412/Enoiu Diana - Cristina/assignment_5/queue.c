//
// Created by Diana on 4/11/2020.
//

#include "stdlib.h"
#include "queue.h"
void enqueue(int content) {
    if (queue == NULL) {
        queue = createNode(content);
    } else {
        NodeL *aux = queue;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = createNode(content);
    }
}

void dequeue() {
    if (queue != NULL) {
        queue = queue->next;
    }
}

NodeL *peekQueue() {
    return queue;
}

int isEmptyQueue() {
    return queue == NULL;
}
NodeL *createNode(int content) {
    NodeL *newN = (NodeL *) malloc(sizeof(NodeL));
    newN->vertex = content;
    newN->next = NULL;
    return newN;
}