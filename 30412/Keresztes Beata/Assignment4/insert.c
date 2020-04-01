//
// Created by q on 3/27/2020.
//

#include "insert.h"

BSTNodeT * constructBST(FILE * fp) {
    // function that constructs a BST with the values read from an input file
    BSTNodeT * root = NULL;
    int key;
    while(!feof(fp)) {
        fscanf(fp,"%d",&key);
        root = insert(root,key);
    }
    return root;
}
BSTNodeT * insert(BSTNodeT * root, int key) {
    /*
  * function that inserts a new node to the tree
  * while it respects the property of a balanced tree
  */
    BSTNodeT * new = createNode(key);
    if(root == NULL) {
        // if tree is empty, then a single node is created
        return new;
    }
    if(key < root->key) {
        root->left = insert(root->left,key);
    }
    else if(key > root->key) {
        root->right = insert(root->right,key);
    }
    else {
        printf("Element %d already exists.\n",key);
        // free memory if node was not added
        free(new);
    }

    // calculate height of root
    root->height = computeHeight(root);

    // re-balance tree if it's the case
    root = reBalanceTree(root,key);

    return root;
}
BSTNodeT * reBalanceTree(BSTNodeT * root, int key) {
    /*
    * function to re-establish the balance of the tree
    * returns the root of the generated balanced tree
    */

    // get balance of the current subtree
    int balance = computeBalance(root);

    // perform rotations when needed to re-balance the tree
        if (balance > 1 && key < root->left->key) {
            root = rightRotate(root);
        }
        if (balance > 1 && key > root->key) {
            root->right = leftRotate(root);
            root = rightRotate(root);
        }
        if (balance < -1 && key > root->right->key) {
            root = leftRotate(root);
        }
        if (balance < -1 && key < root->key) {
            root->left = rightRotate(root);
            root->right = leftRotate(root);
        }

    return root;
}
/*
 * BST rotation functions => keep balanced nature of tree
 * *  R = right rotate
 * *  RL = right-left rotate
 * *  LR = left-right rotate
 * *  L = left rotate
 */

BSTNodeT * rightRotate(BSTNodeT * node) {
    /*
     * function that rotates the tree to the right
     * returns pointer to the new root
     */
    BSTNodeT * replaceNode = node->left;
    node->left = replaceNode->right;
    replaceNode->right = node;
    // update heights
    node->height = computeHeight(node);
    replaceNode->height = computeHeight(replaceNode);
    // return new root
    return replaceNode;
}

BSTNodeT * leftRotate(BSTNodeT * node) {
    /*
     * function that rotates the tree to the right
     * returns pointer to the new root
     */
    BSTNodeT * replaceNode = node->right;
    node->right = replaceNode->left;
    replaceNode->left = node;
    // update heights
    node->height = computeHeight(node);
    replaceNode->height = computeHeight(replaceNode);
    // return new root
    return replaceNode;
}

int computeHeight(BSTNodeT * node) {
    // function that return height of the given node
    return 1 + max(height(node->left),height(node->right));
}

int computeBalance(BSTNodeT * root) {
    // function that returns the balance of the given root
    return height(root->left) - height(root->right);
}