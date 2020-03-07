//
// Created by Andreea on 3/1/2020.
//

#ifndef UNTITLED_SLL_H
#define UNTITLED_SLL_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
}nodeT;

nodeT *first, *last;

void initializeList();
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

#endif //UNTITLED_SLL_H
