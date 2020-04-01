//
// Created by 0rezz on 3/22/2020.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef ASSIGNMENT_3_HEADER_H
#define ASSIGNMENT_3_HEADER_H

typedef struct _node {
    char data;
    struct _node *next, *prev;
} NodeT;

typedef struct _list {
    NodeT *sentinel;
} doublyLinked;

typedef struct _treeNode {
    int id;
    struct _treeNode *left, *right;
}NodeS;

NodeS *createBinaryTree();
void addFirst(char data,doublyLinked *list);
void addLast(char data,doublyLinked *list);
void printAll(doublyLinked *list,FILE *FILE);
void initialiseList(doublyLinked *list);
void preorder(NodeS *currentRoot, int lv);
void getListFromTree(NodeS *currentRoot, int lv, doublyLinked *list);
NodeS *traverseList(NodeT **currentNode);
#endif //ASSIGNMENT_3_HEADER_H
