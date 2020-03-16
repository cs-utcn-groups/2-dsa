//
// Created by diana on 09/03/2020.
//

#include "timeList.h"

void addTimeToList(int time) {
    if (timeList->nrOfEntries == 0) {
        timeList->nrOfEntries = 1;
        timeList->first = initializeEmptyNode();
        timeList->first->next = NULL;
        timeList->first->time = time;
        timeList->last = timeList->first;
    } else {
        Node *node = (Node *) malloc(sizeof(Node));
        node->time = time;
        timeList->last->next = node;
        node->next = NULL;
        timeList->last = node;
        timeList->nrOfEntries++;
    }
}

void initializeTimeList() {
    timeList = (TimeList *) malloc(sizeof(TimeList));
    timeList->nrOfEntries = 0;
    timeList->first = NULL;
    timeList->last = NULL;
}

Node *initializeEmptyNode() {
    Node *node = (Node *) malloc(sizeof(Node));
    return node;
}

