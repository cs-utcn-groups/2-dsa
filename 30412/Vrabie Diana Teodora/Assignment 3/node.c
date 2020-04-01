
#include "node.h"
#include <stdio.h>
#include <string.h>

TreeNode *readBinaryTree() {
    char *inputChar = malloc(sizeof(char));
    scanf("%s", inputChar);
    if (strcmp(inputChar, "*") == 0) {
        return NULL;
    }

    TreeNode *myNode = (TreeNode *) malloc(sizeof(TreeNode));
    myNode->value = inputChar[0];
    free(inputChar);
    myNode->leftChild = readBinaryTree();
    myNode->rightChild = readBinaryTree();
    return myNode;
}



ListNode *initializeEmptyNode() {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    return node;
}

