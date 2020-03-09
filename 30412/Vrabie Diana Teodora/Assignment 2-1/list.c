//
// Created by diana on 07/03/2020.
//

#include "list.h"

void initializeList() {
    myList = (List *) malloc(sizeof(List));
    myList->nrOfMembers = 0;
    myList->first = NULL;
    myList->last = NULL;
}

void addElementToFront(int data) {
    if (myList->first == NULL) {
        myList->first = initializeEmptyNode();
        myList->last = initializeEmptyNode();
        myList->first->value = data;
        myList->first->next = NULL;
        myList->first->prev = NULL;
        myList->last = myList->first;
        myList->nrOfMembers = 1;
    } else {
        Node *newNode = initializeEmptyNode();
        newNode->value = data;
        newNode->next = myList->first;
        newNode->prev = NULL;
        myList->first->prev = newNode;
        myList->first = newNode;
        myList->nrOfMembers++;
    }
}

void printAll(FILE *file) {
    if (myList->nrOfMembers == 0) {
        return;
    }
    Node *node = myList->first;
    while (node != NULL) {
        fprintf(file, "%d ", node->value);
        node = node->next;
    }
    fprintf(file, "\n");
}

void addElementToEnd(int data) {
    if (myList->last == NULL) {
        myList->first = initializeEmptyNode();
        myList->last = initializeEmptyNode();
        myList->last->value = data;
        myList->last->next = NULL;
        myList->last->prev = NULL;
        myList->first = myList->last;
        myList->nrOfMembers = 1;
    } else {
        Node *newNode = initializeEmptyNode();
        newNode->value = data;
        newNode->next = NULL;
        newNode->prev = myList->last;
        myList->last->next = newNode;
        myList->last = newNode;
        myList->nrOfMembers++;
    }
}
