//
// Created by Alina Mihut on 4/5/20.
//

#ifndef ASSIGNMENT_5_LIST_H
#define ASSIGNMENT_5_LIST_H
#include <stdio.h>
#include "node.h"
typedef struct list
{
    NodeT *first, *last;
}List;

List *adjList;

void initializeList ();
void addLast ( List *l, int v);
void printList (List *l);
List *createListFromMatrix ();
#endif //ASSIGNMENT_5_LIST_H
