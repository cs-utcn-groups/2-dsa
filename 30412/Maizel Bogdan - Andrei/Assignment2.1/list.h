#ifndef ASSIGNMENT_2_1_DLL_H
#define ASSIGNMENT_2_1_DLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *prev;
} nodeT;

typedef struct _sentinel {
    nodeT *first;
    nodeT *last;
} ListT;
ListT *ListPtr;

void initList();

void addFirst(int data);

void addLast(int data);

void deleteFirst();

void deleteLast();

void deleteElement(int data);

void doomTheList();

void printAll(FILE *fout);

void printFirst(int x, FILE *fout);

void printLast(int x, FILE *fout);

#endif //ASSIGNMENT_2_1_DLL_H
