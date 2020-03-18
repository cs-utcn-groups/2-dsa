#include "head.h"
NodeL *first=NULL, *last=NULL;

NodeT *createBinTree(int branch, NodeT *parent, FILE *f)
{
    NodeT *p;
    int data;
    /*if(branch==0)
        printf("Root identifier is ");
    else if(branch==1)
        printf("Left child of %d is ",parent->data);
    else
        printf("Right child of %d is ",parent->data);*/

    fscanf(f,"%d",&data);

    if(data==NULL)
        return;
    else
    {
        p=(NodeT *)malloc(sizeof(NodeT));
        if(p==NULL)
            printf("Out of space in createBinTree!");
        p->data=data;
        p->left=createBinTree(1,p,f);
        p->right=createBinTree(2,p,f);
    }
    return p;
}

NodeL *getListFromTree(NodeT *node)
{
    if(node!=NULL)
    {
        if(first==NULL)
        {
            first=(NodeL*)malloc(sizeof(NodeL));
            first->prev=NULL;
            first->next=NULL;
            first->value=node->data;
            last=first;
        }
        else
        {
            NodeL *newEl=(NodeL *)malloc(sizeof(NodeL));
            newEl->next=NULL;
            newEl->prev=last;
            if(node->left==NULL && node->right==NULL)
            {
                newEl->leaves="*";
                newEl->value=node->data;
            }
            else
                newEl->value=node->data;
            last->next=newEl;
            last=newEl;

        }

        getListFromTree(node->left);
        getListFromTree(node->right);
        return first;
    }
    else
        return;
}

void traverseList(NodeL *firstFromList)
{
    NodeL *currentEl=firstFromList;
    while(currentEl!=NULL)
    {
        if(currentEl->leaves=="*")
        {
            printf("%d ",currentEl->value);
            printf("* * ");
        }
        else
            printf("%d ",currentEl->value);
        currentEl=currentEl->next;
    }
    printf("\n");
}

NodeT *getTreeFromList(NodeL *firstFromList)
{
    NodeT *node;

    if(first==NULL)
        return;

    node=(NodeT *)malloc(sizeof(NodeT));
    node->data=first->value;
    first=first->next;
    node->left=NULL;
    node->right=NULL;

    if(firstFromList->leaves!="*")
    {
        node->left=getTreeFromList(firstFromList->next);
        node->right=getTreeFromList(firstFromList->next);
    }

    return node;
}
void prettyPrint(NodeT *node,int level)
{
    if (node!=NULL)
    {
        prettyPrint(node->left,level+1);
        for (int i=0; i<=level; i++)
        {
            printf("   ");
        }
        printf("%d\n",node->data);
        prettyPrint(node->right,level+1);
    }
}

