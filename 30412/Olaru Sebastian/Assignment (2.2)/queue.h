//
// Created by acer on 3/10/2020.
//
#ifndef ASSIGNMENT__2_2__QUEUE_H
#define ASSIGNMENT__2_2__QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMETABLE_LENGTH 100

typedef struct _node {
    int rubles;
    int seconds;
    struct _node *next;
    struct _node *prev;
} Customer;

typedef struct _dllist {
    Customer *first;
    Customer *last;
} Line;

FILE *fin, *fout;
Line *line;
int timeTable[MAX_TIMETABLE_LENGTH];
int totalRubles, totalSec;

void addCustomer();
void prettyPrint(int i);

#endif //ASSIGNMENT__2_2__QUEUE_H
