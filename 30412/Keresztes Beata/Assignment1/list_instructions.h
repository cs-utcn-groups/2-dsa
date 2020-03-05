//
// Created by q on 3/1/2020.
//

#ifndef ASSIGNMENT1_LIST_INSTRUCTIONS_H
#define ASSIGNMENT1_LIST_INSTRUCTIONS_H

#endif //ASSIGNMENT1_LIST_INSTRUCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node * next;
}NodeT;
NodeT * head, * tail;

void initializeList();

void addFirst(int x);

void addLast(int x);

void deleteFirst();

void deleteLast();

void removeAllElements();

void delete(int x);

FILE * openFile(char * fileName, char * openMode);

void printAll(FILE * fp);

void printFirst(FILE * fp, int x);

void printLast(FILE * fp, int x);