//
// Created by Bobby on 3/4/2020.
//

#ifndef ASSIGNMENT2_DOUBLE_H
#define ASSIGNMENT2_DOUBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} List;

typedef struct sent {
    List *first;
    List *last;
} DoubleList;

DoubleList *list;

void InitializeList();

void AddFirst(int x);

void AddLast(int x);

void DeleteFirst();

void DeleteLast();

void DeleteList();

void DeleteElem(int x);

void PrintList();

void PrintFirst(int x);

void PrintLast(int x);

#endif //ASSIGNMENT2_DOUBLE_H
