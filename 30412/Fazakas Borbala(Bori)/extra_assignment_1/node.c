//
// Created by Bori on 2/25/2020.
//

#include "node.h"
#include <stdlib.h>

node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node *createNodeWithNext(int data, node *next) {
    node *newNode = createNode(data);
    newNode->next = next;
    return newNode;
}
