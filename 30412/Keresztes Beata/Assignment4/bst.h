//
// Created by q on 3/24/2020.
//

#ifndef ASSIGNMENT4_BST_H
#define ASSIGNMENT4_BST_H

#endif //ASSIGNMENT4_BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ERR_MEM_ALLOC " Error allocating memory"

typedef struct node {
    int key;
    int height;
    struct node * left, * right;
}BSTNodeT;

/*
 * creating BST
 */
// function that creates a new node
BSTNodeT * createNode(int key);
// function that returns error message when memory was not allocated correctly
void errMessage();

// function that prints the tree
void printBST(BSTNodeT * root, int level);
// function that frees the BST
void freeBST(BSTNodeT * root);

// function that returns the parent of the node given by key
BSTNodeT * getParent(BSTNodeT * root, int key);
// function that checks if the give node has a child with given key
bool hasChildren(BSTNodeT * node, int key);

// function that finds a node in the tree, given its key
bool findNode(BSTNodeT * root, int key);
// function that prints the corresponding message whether the key was found in the tree
void printFound(BSTNodeT * root, int key);

// function that returns the height of each node
int height(BSTNodeT * node);
// function that returns the maximum of the 2 numbers
int max(int A, int B);
