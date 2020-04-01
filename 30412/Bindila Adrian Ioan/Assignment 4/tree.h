//
// Created by bindi on 3/26/2020.
//

#ifndef ASSIGNMENT_4_TREE_H
#define ASSIGNMENT_4_TREE_H
typedef struct _tree {
    double key;
    int height;
    struct _tree *left, *right;
} tree;

tree *createLeaf(double key);

int getHeight(tree *root);

int getBalanceFactor(tree *root);

tree *rotateLeft(tree *root);

tree *rotateRight(tree *root);

tree *balancedInsert(tree *root, double key);

tree *adjustBalance(tree *root, double key);

void printTree(tree *root, int level);


#endif //ASSIGNMENT_4_TREE_H
