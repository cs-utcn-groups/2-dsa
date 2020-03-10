//
// Created by Tudor Tise on 10/03/2020.
//

#ifndef ASSIGNMENT_2___FIRST_LISTMANAGEMENT_H
#define ASSIGNMENT_2___FIRST_LISTMANAGEMENT_H

#include <stdlib.h>
#include <stdio.h>

void setUpFile();
void initializeList();
void addLast(int addedValue);
void addFirst(int addedValue);
void removeLast();
void removeFirst();
void printAll();
void printFirst(int noOfElementsToBePrinted);
void printLast(int noOfElementsToBePrinted);
int getNoOfItems();
void removeAll();
void removeElement(int itemToBeDeleted);



typedef struct node {
    int data;
    struct node * next;
    struct node * prev;
} NodeT;

NodeT * first, * last;
FILE *g;

#endif //ASSIGNMENT_2___FIRST_LISTMANAGEMENT_H
