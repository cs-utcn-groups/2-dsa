//
// Created by q on 3/5/2020.
//

#ifndef LAB2_DOUBLE_LIST_DLL_H
#define LAB2_DOUBLE_LIST_DLL_H

#endif //LAB2_DOUBLE_LIST_DLL_H

#include "node.h"

typedef struct _dLList {
    int count;
    NodeT * head, * tail;
}DLListT;

DLListT * createEmptyList();

void freeList(DLListT * listPtr);

void addFirst(DLListT * listPtr, int x);

void addLast(DLListT * listPtr, int x);

void deleteFirst(DLListT * listPtr);

void deleteLast(DLListT * listPtr);

void doomTheList(DLListT * listPtr);

void deleteByKey(DLListT * listPtr, int x);

void printList(FILE * fp, DLListT * listPtr);

void printFirst(FILE * fp, DLListT * listPtr, int x);

void printLast(FILE * fp, DLListT * listPtr, int x);