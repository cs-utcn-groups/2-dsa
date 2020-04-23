//
// Created by Bori on 2/25/2020.
//

#ifndef ASSIGNMENT1_LIST_H
#define ASSIGNMENT1_LIST_H

#include "node.h"
#include "edge.h"
#include <stdio.h>

typedef struct {
    int size;
    edge *first, *last;
} list;

list createList();

void addFirst(list *myList, int endPoint, int length);

void addLast(list *myList, int endPoint, int length);

void deleteFirst(list *myList);

void deleteLast(list *myList);

void deleteAll(list *myList);

void deleteValue(list *myList, int endPoint);

void printAllList(list *myList, FILE *outFile);

void printFirstX(list *myList, int x, FILE *outFile);

void printLastX(list *myList, int x, FILE *outFile);

#endif //ASSIGNMENT1_LIST_H
