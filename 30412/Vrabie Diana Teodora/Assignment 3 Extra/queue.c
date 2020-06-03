//
// Created by diana on 07/05/2020.
//


#include "queue.h"

Queue* initializeQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->first = NULL;
    newQueue->last = NULL;
    return newQueue;
}

void enqueue(QueueNode *node, Queue *queue) {
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

bool isEmpty(Queue queue) {
    if (queue.first == NULL) return true;
    return false;
}

void readQueue(FILE *inputFile, Queue *queue) {
    while (inputFile != NULL) {
        char *readValue = (char *) malloc(sizeof(char) * MAX_CHAR_LENGTH);
        fscanf(inputFile, "%s", readValue);
        QueueNode* node = createNewQueueNode(readValue);
        enqueue(node, queue);
        free(readValue);
        if (feof(inputFile) != 0)
            break;
    }
}