//
// Created by Ivan on 3/23/2020.
//

#ifndef LAB3_TREES__FUNC_H
#define LAB3_TREES__FUNC_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
    char id;
    struct node *left;
    struct node *right;
}NodeT;
FILE *f;
NodeT *head;

NodeT *createBinTree();
void createListFromTree(NodeT *root, NodeT **head);
NodeT* createTreeFromList(int size);
void prettyPrint (NodeT *root, int level);
int sizeOfDll(NodeT* root);
void traverse(NodeT* root);

#endif //LAB3_TREES__FUNC_H
