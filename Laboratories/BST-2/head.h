//
// Created by Alex on 3/24/2020.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef BST_2_HEAD_H
#define BST_2_HEAD_H

#define COUNT 2

#endif //BST_2_HEAD_H


typedef struct node {
    struct node *left, *right;
    int key;
} NodeT;

void prettyPrint(NodeT *root, int space);