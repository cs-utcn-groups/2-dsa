//
// Created by Alex on 28.03.2020.
//

#ifndef ASSIGNMENT_4_AVL_H
#define ASSIGNMENT_4_AVL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windef.h>

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}NodeT;

void afisTree(NodeT *node,int depth);
NodeT *addNode(NodeT *node,int x);
NodeT *delNode(NodeT *node,int x);
NodeT *balanceTree(NodeT *node,int rd,int ld);
int depth(NodeT *node);

#endif //ASSIGNMENT_4_AVL_H
