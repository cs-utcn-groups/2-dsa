//
// Created by Irina on 21/05/2020.
//

#ifndef ASSIGNMENT7_CHAINING_LIST_H
#define ASSIGNMENT7_CHAINING_LIST_H

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

void addToList(listT * l, char * content);

#endif //ASSIGNMENT7_CHAINING_LIST_H
