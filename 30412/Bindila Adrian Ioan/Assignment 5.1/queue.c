//
// Created by bindi on 4/2/2020.
//
#include <stdlib.h>
#include "list.h"
#include "queue.h"

void enqueue(int data) {
    if (isEmptyQueue()) {
        queue = createListElement(data);
    } else {
        list *temp = queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createListElement(data);
    }
}

void dequeue() {
    if (!isEmptyQueue()) {
        queue = queue->next;
    }
}

list *peekQueue() {
    return queue;
}

int isEmptyQueue() {
    return (queue == NULL);
}