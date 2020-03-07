//
// Created by Alex on 05.03.2020.
//

#include "queue.h"

void Initialize() {
    first = NULL;
    last = NULL;
}

void AddLast(int x) {
    if (first == NULL) {
        first = (Queue *) malloc(sizeof(Queue));
        first->next = last;
        first->val = x;
        last = first;
    } else {
        Queue *newnode = (Queue *) malloc(sizeof(Queue));
        newnode->val = x;
        newnode->next = NULL;
        last->next = newnode;
        last = newnode;
    }
}

void DeleteFirst() {
    Queue *newnode = first;
    first = first->next;
    free(newnode);
    if (first == NULL)
        last = NULL;
}