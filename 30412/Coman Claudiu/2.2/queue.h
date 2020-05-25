#ifndef A1_QUEUE_H
#define A1_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE_PATH "../input.dat"
#define OUTPUT_FILE_PATH "../output.dat"

typedef struct _nodeQ {
    int rubles,seconds;
    struct _nodeQ * next;
} NodeQ;

typedef struct _nodeT {
    int seconds;
    struct _nodeT * next;
} NodeT;

NodeQ *queue;
NodeT *time;

void InitializeQueue();
void InitializeTime();
void AddFirstQueue(int rubles, int time);
void AddLastTime(int key);
void PrintTime();
void PrintQueue();

#endif