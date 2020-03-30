//
// Created by Alina Mihut on 3/29/20.
//

#ifndef ASSIGNMENT_4_HEAD_H
#define ASSIGNMENT_4_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#define COUNT 5
typedef struct node {
    int key;
    int height;
    struct node *left, *right;
}NodeT;


int height(NodeT *current);
NodeT *createNewNode (int key);
NodeT *rightRotate (NodeT *node);
NodeT *leftRotate (NodeT *node);
int getBalance (NodeT *node);
NodeT *insert (NodeT *node, int key);
NodeT *balanceTree(NodeT *node,int key);
NodeT *delete (NodeT *root, int key);
NodeT *getSuccessor (NodeT *node);
void prettyPrint (NodeT *root, int space);

#endif //ASSIGNMENT_4_HEAD_H