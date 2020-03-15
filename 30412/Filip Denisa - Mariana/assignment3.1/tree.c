//
// Created by Denisa on 3/14/2020.
//

#include "tree.h"

NodeT *createTreeNode() {
    NodeT *node = (NodeT *) malloc(sizeof(NodeT));
    node->id = (char *) malloc(sizeof(char));
    node->left = NULL;
    node->right = NULL;
    return node;
}

NodeT *createBinTree() {
    char *c = (char *) malloc(sizeof(char));
    scanf("%s", c);
    if (strcmp(c, "*") == 0) {
        return NULL;
    }
    NodeT *currentNode = createTreeNode();
    strcpy(currentNode->id, c);
    currentNode->left = createBinTree();
    currentNode->right = createBinTree();
    free(c);
    return currentNode;
}

void prettyPrint(NodeT *currentRoot, int level) {
    if (currentRoot != NULL) {
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        printf("%s", currentRoot->id);
        prettyPrint(currentRoot->left, level + 1);
        prettyPrint(currentRoot->right, level + 1);
    }
}