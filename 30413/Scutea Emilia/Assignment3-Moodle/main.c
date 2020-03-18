#include <stdio.h>
#include <stdlib.h>
typedef struct node_type
{
    int id;
    struct node_type * left, * right;
} NodeT;

NodeT * createBinaryTree(int branch,NodeT * parent)
{
    NodeT * p;
    int id;
    if(branch==0)
        printf("Root identifier [0 to end]=");
    else if(branch==1)
        printf("Left child of %d [0 to end]=",parent->id);
    else
        printf("Right child of %d [0 to end]=",parent->id);
    scanf("%d",&id);
    if(id==0)
        return NULL;
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        p->id=id;
        p->left=createBinaryTree(1,p);
        p->right=createBinaryTree(2,p);
    }
    return p;
}
void preorder(NodeT * p,int level)
{
    if(p!=NULL)
    {
        printf("%d ",p->id);
        preorder(p->left,level+1);
        preorder(p->right,level+1);
    }
}
void inorder(NodeT * p,int level)
{
    if(p!=NULL)
    {
        inorder(p->left,level+1);
        printf("%d ",p->id);
        inorder(p->right,level+1);
    }
}
void postorder(NodeT * p,int level)
{
    if(p!=NULL)
    {
        postorder(p->left,level+1);
        postorder(p->right,level+1);
        printf("%d ",p->id);
    }
}

int heightOfTree(NodeT * p)
{
    if(p==NULL)
        return 0;
    else
    {
        int rightDepth=heightOfTree(p->right);
        int leftDepth=heightOfTree(p->left);
        if(rightDepth>leftDepth)
            return rightDepth+1;
        else
            return leftDepth+1;
    }

}

int countNumberOfLeaves(NodeT * p)
{
    if(p==NULL)
        return 0;
    else if(p->left==NULL && p->right==NULL)
        return 1;
    else
        return countNumberOfLeaves(p->left)+countNumberOfLeaves(p->right);
}
void interchangeSubtree(NodeT * p)
{
    if(p!=NULL)
    {
        NodeT * aux;
        aux=p->left;
        p->left=p->right;
        p->right=aux;
        interchangeSubtree(p->left);
        interchangeSubtree(p->right);
    }
}
void searchNode(NodeT * p, int data)
{
    if(p!=NULL)
    {
        if(p->id==data)
        {
            interchangeSubtree(p);
        }
        searchNode(p->left,data);
        searchNode(p->right,data);
    }
}

int main()
{
    NodeT * root=createBinaryTree(0,NULL);
    printf("Preorder listing:\n");
    preorder(root,0);
    printf("\n");
    printf("Postorder listing:\n");
    postorder(root,0);
    printf("\n");
    printf("Inorder listing:\n");
    inorder(root,0);
    printf("\n");
    printf("The height of the tree is %d.\n",heightOfTree(root));
    printf("The number of leaves of the tree is %d.\n",countNumberOfLeaves(root));
    searchNode(root,4);
    printf("Inorder listing of the interchanged subtree:\n");
    inorder(root,0);
    printf("\n");
    return 0;
}
