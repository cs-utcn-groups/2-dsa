//
// Created by Alex on 04.04.2020.
//

#ifndef ASSIGNMENT_5_LIST_H

#include "stack.h"
#include <stdio.h>

typedef struct node {
    int label;
    int val;
    struct node *next;
} List;

List *createList(int n, int *m);

void printList(int n, List **l);

void DFSList(int x, List **l, int *v);

void BFSList(int x, List **l,int *v);

int **backMatrix(int n, List **l);

#define ASSIGNMENT_5_LIST_H

#endif //ASSIGNMENT_5_LIST_H
