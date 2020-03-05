//
// Created by diana on 26/02/2020.
//

#ifndef ASSIGNMENT_1_LIST_H
#define ASSIGNMENT_1_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _ListElement {
    int data;
    struct _ListElement *next;
} ListElement;

ListElement *first, *last;

void initializeList();
void addElementToFront(int data);
void addElementToEnd(int data);
void removeFirstElement();
void removeLastElement();
void removeElement(int data);
void deleteList();
void printFirstNElements(int nr, FILE *file);
void printLastNElements(int nr, FILE *file);
void printAll(FILE *file);

#endif //ASSIGNMENT_1_LIST_H
