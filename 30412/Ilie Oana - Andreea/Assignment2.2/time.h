//
// Created by Andreea on 08-Mar-20.
//

#ifndef ASSIGNMENT2_2_TIME_H
#define ASSIGNMENT2_2_TIME_H

#include <stdio.h>

typedef struct _time {
    int time;
    struct _time *prev, *next;
} timeT;

timeT *firstT, *lastT;

void initializeTime();

void readTime(FILE *inputFile);

void add_time(int time);


#endif //ASSIGNMENT2_2_TIME_H
