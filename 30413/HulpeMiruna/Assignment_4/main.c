#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int label;
    struct node *left,*right;
    int height;
} NodeT;

typedef struct nodel
{
    int val;
    struct nodet *next, *previous;
} NodeL;
NodeT *rightRotate(NodeT *tree)
{
    NodeT *Left = tree->left;
    NodeT *subTree = Left->right;
    Left->right = tree;
    tree->left = subTree;
    tree->height = maxi(height(tree->left), height(tree->right))+1;
    Left->height = maxi(height(Left->left), height(Left->right))+1;
    return Left;
}
NodeT *leftRotate( NodeT *tree)
{
    NodeT *Right = tree->right;
    NodeT *subTree = Right->left;
    Right->left = tree;
    tree->right = subTree;
    tree->height = maxi(height(tree->left), height(tree->right))+1;
    Right->height = maxi(height(Right->left), height(Right->right))+1;
    return Right;
}

int Verify(NodeT *T)
{
    if (T == NULL)
        return 0;
    return Verify(T->left) - Verify(T->right);
}
int height(NodeT *T)
{
    if (T == NULL)
        return 0;
    return T->height;
}
int maxi(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}
NodeT * insertAVL(NodeT *tree,int nr)
{

    if (tree == NULL)
    {
        NodeT* p = (NodeT* ) malloc(sizeof(NodeT));
        p->label   = nr;
        p->left   = NULL;
        p->right  = NULL;
        p->height = 1;
        return(p);
    }

    if (nr < tree->label)
        tree->left  = insertAVL(tree->left, nr);
    else if (nr > tree->label)
        tree->right = insertAVL(tree->right, nr);
    else
        return tree;
    tree->height = 1 + maxi(height(tree->left),
                            height(tree->right));

    int Value = Verify(tree);

    if (Value > 1 && nr < tree->left->label)
        return rightRotate(tree);

    if (Value < -1 && nr > tree->right->label)
        return leftRotate(tree);

    if (Value > 1 && nr > tree->left->label)
    {
        tree->left =  leftRotate(tree->left);
        return rightRotate(tree);
    }


    if (Value < -1 && nr < tree->right->label)
    {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }


    return tree;
}


void inorder(NodeT *T,int level)
{
    if(T!=NULL)
    {
        inorder( T->left, level + 1);
        int i;
        for ( i = 0; i <= level; i++ )
            printf( " " );
        printf("%d\n",T->label);
        inorder( T->right, level + 1 );
    }
}


int main()
{
    NodeT *tree = NULL;
    int n,nr;
    scanf("%d ",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&nr);
        tree=insertAVL(tree,nr);
    }
    inorder(tree,0);
    return 0;
}
