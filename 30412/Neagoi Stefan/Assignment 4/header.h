//
// Created by Stefan on 31/03/2020.
//
#ifndef ASSIGNMENT_4_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ASSIGNMENT_4_HEADER_H



typedef struct _node {
    int data;
    int height;
    struct _node *left;
    struct _node *right;
}NodeT;

NodeT *newNode(int data);
int max(int a, int b);
NodeT *rotateRight(NodeT *y);
int getBalance(NodeT *N);
NodeT* insert(NodeT* node, int key);
int height(NodeT *N);
void prettyPrint(NodeT *root, int level);
void preorder(NodeT *currentRoot, int lv);


#endif //ASSIGNMENT_4_HEADER_H
