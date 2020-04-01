//
// Created by bindi on 3/23/2020.
//

#ifndef ASSIGNMENT_3___EXTRA_TREE_H
#define ASSIGNMENT_3___EXTRA_TREE_H
typedef struct _tree {
    char *data;
    struct _tree *left, *right;
} tree;

tree *createBinaryTree(void);

void printTree(tree *root, int level);

#endif //ASSIGNMENT_3___EXTRA_TREE_H
