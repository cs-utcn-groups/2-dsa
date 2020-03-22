//
// Created by ileana on 3/21/2020.
//

#ifndef ASSIGNMENT_3_1_TREE_H
#define ASSIGNMENT_3_1_TREE_H

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "list.h"

typedef struct node{
    char id;
    struct node *left,*right;
}NodeT;

FILE * fin;

NodeT *createBinTree();
void prettyPrint(NodeT *currentRoot, int level);



#endif //ASSIGNMENT_3_1_TREE_H

