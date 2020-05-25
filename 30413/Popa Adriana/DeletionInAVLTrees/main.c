#include <stdio.h>
#include <stdlib.h>

typedef struct _TREE {
    char Key;
    int Height;
    struct _TREE* Left;
    struct _TREE* Right;
}TREE;

void InitializeTree(TREE **Tree)
{
    TREE* tr = (TREE*)malloc(sizeof(TREE));

    tr->Key = 0;
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
    else if (Node->Key == 0)
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

TREE* FindMin(TREE *Node)
{
    TREE *current = Node;
    while (current && current->Left)
    {
        current = current->Left;
    }
    return current;
}

TREE* Delete(TREE* Root, char Key)
{
    if (NULL == Root)
    {
        return NULL;
    }

    if (Key < Root->Key)
    {
        Root->Left = Delete(Root->Left, Key);
    }
    else if (Key > Root->Key)
    {
        Root->Right = Delete(Root->Right, Key);
    }
    else
    {
        if (NULL == Root->Left)
        {
            TREE* temp = Root->Right;
            free(Root);
            return temp;
        }
        else if (NULL == Root->Right)
        {
            TREE* temp = Root->Left;
            free(Root);
            return temp;
        }
            TREE* temp = FindMin(Root->Right);
            Root->Key = temp->Key;
            Root->Right = Delete(Root->Right, temp->Key);

    }

    if (Root == NULL)
    {
        return Root;
    }

    Root->Height = 1 + Max(Height(Root->Left), Height(Root->Right));
    int balance = GetBalance(Root);

    if (balance > 1 && GetBalance(Root->Left) >= 0)
    {
        return RightRotate(Root);
    }
    if (balance > 1 && GetBalance(Root->Left) <0)
    {
        Root->Left = LeftRotate(Root->Left);
        return RightRotate(Root);
    }
    if (balance < -1 && GetBalance(Root->Right) <= 0)
    {
        return LeftRotate(Root);
    }
    if (balance < -1 && GetBalance(Root->Right) > 0)
    {
        Root->Right = RightRotate(Root->Right);
        return LeftRotate(Root);
    }
    return Root;
}

void DeleteFromTree(TREE **Tree, char Key)
{

    if ((*Tree)->Left == NULL && (*Tree)->Right == NULL)
    {
        if ((*Tree)->Key == Key)
        {
            (*Tree)->Key = 0;
            (*Tree)->Height = 0;
        }
    }
    else
    {
       *Tree = Delete(*Tree, Key);
       if (*Tree == NULL)
       {
           InitializeTree(&(*Tree));
       }
    }
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

int main()
{
    FILE *f = fopen("input.in", "r");
    FILE *g = fopen("output.out", "w");
    TREE *Tree;

    InitializeTree(&Tree);

    char function;
    while (fscanf(f, "%c", &function)>0)
    {
        char letter;
        fscanf(f, "%c", &letter);

        switch(function)
        {
            case 'i': InsertTree(&Tree, letter);
                break;
            case 'p' : Preorder(Tree, g);
                fprintf(g, "\n");
                break;
            case 'd': DeleteFromTree(&Tree, letter);
                break;
            default: printf("Invalid call for function!\n");
                break;
        }

        char aux;
        fscanf(f, "%c", &aux);
    }

    fclose(f);
    fclose(g);

    return 0;
}
