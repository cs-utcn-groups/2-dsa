//
// Created by Alina Mihut on 3/22/20.
//

#ifndef ASSIGNMENT_3_TREE_H
#define ASSIGNMENT_3_TREE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node1{
    char id;
    struct node1 *left, *right;
}NodeT;
NodeT *createBinTree();
void prettyPrint (NodeT *root, int space);
#endif //ASSIGNMENT_3_TREE_H
