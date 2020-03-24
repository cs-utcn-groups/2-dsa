//
// Created by Bori on 3/24/2020.
//

#include "AVLTree.h"
#include <stdlib.h>
#include <minmax.h>
#include <math.h>
#include <stdbool.h>

AVLTree *createEmptyAVLTree() {
    AVLTree *myTree = NULL;
    return myTree;
}

AVLTree *createAVLTreeWithData(int data) {
    AVLTree *newTree = (AVLTree *) malloc(sizeof(AVLTree));
    newTree->rootData = data;
    newTree->left = NULL;
    newTree->right = NULL;
    newTree->height = 1;
    newTree->balanceFactor = 0;
    return newTree;
}

static void inOrderHelper(AVLTree *myTree, int level, FILE *outFile) {
    if (myTree != NULL) //existing node
    {
        inOrderHelper(myTree->left, level + 1, outFile);
        for (int i = 1; i <= level; i++) fprintf(outFile, "    ");
        fprintf(outFile, "%d(%d)\n", myTree->rootData, myTree->balanceFactor);
        inOrderHelper(myTree->right, level + 1, outFile);
    }
}

void inOrder(AVLTree *myTree, FILE *outFile) {
    inOrderHelper(myTree, 0, outFile);
}

static int getTreeHeight(AVLTree *myTree) {
    if (myTree == NULL) return 0;
    else return myTree->height;
}

static void recalculateHeight(AVLTree *myTree) {
    myTree->height = max(getTreeHeight(myTree->left), getTreeHeight(myTree->right)) + 1;
}

static void recalculateBalanceFactor(AVLTree *myTree) {
    myTree->balanceFactor = getTreeHeight(myTree->left) - getTreeHeight(myTree->right);
}

static void recalculateBalanceData(AVLTree *myTree) {
    recalculateHeight(myTree);
    recalculateBalanceFactor(myTree);
}

static bool balanced(AVLTree *myTree) {
    return abs(myTree->balanceFactor) <= 1;
}

static void swap(int *a, int *b) {
    int c = *b;
    *b = *a;
    *a = c;
}

static void rotateRight(AVLTree *myTree) {
    swap(&myTree->rootData,
         &myTree->left->rootData); //i swapped just the data of those two in ordder to avoid changing pointers
    AVLTree *leftChild = myTree->left;
    myTree->left = myTree->left->left;
    leftChild->left = leftChild->right;
    leftChild->right = myTree->right;
    myTree->right = leftChild;
    recalculateBalanceData(myTree->right);
    recalculateBalanceData(myTree);
}

static void rotateLeft(AVLTree *myTree) {
    swap(&myTree->rootData,
         &myTree->right->rootData); //i swapped just the data of those two in ordder to avoid changing pointers
    AVLTree *rightChild = myTree->right;
    myTree->right = myTree->right->right;
    rightChild->right = rightChild->left;
    rightChild->left = myTree->left;
    myTree->left = rightChild;
    recalculateBalanceData(myTree->left);
    recalculateBalanceData(myTree);
}

static void balanceTree(AVLTree *myTree) {
    if (myTree->balanceFactor > 1) {
        if (myTree->left->balanceFactor < 0) {
            rotateLeft(myTree->left);
        }
        rotateRight(myTree);
    } else if (myTree->balanceFactor < -1) {
        if (myTree->right->balanceFactor > 0) {
            rotateRight(myTree->right);
        }
        rotateLeft(myTree);
    }
}

void insertNode_existingTree(AVLTree *myTree, int data) {
    if (myTree == NULL) myTree = createAVLTreeWithData(data);
    if (myTree->rootData > data) {
        if (myTree->left == NULL) myTree->left = createAVLTreeWithData(data);
        else insertNode_existingTree(myTree->left, data);
    } else if (myTree->rootData < data) {
        if (myTree->right == NULL) myTree->right = createAVLTreeWithData(data);
        else insertNode_existingTree(myTree->right, data);
    }

    recalculateHeight(myTree);
    recalculateBalanceFactor(myTree);

    if (!balanced(myTree)) balanceTree(myTree);
}

void insertNode(AVLTree **myTree, int data) {
    if (*myTree == NULL) *myTree = createAVLTreeWithData(data);
    else insertNode_existingTree(*myTree, data);
}

int predecessor(AVLTree *myTree) { //given that myTree->left!=NULL
    AVLTree *curTree = myTree->left;
    while (curTree->right != NULL) {
        curTree = curTree->right;
    }
    return curTree->rootData;
}

void deleteNode(AVLTree **treeAddress, int data) {
    AVLTree *myTree = *treeAddress; //just to make writing easier
    if (myTree != NULL) {
        if (myTree->rootData > data) {
            deleteNode(&myTree->left, data);
        } else if (myTree->rootData < data) {
            deleteNode(&myTree->right, data);
        } else { //case: node found
            if (myTree->left == NULL && myTree->right == NULL) {
                free(myTree);
                *treeAddress = NULL;
            } else if (myTree->left == NULL) {
                *treeAddress = myTree->right;
            } else if (myTree->right == NULL) {
                *treeAddress = myTree->left;
            } else {
                int predecessorData = predecessor(myTree);
                myTree->rootData = predecessorData;
                deleteNode(&myTree->left, predecessorData);
            }
        }

        if(*treeAddress!=NULL) {
            recalculateHeight(myTree);
            recalculateBalanceFactor(myTree);
            if (!balanced(myTree)) balanceTree(myTree);
        }
    }
}
