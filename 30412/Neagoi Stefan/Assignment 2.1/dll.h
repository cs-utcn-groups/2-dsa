//
// Created by htbc4 on 3/9/2020.
//
#include <stdio.h>
#ifndef ASSIGNMENT_2_DLL_H

typedef struct _node {
    int data;
    struct _node *next, *prev;
} NodeT;

typedef struct _list {
    NodeT *sentinel;
} doublyLinked;

void initialiseList(doublyLinked *list);
void addFirst(int data,doublyLinked *list);
void addLast(int data,doublyLinked *list);
void deleteFirst(doublyLinked *list);
void deleteLast(doublyLinked *list);
void doomList(doublyLinked *list);
void deleteElement(int data,doublyLinked *list);
void printAll(doublyLinked *list,FILE *FILE);
void printFirst(int a,doublyLinked *list, FILE *file);
void printLast(int a, doublyLinked *list, FILE *file);
int getListLength(doublyLinked *list);
#define ASSIGNMENT_2_DLL_H

#endif //ASSIGNMENT_2_DLL_H
