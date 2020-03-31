//
// Created by bindi on 3/26/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree *createLeaf(double key) {
    tree *leaf = (tree *) malloc(sizeof(tree));
    leaf->key = key;
    leaf->height = 1;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}

int getHeight(tree *root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(tree *root) {
    if (root == NULL) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

tree *rotateLeft(tree *root) {
    tree *rChild = root->right;
    tree *lGrandChild = rChild->left;

    rChild->left = root;
    root->right = lGrandChild;

    rChild->height = __max(getHeight(rChild->left), getHeight(rChild->right)) + 1;
    root->height = __max(getHeight(root->left), getHeight(root->right)) + 1;
    return rChild;
}

tree *rotateRight(tree *root) {
    tree *lChild = root->left;
    tree *rGrandChild = lChild->right;

    lChild->right = root;
    root->left = rGrandChild;

    lChild->height = __max(getHeight(lChild->left), getHeight(lChild->right)) + 1;
    root->height = __max(getHeight(root->left), getHeight(root->right)) + 1;
    return lChild;
}

tree *balancedInsert(tree *root, double key) {
    ///decided to use the recursive insertion as it makes it easier to update the heights

    if (root == NULL) {
        tree *leaf = createLeaf(key);
        return leaf;
    }
    if (root->key > key) {
        root->left = balancedInsert(root->left, key);
    } else if (root->key < key) {
        root->right = balancedInsert(root->right, key);
    } else {
        printf("%lf already exists in the tree!", key);
    }

    root->height = __max(getHeight(root->left), getHeight(root->right)) + 1;

    ///fix any inbalances
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && key < root->left->key) {
        ///left left case
        return rotateRight(root);
    }
    if (balanceFactor > 1 && key > root->left->key) {
        ///left right case
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balanceFactor < -1 && key < root->right->key) {
        ///right left case
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    if (balanceFactor < -1 && key > root->right->key) {
        ///right right case
        return rotateLeft(root);
    }

    ///if no adjustments are needed:
    return root;
}

void printTree(tree *root, int level) {
    if (root != NULL) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; ++i) {
            printf("      ");
        }
        printf("%.2lf\n", root->key);
        printTree(root->left, level + 1);
    }
}



