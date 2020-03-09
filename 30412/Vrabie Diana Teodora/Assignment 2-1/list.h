//
// Created by diana on 07/03/2020.
//

#ifndef ASSIGNMENT_2_1_LIST_H
#define ASSIGNMENT_2_1_LIST_H

#include "node.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct list {
    int nrOfMembers;
    Node *first;
    Node *last;
} List;

List *myList;

void initializeList();

void addElementToFront(int data);

void addElementToEnd(int data);

void deleteFirstElement();

void deleteLastElement();

void deleteList();

void deleteElement(int data);

void printAll(FILE *file);

void printFirst(int nr, FILE *file);

void printLast(int nr, FILE *file);

#endif //ASSIGNMENT_2_1_LIST_H
