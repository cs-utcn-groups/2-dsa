//
// Created by q on 3/6/2020.
//

#ifndef LASTTRY_TIME_H
#define LASTTRY_TIME_H

#endif //LASTTRY_TIME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer.h"

typedef struct _time {
    int sec;
    struct _time * next, * prev;
}TimeT;

typedef struct _interval {
    TimeT * begin, * end;
}MomentT;
/*
 * create new element and allocate memory to it
 */
TimeT * createTime(int sec);
void freeTime(MomentT * momentPtr);
/*
 * create sentinel to list of time
 */
MomentT * createMoment();
/*
 * append new element to the list
 */
void addTime(MomentT * momentPtr, int sec);
/*
 * read the specific time moments from input file
 */
MomentT * readTime(FILE * fp);
/*
 * print the sum of the cashier at each moment t
 */
void printSumAtEachMoment(FILE * fp, MomentT * momentPtr, QueueT * queuePtr);