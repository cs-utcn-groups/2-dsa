//
// Created by Mihai on 3/23/2020.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE 100
#define MAX_ID 5

#ifndef ASSIGNMENT_3_1_HEADER_H
#define ASSIGNMENT_3_1_HEADER_H

typedef struct _node {
    char data;
    struct _node *next, *prev;
} NodeT;

typedef struct _list {
    NodeT *sentinel;
} doublyLinked;

typedef struct _treeNode {
    char id[MAX_ID];
    struct _treeNode *left, *right;
}NodeS;

NodeS *buildTree(FILE *file);
int isOperator(char c);
void preorder(NodeS *currentRoot, int lv);
#endif //ASSIGNMENT_3_1_HEADER_H
