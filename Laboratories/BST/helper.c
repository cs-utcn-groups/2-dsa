//
// Created by Alex on 3/23/2020.
//
#include "head.h"

void prettyPrint(NodeT *root, int space) {
    {
        if (root == NULL) {
            return;
        }
        space += COUNT;
        prettyPrint(root->right, space);
        printf("\n");
        for (int i = COUNT; i < space; i++)
            printf(" ");
        printf("%d", root->key);
        prettyPrint(root->left, space);
    }
}
