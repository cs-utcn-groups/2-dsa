//
// Created by Bori on 2/25/2020.
//

#include "node.h"
#include <stdlib.h>

#define MEM_ERR_CODE 2
#define MEM_ERR_MESS "error allocating memory for node"

node *createNode(int data, node *prev, node *next) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        perror(MEM_ERR_MESS);
        exit(MEM_ERR_CODE);
    }
    newNode->data = data;
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
