//
// Created by User on 06.04.2020.
//
#include "node.h"
NodeT *createNode(int key) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->key = key;
    newN->next = NULL;
    return newN;
}
