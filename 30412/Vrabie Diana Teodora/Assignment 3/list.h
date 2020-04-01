//
// Created by diana on 24/03/2020.
//

#ifndef ASSIGNMENT_3_LIST_H
#define ASSIGNMENT_3_LIST_H

#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct list {
    int nrOfMembers;
    ListNode *first;
    ListNode *last;
} List;

List *initializeList();

void addElementToEnd(char data, List *list);

void printDLList(List *myList);

void createDLListFromTree(TreeNode *treeNode, List *list);

TreeNode *createTreeFromList(ListNode *listNode);

void printPretty(TreeNode *root, int level);

#endif //ASSIGNMENT_3_LIST_H
