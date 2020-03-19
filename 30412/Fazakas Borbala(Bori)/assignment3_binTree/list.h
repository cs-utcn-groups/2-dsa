//
// Created by Bori on 2/25/2020.
//

#ifndef ASSIGNMENT1_LIST_H
#define ASSIGNMENT1_LIST_H

#include "node.h"

typedef struct {
    node *sentinel;
} dlList;

dlList createDLList();

char *popFirst(dlList *mydlList);

void addFirst(dlList *mydlList, char *value);

void addLast(dlList *mydlList, char *value);

void deleteFirst(dlList *mydlList);

void deleteLast(dlList *mydlList);

void deleteAll(dlList *mydlList);

void deleteValue(dlList *mydlList, char *value);

void printAll(dlList *mydlList, FILE *outFile);

void printFirstX(dlList *mydlList, int x, FILE *outFile);

void printLastX(dlList *mydlList, int x, FILE *outFile);

#endif //ASSIGNMENT1_LIST_H
