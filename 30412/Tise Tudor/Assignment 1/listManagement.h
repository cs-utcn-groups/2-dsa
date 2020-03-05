//
// Created by Tudor Tise on 02/03/2020.
//

#ifndef ASSIGNMENT_1_LISTMANAGEMENT_H
#define ASSIGNMENT_1_LISTMANAGEMENT_H
#include <stdlib.h>
#include <stdio.h>

void setUpFile();
void initializeList();
void addLast(int data);
void addFirst(int data);
void removeLast();
void removeFirst();
void printAll();
void printFirst(int data);
void printLast(int data);
int getNoOfItems();
void removeAll();
void removeElement(int data);



typedef struct node {
    int data;
    struct node * next;
} NodeT;

NodeT * first, * last;
FILE *g;

#endif //ASSIGNMENT_1_LISTMANAGEMENT_H
