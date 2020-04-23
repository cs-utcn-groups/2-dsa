//
// Created by q on 4/14/2020.
//

#ifndef ASSIGNMENT6_VERTICESLIST_H
#define ASSIGNMENT6_VERTICESLIST_H

#include "node.h"
typedef struct _list {
    int count;
    NodeT * head, * tail;
}VlistT;
/*
 * list operations
 */
VlistT * createList(int N);
void addNewNode(VlistT * l, int x);
void printingList(VlistT * l);
#endif //ASSIGNMENT6_VERTICESLIST_H
