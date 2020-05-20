//
// Created by Bori on 4/29/2020.
//

#ifndef ASSIGNMENT6_HT_CHAINING_LIST_H
#define ASSIGNMENT6_HT_CHAINING_LIST_H


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

void addToList(listT* l, char * content);

listT createList();

#endif //ASSIGNMENT6_HT_CHAINING_LIST_H
