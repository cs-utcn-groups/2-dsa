//
// Created by Andreea on 3/7/2020.
//

#ifndef INC_2_1___DOUBLY_LINKED_LISTS_DLL_H
#define INC_2_1___DOUBLY_LINKED_LISTS_DLL_H

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
}nodeT;

typedef struct sentinel
{
    struct node *head;
    struct node *tail;
}sentinelT;

sentinelT *sentinel;

void initializeSentinelList();
void addFirst(int x);
void addLast(int x);
void deleteFirst();
void deleteLast();
void doomTheList();
void deleteElement(int x);
void printAll(FILE* ofptr);
void printFirstXValues(FILE* ofptr, int x);
int countElementsOfList();
void printLastXValues(FILE* ofptr, int x);


#endif //INC_2_1___DOUBLY_LINKED_LISTS_DLL_H
