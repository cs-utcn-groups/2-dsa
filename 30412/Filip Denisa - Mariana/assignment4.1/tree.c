//
// Created by Denisa on 3/26/2020.
//

#include "tree.h"

NodeT *createNode(int key) {
    NodeT *node = (NodeT *) malloc(sizeof(NodeT));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void prettyPrintUtil(NodeT *currentRoot, int space) {
    if (currentRoot != NULL) {
        space += COUNT;
        prettyPrintUtil(currentRoot->right, space);
        printf("\n");
        for (int i = COUNT; i < space; i++) {
            printf(" ");
        }
        printf("%d\n", currentRoot->key);
        prettyPrintUtil(currentRoot->left, space);
    }
}

void prettyPrint(NodeT *currentRoot) {
    prettyPrintUtil(currentRoot, 0);
}

int height(NodeT *currentNode) {
    if (currentNode == NULL) {
        return 0;
    }
    return currentNode->height;
}

int getMaximum(int a, int b) {
    return (a > b) ? a : b;
}

int computeBalance(NodeT *currentNode) {
    if (currentNode == NULL) {
        return 0;
    }
    return height(currentNode->left) - height(currentNode->right);
}

int getHeight(NodeT *currentNode) {
    return 1 + getMaximum(height(currentNode->left), height(currentNode->right));
}

NodeT *rightRotate(NodeT *currentRoot) {
    NodeT *leftRoot = currentRoot->left;

    currentRoot->left = leftRoot->right;
    leftRoot->right = currentRoot;

    currentRoot->height = getHeight(currentRoot);
    leftRoot->height = getHeight(leftRoot);

    return leftRoot;
}

NodeT *leftRotate(NodeT *currentRoot) {
    NodeT *rightRoot = currentRoot->right;

    currentRoot->right = rightRoot->left;
    rightRoot->left = currentRoot;

    currentRoot->height = getHeight(currentRoot);
    rightRoot->height = getHeight(rightRoot);

    return rightRoot;
}

NodeT *insert(NodeT *currentRoot, int key) {
    NodeT *node = createNode(key);
    if (currentRoot == NULL) {
        return node;
    }

    if (key < currentRoot->key) {
        currentRoot->left = insert(currentRoot->left, key);
    } else if (key > currentRoot->key) {
        currentRoot->right = insert(currentRoot->right, key);
    } else {
        printf("Key %d already in tree!", key);
        free(node);
    }

    currentRoot = transformIntoBalancedTree(currentRoot, key);
    return currentRoot;
}

bool find(NodeT *currentRoot, int key) {
    if (currentRoot == NULL) {
        return false;
    } else {
        if (currentRoot->key == key) {
            return true;
        } else {
            if (key < currentRoot->key) {
                return find(currentRoot->left, key);
            } else {
                return find(currentRoot->right, key);
            }
        }
    }
}

void findWithPrint(NodeT *currentRoot, int key) {
    printf(find(currentRoot, key) ? "Element %d found!\n" : "Element %d not found!\n", key);
}

NodeT *getSuccessor(NodeT *node) {
    NodeT *currentNode = node->right;
    while (currentNode && currentNode->left) {
        currentNode = currentNode->left;
    }
    return currentNode;
}

NodeT *delete(NodeT *currentRoot, int key) {
    //if the tree has no nodes
    if (currentRoot == NULL) {
        return currentRoot;
    }
    if (key < currentRoot->key) {
        currentRoot->left = delete(currentRoot->left, key);
    } else if (key > currentRoot->key) {
        currentRoot->right = delete(currentRoot->right, key);
    } else {
        //the element with the right key was found;
        if (currentRoot->left == NULL) {
            NodeT *temp = currentRoot->right;
            free(currentRoot);
            return temp;
        } else if (currentRoot->right == NULL) {
            NodeT *temp = currentRoot->left;
            free(currentRoot);
            return temp;
        } else {
            NodeT *successor = getSuccessor(currentRoot);
            currentRoot->key = successor->key;
            currentRoot->right = delete(currentRoot->right, successor->key);
        }
    }

    currentRoot = transformIntoBalancedTree(currentRoot, key);
    return currentRoot;
}

NodeT *transformIntoBalancedTree(NodeT *currentRoot, int key) {
    currentRoot->height = getHeight(currentRoot);
    int balance = computeBalance(currentRoot);

    //left left case
    if (balance > 1 && key < currentRoot->left->key) {
        currentRoot = rightRotate(currentRoot);
    }

    //left right case
    if (balance > 1 && key > currentRoot->left->key) {
        currentRoot->left = leftRotate(currentRoot->left);
        currentRoot = rightRotate(currentRoot);
    }

    //right right case
    if (balance < -1 && key > currentRoot->right->key) {
        currentRoot = leftRotate(currentRoot);
    }

    //right left case
    if (balance < -1 && key < currentRoot->right->key) {
        currentRoot->right = rightRotate(currentRoot->right);
        currentRoot = leftRotate(currentRoot);
    }
    return currentRoot;
}
