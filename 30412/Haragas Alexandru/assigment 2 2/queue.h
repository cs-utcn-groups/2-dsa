//
// Created by Alex on 05.03.2020.
//

#ifndef ASSIGMENT_2_2_QUEUE_H
#define ASSIGMENT_2_2_QUEUE_H

#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Queue;

Queue *first, *last;

void Initialize();

void AddLast(int x);

void DeleteFirst();

#endif //ASSIGMENT_2_2_QUEUE_H
