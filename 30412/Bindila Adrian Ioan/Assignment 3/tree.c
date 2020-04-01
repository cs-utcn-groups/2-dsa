//
// Created by bindi on 3/19/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

tree *createBinaryTree() {
    char *string = malloc(sizeof(char));
    gets(string);
    if (strcmp(string, "*") == 0) {
        return NULL;
    }
    tree *leaf = (tree *) malloc(sizeof(tree));
    leaf->id = string[0];
    leaf->left = createBinaryTree();
    leaf->right = createBinaryTree();
    return leaf;
}

void prettyPrint(tree *root, int level) {
    if (root != NULL) {
        prettyPrint(root->right, level + 1);
        for (int i = 0; i < level; ++i) {
            printf("    ");
        }
        printf("%c\n",root->id);
        prettyPrint(root->left, level + 1);
    }
}