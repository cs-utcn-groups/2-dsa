//
// Created by q on 3/24/2020.
//

#include "bst.h"

void errMessage() {
    perror(ERR_MEM_ALLOC);
    exit(EXIT_FAILURE);
}
BSTNodeT * createNode(int key) {
    // function that creates a new node
    BSTNodeT * n = (BSTNodeT*)malloc(sizeof(BSTNodeT));
    if(!n) {
        errMessage();
    }
    else {
        n->key = key;
        // new node is initially added as a leaf
        n->height = 1;
        n->right = n->left = NULL;
    }
    return n;
}

void printBST(BSTNodeT * root, int level) {
    // function that prints the BST, traversing it post order
    if(root) {
        for(int i=0;i<=level ;i++)
            printf("    ");
        printf("%d\n", root->key);
        printBST(root->left, level + 1);
        printBST(root->right, level + 1);
    }
}

void freeBST(BSTNodeT * root) {
    // function that recursively frees the memory allocated to the tree
    if(root) {
        freeBST(root->left);
        freeBST(root->right);
        BSTNodeT * temp = root;
        free(temp);
    }
}

BSTNodeT * getParent(BSTNodeT * root, int key) {
    /*
     * recursive function that returns the parent of the node given by its key
     */
    if(root == NULL) {
        return NULL;
    }
    if(root->key < key) {
        return getParent(root->left,key);
    }
    else if (root->key > key) {
        return getParent(root->right,key);
    }
    else if(hasChildren(root,key)) {
        // check is this node has actually a child with given key
        return root;
    }
}
bool hasChildren(BSTNodeT * node, int key) {
    // function that checks if the give node has a child with given key
    if((node->left != NULL && node->left->key == key) || (node->right != NULL && node->right->key == key)) {
        return true;
    }
    return false;
}


bool findNode(BSTNodeT * root, int key) {
    // function that finds a node in the tree, given its key
    // return true when found, otherwise false
    if(root == NULL) {
        return false;
    }
    if( root->key == key) {
        return true;
    }
    else if(key < root->key) {
        return findNode(root->left,key);
    }
    else if (key > root->key) {
        return findNode(root->right,key);
    }
}

void printFound(BSTNodeT * root, int key) {
    /*
     * function that calls the findNode function and evaluates its return value,
     * displaying the corresponding message
     */
    if(findNode(root, key)) {
        printf("Element %d was found.\n",key);
    }
    else {
        printf("Element %d was not found.\n",key);
    }
}

int height(BSTNodeT * node) {
    // function that returns tha height of a node or 0, if it's null
    if(node == NULL) {
        return 0;
    }
    return node->height;
}

int max(int A, int B) {
    // function that returns the maximum of the two numbers
    return (A>B) ? A : B;
}