#include "head.h"
const int count=10;

void preorder(NodeT *p, int level)
{
    if(p!=NULL)
    {
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%2.2d\n",p->id);
        preorder(p->left,level+1);
        preorder(p->right,level+1);
    }
}

void inorder (NodeT *p, int level)
{
    if(p!=NULL)
    {
        inorder(p->left,level+1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%2.2d\n",p->id);
        inorder(p->right,level+1);
    }
}

void postorder(NodeT *p, int level)
{

    if(p!=NULL)
    {
        postorder(p->left,level+1);
        postorder(p->right,level+1);
        for(int i=0; i<level; i++)
            printf(" ");
        printf("%2.2d\n",p->id);
    }
}

void fatalError(const char *msg)
{
    printf(msg);
    printf("\n");
    exit(1);
}

NodeT *createBinTree(int branch, NodeT *parent,FILE *f)
{
    NodeT *p;
    int id;

    /* if(branch==0)
         printf("Root identifier [0 to end]=");
     else if(branch==1)
         printf("Left child of %d [0 to end]=",parent->id);
     else
         printf("Right child of %d [0 to end]=",parent->id);*/

    fscanf(f,"%d",&id);

    if(id==0)
        return NULL;
    else
    {
        p=(NodeT *)malloc(sizeof(NodeT));
        if(p==NULL)
            fatalError("Out of space in createBinTree");
        p->id=id;
        p->left=createBinTree(1,p,f);
        p->right=createBinTree(2,p,f);
    }
    return p;
}

bool ifNodeExists(NodeT *node, int data)
{
    if(node==NULL)
        return false;
    if(node->id==data)
        return true;
    bool search_left=ifNodeExists(node->left,data);
    if(search_left==true)
        return true;
    bool search_right=ifNodeExists(node->right,data);
    if(search_right==true)
        return true;
}

void swapTree(NodeT *node)
{
    if(node!=NULL)
    {
        NodeT *temp;
        temp=node->left;
        node->left=node->right;
        node->right=temp;
        swapTree(node->left);
        swapTree(node->right);
    }
}


int searchNodeForAddress(NodeT *node, int data)
{
    if(node!=NULL)
    {
        if(node->id==data)
        {
            swapTree(node);
        }
        searchNodeForAddress(node->left,data);
        searchNodeForAddress(node->right,data);
    }


}

int findHeight(NodeT *node)
{
    int leftTree=0, rightTree=0;
    if(node!=NULL)
    {
        leftTree=findHeight(node->left);
        rightTree=findHeight(node->right);
        if(leftTree>=rightTree)
            return leftTree+1;
        else
            return rightTree+1;
    }
    else
        return -1;
}

int nrOfLeaves(NodeT *node)
{
    if(node!=NULL)
    {
        if(node->left==NULL && node->right==NULL) return 1;
        else return nrOfLeaves(node->left)+nrOfLeaves(node->right);
    }
    else return 0;

}
