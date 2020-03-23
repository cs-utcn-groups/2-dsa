//
// Created by Alina Mihut on 3/23/20.
//
#include "other_functions.h"
NodeL *getListFromTree(NodeT *root) {
    initializeDLL();
    if (root == NULL)
        return NULL;
    else {
        addNode(root->id);
        getListFromTree(root->left);
        if (root->left == NULL) addNode('*');
        getListFromTree(root->right);
        if (root->right == NULL) addNode('*');


        return first;
    }
}
NodeT *getTreeFromList(NodeL *currentElement)
{
    currentElement=first;
    if(first==NULL)
        return NULL;

    if(currentElement->data=='*')
        return NULL;
    else
    {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->id=currentElement->data;
        newNode->left=getTreeFromList(currentElement->next);
        newNode->right=getTreeFromList(currentElement->next);
        return newNode;
    }




}