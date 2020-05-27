//
// Created by acer on 3/10/2020.
//

#ifndef ASSIGNMENT__3_2__OPTREE_H
#define ASSIGNMENT__3_2__OPTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define PADDING_STEP 10

typedef struct _nodeT{
    char *data;
    struct _nodeT *left, *right;
}NodeOT;

NodeOT *createBinTree();
int isOperator(char *key);
void prettyPrint(NodeOT *root, int space);


#endif //ASSIGNMENT__3_2__OPTREE_H
