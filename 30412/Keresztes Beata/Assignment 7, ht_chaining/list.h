//
// Created by q on 5/1/2020.
//

#ifndef ASSIGNMENT_7__HT_CHAINING_LIST_H
#define ASSIGNMENT_7__HT_CHAINING_LIST_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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

void addToList(listT * l, char * content);
void printList(listT l);
int find(listT * l, char * data);
#endif //ASSIGNMENT_7__HT_CHAINING_LIST_H
