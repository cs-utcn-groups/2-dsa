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
