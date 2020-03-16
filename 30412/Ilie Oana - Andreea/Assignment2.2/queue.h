//
// Created by Andreea on 09-Mar-20.
//

#ifndef ASSIGNMENT2_2_QUEUE_H
#define ASSIGNMENT2_2_QUEUE_H

typedef struct _queue {
    int time, roubles;
    struct _queue *prev, *next;
} queueT;

queueT *firstQ, *lastQ;

void initializeQueue();

void addQueue(int time, int roubles);

void createQueue();

void PRINT_ALL_Q(FILE *outputFile);

#endif //ASSIGNMENT2_2_QUEUE_H
