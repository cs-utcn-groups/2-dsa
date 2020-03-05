//
// Created by Bori on 2/25/2020.
//

#include "node.h"
#include <stdlib.h>

node *createNode(int data, node *prev, node* next) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->data=data;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}

node *createNodeWithSelfReference(int data) {
    node *newNode = createNode(data, NULL, NULL);
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}
