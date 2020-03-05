//
// Created by Bori on 2/25/2020.
//

#ifndef ASSIGNMENT1_LIST_H
#define ASSIGNMENT1_LIST_H

#include "node.h"

typedef struct {
    node *first, *last;
} list;

list createList();

void addFirst(list *myList, int value);

void addLast(list *myList, int value);

void deleteFirst(list *myList);

void deleteLast(list *myList);

void deleteAll(list *myList);

void deleteValue(list *myList, int value);

void printAll(list *myList, FILE *outFile);

void printFirstX(list *myList, int x, FILE *outFile);

void printLastX(list *myList, int x, FILE *outFile);

#endif //ASSIGNMENT1_LIST_H
