#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    char id;
    struct node_Type *left, *right;
} NodeT;
void fatalError(const char * msg)
{
    printf(msg);
    printf("\n");
    exit(1);
}
void preorder( NodeT *p, int level )
{
    if ( p != NULL )
    {
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%2.2d\n",p->id);
        preorder(p->left, level +1);
        preorder (p->right, level + 1);
    }
}
void inorder(NodeT *p, int level)
{
    if(p!= NULL)
    {
        inorder(p->left,level +1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%2.2d\n",p->id);
        inorder(p->right,level +1);
    }
}
void postorder(NodeT *p, int level)
{
    if(p!=NULL)
    {
        postorder(p->left, level+1);
        postorder(p->right,level+1);
        for(int i=0; i<=level; i++)
            printf(" ");
        printf("%2.2d\n",p->id);
    }
}
NodeT *createBinTree (int branch, NodeT *parent)
{
    NodeT *p;
    int id;
    if(branch==0)
    {
        printf("Root identifier [0 to end]=");
    }
    else if(branch==1)
        printf("Left child of %d [0 to end]=",parent->id);
    else
        printf("Right child of %d [0 to end]=",parent->id);
    scanf("%d",&id);
    if(id==0)
        return NULL;
    else
    {
        p=(NodeT *)malloc(sizeof(NodeT));
        if(p==NULL)
            fatalError("Out of space in tree");
        p->id=id;
        p->left=createBinTree(1,p);
        p->right=createBinTree(2,p);
    }
    return p;
}
NodeT * createBalBinTree(int nbOfNodes)
{
    NodeT *p;
    if(nbOfNodes==0)
        return NULL;
    int nLeft=nbOfNodes/2;
    int nRight=nbOfNodes-nLeft-1;
    p=(NodeT *)malloc(sizeof(NodeT));
    if(p)
    {
        printf("Node identifier in preorder= ");
        scanf("%d",&p->id);
        p->left=createBalBinTree(nLeft);
        p->right=createBalBinTree(nRight);
    }
    else abort();
    return p;
}
NodeT * interchangeLeftRightSubtrees(NodeT * p)
{
    NodeT *x=(NodeT*)malloc(sizeof(NodeT));
    NodeT *y=(NodeT*)malloc(sizeof(NodeT));
    x->left=p->right;
    x->right=p->left;
    return x;
}
int HeightBinTree(NodeT *tree)
{

    if(tree!=NULL)
    {
        int left=HeightBinTree(tree->left);
        int right=HeightBinTree(tree->right);
        if(left>right)
            return (left+1);
        else
            return (right+1);
    }
    else
        return 0;
}
int nbLeaves(NodeT *tree)
{
    if(tree==NULL)
        return 0;
    if(tree->left==NULL && tree->right==NULL)
        return 1;
    return (nbLeaves(tree->left)+nbLeaves(tree->right));
}
/*int main() //main2
{
    int nbOfNodes = 0;
    printf("\n Number of nodes in the tree=");
    scanf("%d",&nbOfNodes);
    NodeT*root=createBalBinTree(nbOfNodes);

    printf("\n Preorder listing \n");
    preorder(root,0);
    printf("\n Inorder listing\n");
    inorder(root,0);
    printf("\n postorder listing\n");
    postorder(root,0);
     while('\n' != getc(stdin));
    return 0;
}*/
int main()// main 1
{

    NodeT *root=createBinTree(0,NULL);
    printf("\nPreorder listing\n");
    preorder(root,0);
   int height=HeightBinTree(root);
   int leafCt=nbLeaves(root);
   printf("height is %d and there are %d leaves",height,leafCt);
    return 0;

}
