//
// Created by Alex on 19.03.2020.
//

#ifndef ASSIGNMENT_3_1_NODES_H
#define ASSIGNMENT_3_1_NODES_H

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
}NodeL;

NodeL *first,*last;

NodeT *createTree();

void intializeList();

NodeL createList(NodeT *x);

NodeT *goBack();

void printTree(NodeT *x,int level);

void printList();

void freeTree();
#endif //ASSIGNMENT_3_1_NODES_H
