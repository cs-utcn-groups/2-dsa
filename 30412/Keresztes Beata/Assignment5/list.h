//
// Created by q on 4/1/2020.
//

#ifndef ASSIGNMENT5_LIST_H
#define ASSIGNMENT5_LIST_H

#include "node.h"

typedef struct list {
    int count;
    NodeT * head, * tail;
}ListT;
// function to create the adjacency array of lists
ListT * createAdjList(int N);
// add new node to the list
void insertNode(ListT * list, int data);
// print adjacency lists
void printAdjList(int N, ListT * AL);
// print list
void printList(ListT list);
// delete last node
void deleteLastNode(ListT * list);
// delete list
void deleteList(ListT * list);

#endif //ASSIGNMENT5_LIST_H
