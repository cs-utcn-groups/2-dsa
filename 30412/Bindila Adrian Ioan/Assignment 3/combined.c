//
// Created by bindi on 3/19/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "tree.h"

list *getListFromTree(tree *root) {
    if (root != NULL) {
        addElementLast(root->id);
        getListFromTree(root->left);
        if (root->left == NULL) {
            ///found a leaf
            addElementLast('*');
        }
        getListFromTree(root->right);
        if(root->right == NULL){
            ///found a terminal leaf
            addElementLast('*');
        }
    }
    return firstElement;
}

tree *getTreeFromList(list *currentElement) {
    currentElement=firstElement;
    firstElement=firstElement->next;
    if (currentElement->data=='*') {
        return NULL;
    }
    tree *leaf = (tree *) malloc(sizeof(tree));
    leaf->id = currentElement->data;
    leaf->left = getTreeFromList(firstElement);
    leaf->right = getTreeFromList(firstElement);
    return leaf;
}