//
// Created by Diana on 2/29/2020.
//

#ifndef ASSIGNMENT_1_SLL_H
#define ASSIGNMENT_1_SLL_H
#include <stdio.h>
#include <stdlib.h>
void initializeSll();
void addFirst(int data);
void addLast(int data);
void deleteFirst();
void deleteLast();
void doomTheList();
void deleteElement(int data);
void printAll(FILE * output);
void printFirst (FILE * output, int tillValue);
void printLast (FILE * output, int tillValue);
typedef struct _node {
    int data;
    struct _node * next;
} NodeT;
NodeT * first, * last;
#endif //ASSIGNMENT_1_SLL_H
