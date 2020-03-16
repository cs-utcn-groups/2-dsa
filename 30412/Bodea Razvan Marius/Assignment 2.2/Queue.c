//
// Created by razvi on 3/8/2020.
//
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void initializeSll() {
    first = NULL;
    last = NULL;
}

void Add_Last(int data) {
    if (first == NULL) {
        first = (Queue *) malloc(sizeof(Queue));
        first->next = last;
        first->data = data;
        last = first;
    } else {
        Queue *newNode = (Queue *) malloc(sizeof(Queue));
        newNode->data = data;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

void Delete_First() {
    if (first == NULL) {
        return;
    }
    Queue *newNode = first;
    first = first->next;
    free(newNode);
}
