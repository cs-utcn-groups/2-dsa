#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    char id;
    struct node *left, *right;
} NodeT;

void fatalError(const char *msg)
{
    printf(msg);
    printf("\n");
    exit(1);
}

void preorder(NodeT *p, int level)
{
    if(p != NULL)
    {
        for(int i = 0; i <= level; i++)
            printf(" ");
        printf("%2.2d\n",p->id);
        preorder(p->left, level+1);
        preorder(p->right, level+1);
    }
}

void inorder(NodeT *p, int level)
{
    if(p != NULL)
    {
        inorder(p->left, level+1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%2.2d\n", p->id);
        inorder(p->right, level+1);
    }
}

void postorder(NodeT *p, int level)
{
    if(p != NULL)
    {
        postorder(p->left, level+1);
        postorder(p->right, level+1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%2.2d\n", p->id);
    }
}

NodeT *createBinTree(int branch, NodeT *parent)
{
    NodeT *p;
    int id;

    if(branch == 0)
        printf("Root identifier [0 to end] =");
    else if(branch == 1)
        printf("Left child of %d [0 to end] =", parent->id);
    else
        printf("Right child of %d [0 to end] =", parent->id);
    scanf("%d",&id);
    if(id == 0)
        return NULL;
    else
    {
        p = (NodeT*)malloc(sizeof(NodeT));
        if(p == NULL)
            fatalError("Out of space in createBinTree");
        p->id = id;
        p->left = createBinTree(1,p);
        p->right = createBinTree(2,p);
    }
    return p;
}

int determineHeight (NodeT *p)
{
    int totalHeight;

    if(p->right != NULL && p->left != NULL)
    {
        int rightHeight = 1 + determineHeight(p->right);
        int leftHeight = 1 + determineHeight(p->left);
        if(rightHeight>leftHeight)
        {
            totalHeight = rightHeight;
        }
        else
        {
            totalHeight = leftHeight;
        }
    }
    else if(p->right != NULL)
    {
        totalHeight = 1 + determineHeight(p->right);
    }
    else if(p->left != NULL)
    {
        totalHeight = 1 + determineHeight(p->left);
    }
    else
    {
        totalHeight = 1;
    }

    return totalHeight;
}

int countLeaves(NodeT *p)
{
    int numberOfLeaves;

    if(p->right != NULL && p->left != NULL)
    {
        int rightAmountOfLeaves = countLeaves(p->right);
        int leftAmountOfLeaves = countLeaves(p->left);
        numberOfLeaves = rightAmountOfLeaves + leftAmountOfLeaves;
    }
    else if(p->right != NULL)
    {
        numberOfLeaves = countLeaves(p->right);
    }
    else if(p->left != NULL)
    {
        numberOfLeaves = countLeaves(p->left);
    }
    else
    {
        numberOfLeaves = 1;
    }
    return numberOfLeaves;
}

void interchangeLeftAndRight(NodeT *p)
{
    if(p->right != NULL && p->left != NULL)
    {
        NodeT *q = p->right;
        p->right = p->left;
        p->left = q;
    }
    else if(p->right != NULL)
    {
        p->left = p->right;
        p->right = NULL;
    }
    else if(p->left != NULL)
    {
        p->right = p->left;
        p->left = NULL;
    }
}

int main()
{
    NodeT *root = createBinTree(0, NULL);
    printf("\nPreorder listing\n");
    preorder(root,0);
    printf("\nInorder listing\n");
    inorder(root,0);
    printf("\nPostorder listing\n");
    postorder(root,0);
}
