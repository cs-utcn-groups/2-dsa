//
// Created by acer on 3/10/2020.
//
#include "node.h"


Node *createNode(int data, Node *prev, Node *next) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}