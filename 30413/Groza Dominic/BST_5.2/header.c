//
// Created by Dominic on 3/19/2020.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    char key;
    struct node *left, *right;
} BSTNodeT;

BSTNodeT *createNode(char key) {
    BSTNodeT *p = (BSTNodeT *) malloc(sizeof(BSTNodeT));
    if (p) {
        p->key = key;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

BSTNodeT *insertNode(BSTNodeT *root, char car) {
    int data=(int) car;
    if (root == NULL) {//empty tree
        root = createNode((char)data);
    } else {
        if ((int)root->key < data) {//right subtree
            root->right = insertNode(root->right,(char) data);
        } else if ((int)root->key > data) {//left subtree
            root->left = insertNode(root->left, (char) data);
        } else printf("\n Node already exists \n");
    }
    return root;
}

BSTNodeT *find(BSTNodeT *root, char car) {
    int key=(int)car;
    if (root == NULL) {
        printf("tree is empty");
        return NULL;
    }
    for (BSTNodeT *p = root; p != NULL;) {
        if (key==(int)p->key) return p;
        else
        if (key<(int) p->key) p=p->left;
        else p=p->right;
    }
    return NULL;
}

void preorder(BSTNodeT *p){
    if (p!=NULL){
        printf("%c\n",p->key);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(BSTNodeT *p){
    if (p!=NULL){
        inorder(p->left);
        printf("%c\n",p->key);
        inorder(p->right);
    }
}

void postorder(BSTNodeT *p){
    if (p!=NULL){
        postorder(p->left);
        postorder(p->left);
        printf("%c\n",p->key);
    }
}

BSTNodeT *findMin(BSTNodeT *node){
    if (node==NULL){
        return NULL;
    }
    if (node->left)
        findMin(node->left);
    else return node;
}

BSTNodeT *findMax(BSTNodeT *node){
    if (node==NULL){
        return NULL;
    }
    if (node->right)
        findMax(node->right);
    else return node;
}

BSTNodeT *deleteNode (BSTNodeT *node, char car) {
    int key=(int)car;
    if (node == NULL) {
        printf("Element not found");
    } else if (key < (int)node->key) {//left subtree
        node->left = deleteNode(node->left,(char) key);
    } else if (key > (int) node->key) {//right subtree
        node->right = deleteNode(node->right,(char) key);
    } else
        //we found the node, replace either min from right subtree or max from left subtree
    if (node->right && node->left) {
        BSTNodeT *temp = findMax(node->left);
        node->key = temp->key;
        node->left = deleteNode(node->left, temp->key);
    } else {
        //one or zero children => remove it from tree and connect its parent to its child
        BSTNodeT *temp = node;
        if (node->left == NULL)
            node = node->right;
        else if (node->right == NULL)
            node = node->left;
        free(temp);
    }

    return node;
}