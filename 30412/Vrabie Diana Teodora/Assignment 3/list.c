//
// Created by diana on 24/03/2020.
//

#include "list.h"

List *initializeList() {
    List *myList = (List *) malloc(sizeof(List));
    myList->nrOfMembers = 0;
    myList->first = NULL;
    myList->last = NULL;
    return myList;
}

void printDLList(List *myList) {
    if (myList->nrOfMembers == 0) {
        return;
    }
    ListNode *node = myList->first;
    while (node != NULL) {
        printf("%c ", node->value);
        node = node->nextNode;
    }
    printf("\n");
}

void addElementToEnd(char data, List *list) {
    if (list->last == NULL) {
        list->first = initializeEmptyNode();
        list->last = initializeEmptyNode();
        list->last->value = data;
        list->last->nextNode = NULL;
        list->last->prevNode = NULL;
        list->first = list->last;
        list->nrOfMembers = 1;
    } else {
        ListNode *newNode = initializeEmptyNode();
        newNode->value = data;
        newNode->nextNode = NULL;
        newNode->prevNode = list->last;
        list->last->nextNode = newNode;
        list->last = newNode;
        list->nrOfMembers++;
    }
}

void createDLListFromTree(TreeNode *treeNode, List *list) {
    if (treeNode != NULL) {
        addElementToEnd(treeNode->value, list);
        if (treeNode->leftChild == NULL) {
            addElementToEnd('*', list);
        }
        if (treeNode->rightChild == NULL) {
            addElementToEnd('*', list);
        }
        createDLListFromTree(treeNode->leftChild, list);
        createDLListFromTree(treeNode->rightChild, list);
    }
}

TreeNode *createTreeFromList(ListNode *listNode) {
    if (listNode->value == '*')
        return NULL;

    TreeNode *myNode = (TreeNode *) malloc(sizeof(TreeNode));
    myNode->value = listNode->value;
    myNode->leftChild = readBinaryTree();
    myNode->rightChild = readBinaryTree();
    return myNode;
}

void printPretty(TreeNode *root, int level) {
    if (root != NULL) {
        printPretty(root->rightChild, level + 1);
        for (int i = 0; i <= level; i++) {
            printf("  ");
        }
        printf("%c\n", root->value);
        printPretty(root->leftChild, level + 1);
    }
}