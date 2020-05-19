//
// Created by Diana on 07/05/2020.
//

#ifndef ASSIGNMENT_7_1_LIST_H

typedef struct node
{
    char * content;
    struct node * next;
} nodeT;

typedef struct list
{
    nodeT * head;
    nodeT * tail;
    int sizeList;
} listT;

void addToList(listT *l, char * content);
#define ASSIGNMENT_7_1_LIST_H

#endif //ASSIGNMENT_7_1_LIST_H
