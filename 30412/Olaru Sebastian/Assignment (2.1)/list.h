#ifndef ASSIGNMENT__2_1__LIST_H
#define ASSIGNMENT__2_1__LIST_H

#include "node.h"

FILE *fin, *fout;

typedef struct list {
    Node *santinel;
}List;

List doubleLinkedList;

List createList();

void AddElementFirst(int x);

void AddElementLast(int x);

void DeleteFirst();

void DeleteLast();

void DeleteWholeList();

void DeleteElement(int x);

void PrintWholeList();

void PrintFirstNElements(int x);

void PrintLastNElements(int x);

#endif //ASSIGNMENT__2_1__LIST_H
