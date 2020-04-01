//
// Created by Bobby on 3/19/2020.
//

#ifndef ASSIGNMENT3_TREE_H
#define ASSIGNMENT3_TREE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tree{
    char data;
    struct tree *left;
    struct tree *right;
}NodeT;

NodeT *root;

typedef struct list{
    char data;
    struct list *next;
    struct list *prev;
}Node;

Node *first,*last;

NodeT *createTree();

void intializeList();

Node createList(NodeT *k);

NodeT *back();

void printT(NodeT *x, int layer);

void printL();

void freeTree();

#endif //ASSIGNMENT3_TREE_H
