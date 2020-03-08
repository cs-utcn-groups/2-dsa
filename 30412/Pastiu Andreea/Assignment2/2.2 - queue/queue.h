//
// Created by Andreea on 3/8/2020.
//

#ifndef INC_2_2___QUEUE_QUEUE_H
#define INC_2_2___QUEUE_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
typedef struct nodeQ
{
    int rubles;
    int seconds;
    struct nodeQ *next;
}queueNode;
typedef struct nodeT
{
    int seconds;
    struct nodeT *next;
}timeNode;
queueNode *firstQueue, *lastQueue;
timeNode *firstTime, *lastTime;

void initializeTime();
void initializeQueue();
void addLastTime(int seconds);
void addLastQueue(int rubles, int seconds);
void deleteFirstTime();
void deleteFirstQueue();
void readData(FILE *inptr, FILE *ofptr);
void solve(FILE *ofptr);

#endif //INC_2_2___QUEUE_QUEUE_H
