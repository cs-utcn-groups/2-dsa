//
// Created by ileana on 3/21/2020.
//

#include "conversions.h"



NodeT *getTreeFromListRec(NodeL **first){

    if((*first)->key=='*') {
        *first=(*first)->next;
        return NULL;
    }
    NodeT * p = (NodeT*)malloc(sizeof(NodeT));
    p->id=(*first)->key;
    *first=(*first)->next;
    p->left=getTreeFromListRec(first);
    p->right=getTreeFromListRec(first);
    return p;
}

NodeT *getTreeFromList(NodeL *first)
{
    NodeT * root;
    root=getTreeFromListRec(&first);
    return root;
}

void preorder(NodeL **first, NodeT *currentRoot,char givenKey) {
    if(currentRoot!=NULL)
    {
        givenKey=currentRoot->id;
        addElement(first,givenKey);
        if(currentRoot->left==NULL) {
            givenKey = '*';
            addElement(first,givenKey);
        }
        preorder(first, currentRoot->left,currentRoot->id);
        if(currentRoot->right==NULL) {
            givenKey = '*';
            addElement(first,givenKey);
        }
        preorder(first,currentRoot->right,currentRoot->id);
    }
}

NodeL *getListFromTree(NodeT *root) {
    NodeL * first=(NodeL*)malloc(sizeof(NodeL));
    first= NULL;
    preorder(&first,root,root->id);
    return first;

}