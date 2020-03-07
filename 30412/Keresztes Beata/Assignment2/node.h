//
// Created by q on 3/5/2020.
//

#ifndef LAB2_DOUBLE_LIST_NODE_H
#define LAB2_DOUBLE_LIST_NODE_H

#endif //LAB2_DOUBLE_LIST_NODE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node * prev, *next;
}NodeT;

NodeT * createNode(int data);

NodeT * findNodeByKey(NodeT * curr, int x);
/*
 * this function prints the last x elements of the list, by traversing it backwards
 */
void printLastRec(FILE * fp, NodeT * curr, int x);