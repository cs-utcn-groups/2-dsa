//
// Created by bindi on 4/6/2020.
//
#include <stdlib.h>
#include "list.h"

list *createListElement(int data) {
    list *newElement = (list *) malloc(sizeof(list));
    newElement->data = data;
    newElement->next = NULL;
    return newElement;
}