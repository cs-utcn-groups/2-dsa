//
// Created by diana on 26/05/2020.
//

#ifndef ASSIGNMENT_7_2_LIST_H
#define ASSIGNMENT_7_2_LIST_H

#include "string.h"
#include "stdlib.h"

typedef struct node
{
    char * content;
    struct node * next;
} nodeT;

typedef struct list
{
    nodeT * head;
    nodeT * tail;
    int size;
} listT;

void addToList(listT l, char * content);

#endif //ASSIGNMENT_7_2_LIST_H
