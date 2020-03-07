//
// Created by Alex on 05.03.2020.
//

#ifndef ASSIGMENT_2_1_DOUBLENODE_H
#define ASSIGMENT_2_1_DOUBLENODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} List;

typedef struct sentinel {
    List *first;
    List *last;
} DoubleList;

DoubleList *Dlist;

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


#endif //ASSIGMENT_2_1_DOUBLENODE_H
