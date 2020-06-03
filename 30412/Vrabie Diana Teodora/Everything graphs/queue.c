//
// Created by diana on 09/05/2020.
//

#include "queue.h"

QueueNode *createNewQueueNode(int value) {
    QueueNode *node = (QueueNode *) malloc(sizeof(QueueNode));
    node->value = value;
    node->next = NULL;
    return node;
}

Queue *initializeQueue() {
    Queue *newQueue = (Queue *) malloc(sizeof(Queue));
    newQueue->first = NULL;
    newQueue->last = NULL;
    return newQueue;
}

void enqueue(int value, Queue *queue) {
    QueueNode *node = createNewQueueNode(value);
    //empty queue, add first node
    if (queue->first == NULL) {
        queue->first = queue->last = node;
        return;
    }
    //append node to end of queue
    queue->last->next = node;
    queue->last = node;
}

QueueNode *dequeue(Queue *queue) {
    //queue is empty
    if (queue->first == NULL) {
        return NULL;
    }
    QueueNode *node = queue->first;
    queue->first = queue->first->next;
    return node;
}

bool isQueueEmpty(Queue *queue) {
    if (queue->first == NULL) return true;
    return false;
}

void readQueue(FILE *inputFile, Queue *queue) {
    while (inputFile != NULL) {
        int readValue;
        fscanf(inputFile, "%d", &readValue);
        enqueue(readValue, queue);
        if (feof(inputFile) != 0)
            break;
    }
}