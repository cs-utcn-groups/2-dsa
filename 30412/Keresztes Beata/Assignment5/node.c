//
// Created by q on 4/1/2020.
//

#include "node.h"


void errMessage() {
    // display error message
    perror(ERR_ALLOC_MEM);
    exit(EXIT_FAILURE);
}

NodeT * createNode(int data) {
    // function to create a new node
    NodeT * newNode = (NodeT *)malloc(sizeof(NodeT));
    if(newNode == NULL) {
        errMessage();
    }
    else {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}