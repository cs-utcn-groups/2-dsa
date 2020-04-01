//
// Created by Andreea on 23-Mar-20.
//

#ifndef ASSIGNMENT3_DLL_H
#define ASSIGNMENT3_DLL_H

#include <stdio.h>

typedef struct _nodeL {
    char *data;
    struct _nodeL *next;
    struct _nodeL *prev;
} nodeL;
nodeL *sentinel, *currentElement;

void initializeDLL();

void addLast(char *data);

void deleteFirst();

void traverseList(FILE *outputFile);


#endif //ASSIGNMENT3_DLL_H
