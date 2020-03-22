//
// Created by Bori on 2/25/2020.
//

#include "node.h"
#include <stdlib.h>
#include <string.h>

#define MEM_ERR_CODE 2
#define MEM_ERR_MESS "error allocating memory for node"

node *createNode(char *data, node *prev, node *next) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        perror(MEM_ERR_MESS);
        exit(MEM_ERR_CODE);
    }
    newNode->data = (char *) malloc(sizeof(char) * (strlen(data) + 1));
    if (newNode->data == NULL) {
        perror(MEM_ERR_MESS);
        exit(MEM_ERR_CODE);
    }
    strcpy(newNode->data, data);
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}

node *createNodeWithSelfReference(char *data) {
    node *newNode = createNode(data, NULL, NULL);
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}
