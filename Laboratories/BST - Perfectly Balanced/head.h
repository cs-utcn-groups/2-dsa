//
// Created by Alex on 3/23/2020.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef BST___PERFECTLY_BALANCED_HEAD_H
#define BST___PERFECTLY_BALANCED_HEAD_H
#define COUNT 2

#endif //BST___PERFECTLY_BALANCED_HEAD_H
typedef struct node {
    struct node *left, *right;
    int key;
} NodeT;

void prettyPrint(NodeT *root, int space);