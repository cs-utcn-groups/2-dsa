//
// Created by Alex on 27.02.2020.
//

#ifndef ASIGMENT_1_NODE_H
#define ASIGMENT_1_NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * next;
} List;

List *first, *last;
int noelem;

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

#endif //ASIGMENT_1_NODE_H
