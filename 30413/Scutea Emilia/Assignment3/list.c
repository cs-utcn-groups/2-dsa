#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
NodeT * createBinTree()
{
    NodeT * p;
    char c;
    scanf("%c",&c);
    if(c=='*')
        return NULL;
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        p->label=c;
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}
void initializeList()
{
    first=NULL;
    last=NULL;
}

void addInList(char data)
{
    if(first==NULL)
    {
        first=(NodeL*)malloc(sizeof(NodeL));
        first->label=data;
        first->left=NULL;
        first->right=NULL;
        last=first;
    }
    else
    {
        NodeL * currentElement=(NodeL*)malloc(sizeof(NodeL));
        last->right=currentElement;
        currentElement->left=last;
        currentElement->label=data;
        currentElement->right=NULL;
        last=currentElement;
    }
}
NodeL * getListFromTree(NodeT * p)
{
    if(p!=NULL)
    {
        addInList(p->label);
        getListFromTree(p->left);
        getListFromTree(p->right);
    }
    else
    {
        addInList('*');
    }
    return first;
}
void traverseList(NodeL * p)
{
    while(p!=NULL)
    {
        printf("%c ",p->label);
        p=p->right;
    }
    printf("\n");
}
NodeT * getTreeFromList(NodeL * firstFromList)
{
    NodeT * currentElement;
    if(first->label=='*' || first==NULL)
    {
        first=first->right;
        return NULL;
    }
    else
    {
        currentElement=(NodeT*)malloc(sizeof(NodeT));
        currentElement->label=first->label;
        first=first->right;
        currentElement->left=getTreeFromList(firstFromList->right);
        currentElement->right=getTreeFromList(firstFromList->right);
    }
    return currentElement;
}

void prettyPrint( NodeT *p, int level )
{
    if(p!=NULL)
    {
        prettyPrint(p->left,level+1);
        for(int i=1;i<=level;i++)
            printf(" ");
        printf("%c\n",p->label);
        prettyPrint(p->right,label);
    }
}
