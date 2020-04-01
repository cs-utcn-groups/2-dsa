//
// Created by q on 3/27/2020.
//

#include "delete.h"
/*
 * deleting node, but keeping the balanced property
 */
BSTNodeT * deleteNode(BSTNodeT * root, int key) {
    /*
     * recursive function that deletes node from the tree by key (if it was found)
     * it returns a pointer to the new node (the one that took the place of the deleted one) or NULL (if it was a leaf)
     * it also keeps the tree balanced
     */
    if(root == NULL) {
        return root;
    }
    if(key < root->key) {
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->key) {
        root->right = deleteNode(root->right,key);
    }
    else {
        // node was found
        if (root->left == NULL) {
            BSTNodeT *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNodeT *temp = root->left;
            free(root);
            return temp;
        }
        // replace node to be deleted with its successor
        BSTNodeT *successor = getSuccessor(root);
        // first we replace the value of the current node with its predecessor's
        root->key = successor->key;
        // then we delete the predecessor
        root->right = deleteNode(root->right, successor->key);
    }
    return root;
}

BSTNodeT * getSuccessor(BSTNodeT * node) {
    /*
     * function that returns the successor of the given node
     * successor = leftmost child in right subtree
     */
    BSTNodeT * current = node->right;
    while(current && current->left) {
        current = current->left;
    }
    return current;
}
