#include "avl.h"

void initializeTree(NodeT **root)
{
    NodeT *Tree=(NodeT*)malloc(sizeof(NodeT));
    Tree->Key ='\0';
    Tree->Height=0;
    Tree->Right=NULL;
    Tree->Left=NULL;
    *root=Tree;
}

NodeT *New(char Key)
{
    NodeT *t=(NodeT*)malloc(sizeof(NodeT));
    t->Key=Key;
    t->Height=1;
    t->Left=NULL;
    t->Right=NULL;
    return t;
}

int Height(NodeT *Tree)
{
    if (Tree == NULL)
    {
        return 0;
    }
    return Tree->Height;
}

int Maxim(int a, int b)
{
    if (a>b)
        return a;
    return b;
}

NodeT* RightRotate(NodeT *Y)
{
    NodeT *X = Y->Left;
    NodeT *T = X->Right;

    X->Right = Y;
    Y->Left = T;

    Y->Height = Maxim(Height(Y->Left), Height(Y->Right)) + 1;
    X->Height = Maxim(Height(X->Left), Height(X->Right)) + 1;

    return X;
}

NodeT* LeftRotate(NodeT *X)
{
    NodeT *Y = X->Right;
    NodeT *T = Y->Left;

    Y->Left = X;
    X->Right = T;

    X->Height = Maxim(Height(X->Left), Height(X->Right)) + 1;
    Y->Height = Maxim(Height(Y->Left), Height(Y->Right)) + 1;

    return Y;
}

NodeT *Insert(NodeT *Tree, char Key)
{
    if(Tree==NULL)
    {
        Tree=New(Key);
        return Tree;
    }
    else if(Tree->Key == NULL)
    {
        Tree->Key = Key;
        Tree->Height=1;
        return Tree;
    }
    else
    {
        if(Key < Tree->Key)
        {
            Tree->Key = Insert(Tree->Left,Key);
        }
        else if(Key > Tree->Key)
        {
            Tree->Right = Insert(Tree->Right,Key);
        }
        else
        {
            return Tree;
        }
    }


    if(Height(Tree->Left) > Height(Tree->Right))
    {
        Tree->Height = 1 + Height(Tree->Left);
    }
    else
    {
        Tree->Height = 1 + Height(Tree->Right);
    }


    int balance = Height(Tree->Left) - Height(Tree->Right);


    if (balance > 1)
    {
        if(Key > Tree->Left->Key)
            Tree->Left = LeftRotate(Tree->Left);
        return RightRotate(Tree);
    }
    if (balance < -1)
    {
        if(Key < Tree->Right->Key)
            Tree->Right = RightRotate(Tree->Right);
        return LeftRotate(Tree);
    }
    return Tree;
}

void prettyPrint( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        prettyPrint( p->Left, level + 1 ) ;
        for ( i = 0; i < level ; i++ )
            printf ( "     " ) ;
        printf ("%c %d\n", p->Key,p->Height ) ;
        prettyPrint( p->Right, level + 1 ) ;
    }
}
