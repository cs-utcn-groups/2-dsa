#include "head.h"

NodeT *createBinTree()
{
    NodeT *p;
    char c;
    scanf("%c",&c);
    if(c=='*')
    {
        return NULL;
    }
    p=(NodeT*)malloc(sizeof(NodeT));
    if(p==NULL)
    {
        printf("Out of space\n");
        exit(1);
    }
    p->data=c;
    p->left=createBinTree();
    p->right=createBinTree();
    return p;
}
void addToList(char c)
{
    if(first==NULL)
    {
        first=(NodeL*)malloc(sizeof(NodeL));
        first->data=c;
        first->next=NULL;
        first->previous=NULL;
        last=first;
    }
    else
    {
        currentElement=(NodeL*)malloc(sizeof(NodeL));
        currentElement->data=c;
        currentElement->next=NULL;
        currentElement->previous=last;
        last->next=currentElement;
        last=currentElement;
    }
}
NodeL *getListFromT(NodeT *root)
{
    if(root)
    {
        addToList(root->data);
        getListFromT(root->left);
        getListFromT(root->right);
    }
    else
    {
        addToList('*');
    }
    return first;
}
void traverseList(NodeL *first)
{
    if(first)
    {
        currentElement=first;
        while(currentElement)
        {
            printf("%c ",currentElement->data);
            currentElement=currentElement->next;
        }
    }
    else
        printf("Empty list");
    printf("\n\n");
}
NodeT *getTreeFromList(NodeL *first)
{
    NodeT *p;
    if(first->data=='*')
    {
        return NULL;
    }
    p=(NodeT*)malloc(sizeof(NodeT));
    if(p==NULL)
    {
        printf("Out of space\n");
        exit(1);
    }
    p->data=first->data;
    while(first->beenHere==1)
    {
        first=first->next;
    }
    first->beenHere=1;
    p->left=getTreeFromList(first->next);
    while(first->beenHere==1)
    {
        first=first->next;
    }
    first->beenHere=1;
    p->right=getTreeFromList(first->next);
    return p;
}
void prettyPrint(NodeT *p, int level)
{
    if(p)
    {
        prettyPrint(p->left,level+1);
        for(int i=0; i<=level; i++)
        {
            printf(" ");
        }
        printf("%c\n",p->data);
        prettyPrint(p->right,level+1);
    }
}
