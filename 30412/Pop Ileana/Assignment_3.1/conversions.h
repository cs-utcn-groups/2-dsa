//
// Created by ileana on 3/21/2020.
//

#ifndef ASSIGNMENT_3_1_CONVERSIONS_H
#define ASSIGNMENT_3_1_CONVERSIONS_H
#include "tree.h"
#include "list.h"

NodeT *getTreeFromList(NodeL *first);
NodeL *getListFromTree(NodeT *root);
void preorder(NodeL **first, NodeT *currentRoot,char givenKey);

#endif //ASSIGNMENT_3_1_CONVERSIONS_H
