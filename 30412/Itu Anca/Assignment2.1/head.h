//
// Created by Anca on 3/8/2020.
//

#ifndef ASSIGNMENT2_HEAD_H
#define ASSIGNMENT2_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}NodeT;

NodeT *head;
NodeT *last;

FILE * fptrout;

void initializeDll();
void addFirst(int data);
void addLast(int data);
void printDllData();
void deleteFirst();
void deleteFirst2();
void deleteLast();
void deleteLast2();
void deleteAll();
void deleteX(int x);
void printFirstXElements(int x);
void printLastXElements(int x);

#endif //ASSIGNMENT2_HEAD_H
