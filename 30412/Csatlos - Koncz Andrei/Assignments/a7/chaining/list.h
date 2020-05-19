//
// Created by csatl on 5/4/2020.
//

#ifndef CHAINING_LIST_H
#define CHAINING_LIST_H

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

#endif //CHAINING_LIST_H
