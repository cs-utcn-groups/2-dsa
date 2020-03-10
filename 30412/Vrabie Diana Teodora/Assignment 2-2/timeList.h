//
// Created by diana on 09/03/2020.
//

#ifndef ASSIGNMENT_2_2_TIMELIST_H
#define ASSIGNMENT_2_2_TIMELIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int time;
    struct node *next;
} Node;

typedef struct _timeList {
    int nrOfEntries;
    Node *first;
    Node *last;
} TimeList;

TimeList *timeList;

Node *initializeEmptyNode();

void initializeTimeList();

void addTimeToList(int time);


#endif //ASSIGNMENT_2_2_TIMELIST_H
