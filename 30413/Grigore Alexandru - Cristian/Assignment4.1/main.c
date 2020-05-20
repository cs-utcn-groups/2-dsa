#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *left, *right;
    int height;
}NodeT;

NodeT *createNode(int key)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    if(p)
    {
        p->key=key;
        p->left=NULL;
        p->right=NULL;
        p->height=1;
    }
    return p;
}

int height(NodeT *p)
{
    if(p==NULL)
    {
        return 0;
    }
    return p->height;
}

int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int makeJustice(NodeT *p)
{
    if(p==NULL)
    {
        return 0;
    }
    return height(p->left)-height(p->right);
}

NodeT *rotateRight(NodeT *p)
{
    NodeT *aux=p->left;
    NodeT *temp=aux->right;

    aux->right=p;
    p->left=temp;

    p->height=max(height(p->left),height(p->right)+1);
    aux->height=max(height(aux->left),height(aux->right+1));

    return aux;
}

NodeT *rotateLeft(NodeT *p)
{
    NodeT *aux=p->right;
    NodeT *temp=aux->left;

    aux->left=p;
    p->right=temp;

    p->height=max(height(p->left),height(p->right)+1);
    aux->height=max(height(aux->left),height(aux->right)+1);

    return aux;
}

NodeT *insert(NodeT *p,int key)
{
    if(p==NULL)
    {
        return createNode(key);
    }
    if(key<p->key)
    {
        p->left=insert(p->left,key);
    }
    else if(key>p->key)
    {
        p->right=insert(p->right,key);
    }
    else
        return p;

    p->height=1+max(height(p->left),height(p->right));

    int justice=makeJustice(p);

    //left left case
    if(justice>1 && key<p->left->key)
    {
        return rotateRight(p);
    }
    //right right case
    if(justice<-1 && key>p->right->key)
    {
        return rotateLeft(p);
    }
    //left right
    if(justice>1 && key>p->left->key)
    {
        p->left=rotateLeft(p->left);
        return rotateRight(p);
    }
    //right left
    if(justice<-1 && key<p->right->key)
    {
        p->right=rotateRight(p->right);
        return rotateLeft(p);
    }

    return p;
}

void preorder(NodeT *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->key);
        preorder(p->left);
        preorder(p->right);
    }
}

void prettyPrint(NodeT *p,int level)
{
    if(p==NULL)
    {
        return;
    }
    prettyPrint(p->right,level+1);
    for(int i=0;i<=level;i++)
    {
        printf("  ");
    }
    printf("%d\n",p->key);
    prettyPrint(p->left,level+1);
}

int main()
{
   NodeT *root=NULL;
   int n;
   printf("enter nr of nodes: ");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
     int key;
     scanf("%d",&key);
     root=insert(root,key);
   }
   preorder(root);
   printf("\n");
   prettyPrint(root,0);
    return 0;
}
