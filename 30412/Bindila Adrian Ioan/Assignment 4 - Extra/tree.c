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

tree *getSuccessor(tree *root) {
    tree *current = root->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
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

tree *adjustBalanceInsert(tree *root, double key) {
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

tree *adjustBalanceDelete(tree *root) {
    ///fix any inbalances
    int balanceFactor = getBalanceFactor(root);
    int lBalanceFactor = getBalanceFactor(root->left);
    int rBalanceFactor = getBalanceFactor(root->right);
    if (balanceFactor > 1 && lBalanceFactor >= 0) {
        ///left left case
        return rotateRight(root);
    }
    if (balanceFactor > 1 && lBalanceFactor < 0) {
        ///left right case
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balanceFactor < -1 && rBalanceFactor >= 0) {
        ///right left case
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    if (balanceFactor < -1 && rBalanceFactor < 0) {
        ///right right case
        return rotateLeft(root);
    }

    ///if no adjustments are needed:
    return root;
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

    return adjustBalanceInsert(root, key);
}

tree *balancedDelete(tree *root, double key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        ///go left
        root->left = balancedDelete(root->left, key);
    } else if (key > root->key) {
        ///go right
        root->right = balancedDelete(root->right, key);
    } else {
        ///found it
        if (root->left == NULL) {
            ///one right child or no child
            tree *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            ///one left child or no child
            tree *temp = root->left;
            free(root);
            return temp;
        }

        tree *temp = getSuccessor(root);
        root->key = temp->key;
        root->right = balancedDelete(root->right, temp->key);
    }

    ///update the height after the deletion
    root->height = __max(getHeight(root->left), getHeight(root->right)) + 1;
    ///check and adjust any imbalances
    return adjustBalanceDelete(root);
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



