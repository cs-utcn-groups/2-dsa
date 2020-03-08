//
// Created by razvi on 3/8/2020.
//

#ifndef NEW_FOLDER_QUEUE_H
#define NEW_FOLDER_QUEUE_H

#include <stdio.h>

void initializeSll();

void Add_Last(int data);

void Delete_First();

typedef struct node {
    int data;
    struct node *next;
} Queue;

Queue *first, *last;

#endif //NEW_FOLDER_QUEUE_H
