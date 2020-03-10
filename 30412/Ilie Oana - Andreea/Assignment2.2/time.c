//
// Created by Andreea on 08-Mar-20.
//

#include "time.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 30

void initializeTime() {
    firstT = NULL;
    lastT = NULL;
}

void readTime(FILE *inputFile) {
    char *line, *p;
    int x;
    line = (char *) malloc(MAX_LINE * sizeof(char));
    fgets(line, MAX_LINE, inputFile);
    p = strtok(line, " ");
    while (p) {
        x = atoi(p);
        add_time(x);
        p = strtok(NULL, " ");
    }
}

void add_time(int time) {
    timeT *newElement = (timeT *) malloc(sizeof(timeT));
    newElement->time = time;
    newElement->next = NULL;
    newElement->prev = lastT;
    if (lastT != NULL)
        lastT->next = newElement;
    else
        firstT = newElement;
    lastT = newElement;
}

