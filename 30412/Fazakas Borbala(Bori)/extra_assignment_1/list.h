//
// Created by Bori on 2/25/2020.
//

#ifndef ASSIGNMENT1_LIST_H
#define ASSIGNMENT1_LIST_H

#include "node.h"
#include <stdio.h>

typedef struct {
    node *first, *last;
} list;

list createList();

void addFirst(list *myList, int value);

int isEmpty(list *myList);

void addLast(list *myList, int value);

void deleteFirst(list *myList);

void deleteLast(list *myList);

int sumOfElements(list *myList);

int firstValue(list *myList);

int subtractFromFirstValue(list *myList, int value);

int size(list *myList);

int noElementsWithSumSmallerOrEqual(list *myList, int sum, int *unUsedOfSum);

#endif //ASSIGNMENT1_LIST_H
