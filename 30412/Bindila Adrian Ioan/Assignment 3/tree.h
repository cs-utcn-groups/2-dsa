//
// Created by bindi on 3/19/2020.
//

#ifndef ASSIGNMENT_3_TREE_H
#define ASSIGNMENT_3_TREE_H
typedef struct _tree {
    char id;
    struct _tree *left, *right;
} tree;

tree *createBinaryTree();

void prettyPrint(tree *root, int level);

#endif //ASSIGNMENT_3_TREE_H
