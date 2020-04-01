//
// Created by Bori on 3/24/2020.
//

#ifndef ASSIGNMENT4_AVL_TREE_AVLTREE_H
#define ASSIGNMENT4_AVL_TREE_AVLTREE_H

#include <stdio.h>

typedef struct _AVLTree {
    int rootData;
    struct _AVLTree *left, *right;
    int height, balanceFactor;
} AVLTree;

AVLTree *createEmptyAVLTree();

AVLTree createAVLTree(int data);

void inOrder(AVLTree *myTree, FILE *outFile);

void insertNode(AVLTree **myTree, int data);

void deleteNode(AVLTree **myTree, int data);

#endif //ASSIGNMENT4_AVL_TREE_AVLTREE_H
