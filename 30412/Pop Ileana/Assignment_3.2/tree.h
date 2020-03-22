//
// Created by ileana on 3/21/2020.
//

#ifndef ASSIGNMENT_3_2_TREE_H
#define ASSIGNMENT_3_2_TREE_H


#include "queue.h"
typedef struct nodeT{
    double operand;
    char operator;
    int type;               //type=1 = > operand , 0 otherwise
    struct nodeT * left;
    struct nodeT * right;
}NodeT;

NodeT * createExpressionTree();
void printTree(NodeT * root, int level);
void preOrder(NodeT * currentRoot, int level);

#endif //ASSIGNMENT_3_2_TREE_H
