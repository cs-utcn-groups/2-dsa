//
// Created by q on 3/27/2020.
//

#ifndef ASSIGNMENT4_INSERT_H
#define ASSIGNMENT4_INSERT_H

#endif //ASSIGNMENT4_INSERT_H

#include "bst.h"

// function to construct a BST tree
BSTNodeT * constructBST(FILE * fp);
// function that inserts a new node to the BST tree, keeping te property of a balanced tree
BSTNodeT * insert(BSTNodeT * root, int key);
// function to re-balance the tree
BSTNodeT * reBalanceTree(BSTNodeT * root, int key);
/*
 * rotation functions
 */
// right rotate
BSTNodeT * rightRotate(BSTNodeT * node);
// left rotate
BSTNodeT * leftRotate(BSTNodeT * node);
// function that computes the height of the given node
int computeHeight(BSTNodeT * node);
// function that computes the balance of the given root
int computeBalance(BSTNodeT * root);
