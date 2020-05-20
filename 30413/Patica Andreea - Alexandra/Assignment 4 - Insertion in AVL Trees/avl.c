#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void InitializeTree(TREE **Tree)
{
    TREE* tr = (TREE*)malloc(sizeof(TREE));

    tr->Key = NULL;
    tr->Height = 0;
    tr->Left = NULL;
    tr->Right = NULL;

    *Tree = tr;
}

int Height(TREE *Node)
{
    if (Node == NULL)
    {
        return 0;
    }
    return Node->Height;
}

int Max(int a, int b)
{
    if (a>b) return a;
    return b;
}

TREE* RightRotate(TREE *Y)
{
    TREE *X = Y->Left;
    TREE *T = X->Right;

    X->Right = Y;
    Y->Left = T;

    Y->Height = Max(Height(Y->Left), Height(Y->Right)) + 1;
    X->Height = Max(Height(X->Left), Height(X->Right)) + 1;

    return X;
}

TREE* LeftRotate(TREE *X)
{
    TREE *Y = X->Right;
    TREE *T = Y->Left;

    Y->Left = X;
    X->Right = T;

    X->Height = Max(Height(X->Left), Height(X->Right)) + 1;
    Y->Height = Max(Height(Y->Left), Height(Y->Right)) + 1;

    return Y;
}

int GetBalance(TREE *Node)
{
    if (Node == NULL)
    {
        return 0;
    }
    return (Height(Node->Left) - Height(Node->Right));
}

TREE* NewNode(char Key)
{
    TREE* node = (TREE*)malloc(sizeof(TREE));
    node->Key = Key;
    node->Height = 1;
    node->Left = NULL;
    node->Right = NULL;

    return node;
}

TREE* Insert(TREE* Node, char Key)
{
    if (Node == NULL)
    {
        Node = NewNode(Key);
        return Node;
    }
    else if (Node->Key == NULL)
    {
        Node->Key = Key;
        Node->Height = 1;
        return Node;
    }
    else
    {
        if (Key < Node->Key)
        {
            Node->Left = Insert(Node->Left, Key);
        }
        else if (Key > Node->Key)
        {
            Node->Right = Insert(Node->Right, Key);
        }
        else
        {
            return Node;
        }
    }

    Node->Height = 1 + Max(Height(Node->Left), Height(Node->Right));

    int balance = GetBalance(Node);

    if (balance > 1 && Key < Node->Left->Key)
    {
        return RightRotate(Node);
    }
    if (balance < -1 && Key > Node->Right->Key)
    {
        return LeftRotate(Node);
    }
    if (balance > 1 && Key > Node->Left->Key)
    {
        Node->Left = LeftRotate(Node->Left);
        return RightRotate(Node);
    }
    if (balance < -1 && Key < Node->Right->Key)
    {
        Node->Right = RightRotate(Node->Right);
        return LeftRotate(Node);
    }

    return Node;
}

void InsertTree(TREE **Tree, char Key)
{

    *Tree = Insert(*Tree, Key);
}

void Preorder(TREE *Node, FILE *g)
{
    if (Node == NULL)
    {
        return;
    }
    fprintf(g, "%c ", Node->Key);
    Preorder(Node->Left, g);
    Preorder(Node->Right, g);
}

