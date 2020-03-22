//
// Created by ileana on 3/21/2020.
//


#include "tree.h"

NodeT *createBinTree() {
    char * c= malloc(sizeof(char));
    fscanf(fin,"%s",c);
    if(strcmp(c,"*")==0)
        return NULL;
    NodeT * p = (NodeT*)malloc(sizeof(NodeT));
    p->id=c[0];
    p->left=createBinTree();
    p->right=createBinTree();
    return p;
}

void prettyPrint(NodeT *currentRoot, int level) {
    if(currentRoot!=NULL)
    {
        prettyPrint(currentRoot->right,level+1);
        for(int i=0;i< 7*level;i++)
            printf(" ");
        printf("%c",currentRoot->id);
        printf("\n");
        prettyPrint(currentRoot->left,level+1);
    }
}

