//
// Created by bindi on 3/19/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initList(void) {
    firstElement = NULL;
    lastElement = NULL;
}

void addElementLast(char data) {
    list *newElement = (list *) malloc(sizeof(list));
    newElement->data = data;
    newElement->next = NULL;
    newElement->prev = NULL;
    if (firstElement == NULL) {
        firstElement = newElement;
        lastElement = newElement;
    } else {
        lastElement->next = newElement;
        newElement->prev = lastElement;
        lastElement = newElement;
    }
}

void traverseList(list *firstOfList) {
    list *currentElement = firstOfList;
    while (currentElement != NULL) {
        printf("%c ", currentElement->data);
        currentElement = currentElement->next;
    }
    printf("\n");
}