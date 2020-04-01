//
// Created by Andreea on 23-Mar-20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

#define MAX_SIZE 5

void initializeDLL() {
    nodeL *node = (nodeL *) malloc(sizeof(nodeL));
    node->next = node;
    node->prev = node;
    sentinel = node;
    currentElement = sentinel;
}

void addLast(char *data) {
    nodeL *newElement = (nodeL *) malloc(sizeof(nodeL));
    newElement->data = (char *) malloc(MAX_SIZE * sizeof(char));
    strcpy(newElement->data, data);
    currentElement = sentinel->prev;
    currentElement->next = newElement;
    newElement->prev = currentElement;
    newElement->next = sentinel;
    sentinel->prev = newElement;
}

void traverseList(FILE *outputFile) {
    currentElement = sentinel->next;
    if (currentElement == sentinel)
        fprintf(outputFile, "List is empty!");
    else {
        while (currentElement != sentinel) {
            fprintf(outputFile, "%s ", currentElement->data);
            currentElement = currentElement->next;
        }
    }
    fprintf(outputFile, "\n");
}

void deleteFirst() {
    currentElement = sentinel->next;
    if (currentElement != sentinel) {
        sentinel->next = currentElement->next;
        currentElement->next->prev = sentinel;
        free(currentElement);
    }
}