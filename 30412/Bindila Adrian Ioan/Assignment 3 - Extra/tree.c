//
// Created by bindi on 3/23/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define MAX_LINE_LENGTH 64

tree *createBinaryTree(void) {
    char *string = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    scanf("%s", string);
    tree *leaf = (tree *) malloc(sizeof(tree));
    leaf->data = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    if ((string[0] > '0' && string[0] < '9') || (string[1] > '0' && string[1] < '9')) {///is a number
        ///we notice that numbers have the same role as * in a regular tree:
        ///numbers are terminal nodes
        strcpy(leaf->data, string);
        leaf->left = NULL;
        leaf->right = NULL;
        return leaf;
    }
    strcpy(leaf->data, string);
    leaf->left = createBinaryTree();
    leaf->right = createBinaryTree();
    return leaf;
}

void printTree(tree *root, int level) {
    ///I really don't know how to get that formatting right, so I have come up with a more primitive one
    if (root != NULL) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; ++i) {
            printf("      ");
        }
        printf("%s\n",root->data);
        printTree(root->left, level + 1);
    }
}
