//
// Created by Alina Mihut on 3/22/20.
//
#include "tree.h"
NodeT *createBinTree(){
 char *c=malloc (sizeof(char));

 scanf("%s", c);
 if (strcmp(c,"*")==0)
     return NULL;

 NodeT *p=(NodeT*) malloc (sizeof(NodeT));
 p->id=c[0];
 p->left=createBinTree();
 p->right=createBinTree();
}


void prettyPrint (NodeT *root, int space)
{
    if(root == NULL) return;

    space=space+5;
    prettyPrint (root->right, space);
    printf("\n");
    for(int i=5;i<space;i++)
        printf(" ");
    printf("%c \n", root->id);
    prettyPrint (root->right, space);
}

