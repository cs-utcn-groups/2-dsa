#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void InitializeTree(TREE **Tree)
{
    TREE* tr = (TREE*)malloc(sizeof(TREE));

    tr->Key = NULL;
    tr->Left = NULL;
    tr->Right = NULL;

    *Tree = tr;
}

TREE* NewNode(char Key)
{
    TREE* node = (TREE*)malloc(sizeof(TREE));
    node->Key = Key;
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
        return Node;
    }
    else
    {
        if (Key < Node->Key)
        {
            Node->Left = Insert(Node->Left, Key);
        }
        else
        {
            Node->Right = Insert(Node->Right, Key);
        }

        return Node;
    }
}

void InsertTree(TREE *Tree, char Key)
{

    Tree = Insert(Tree, Key);
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
            TREE* t = Root->Right;
            free(Root);
            return t;
        }
        else if (NULL == Root->Right)
        {
            TREE* temp = Root->Left;
            free(Root);
            return temp;
        }
            TREE* temp = GetExtremum(Root->Right, 'm');
            Root->Key = temp->Key;
            Root->Right = Delete(Root->Right, temp->Key);

    }
    return Root;
}

void DeleteFromTree(TREE *Tree, char Key)
{

    if (Tree->Left == NULL && Tree->Right == NULL)
    {
        if (Tree->Key == Key)
        {
            Tree->Key = NULL;
        }
    }
    else
    {
       Tree = Delete(Tree, Key);
       if (Tree == NULL)
       {
           InitializeTree(&Tree);
       }
    }
}

void Find(TREE *Tree, char Key, FILE *g)
{

    TREE* node = Tree;

    while (NULL != node)
    {
        if (Key > node->Key)
        {
            node = node->Right;
        }
        else if (Key < node->Key)
        {
            node = node->Left;
        }
        else
        {
            fprintf(g, "Letter %c found!\n", Key);
            return;
        }
    }

    fprintf(g, "Letter %c not found!\n", Key);
}

void Preorder(TREE *Tree, FILE *g)
{
    if (Tree == NULL)
    {
        return;
    }
    fprintf(g, "%c ", Tree->Key);
    Preorder(Tree->Left, g);
    Preorder(Tree->Right, g);
}

void Postorder(TREE *Tree, FILE *g)
{
    if (Tree == NULL)
    {
        return;
    }
    Postorder(Tree->Left, g);
    Postorder(Tree->Right, g);
    fprintf(g, "%c ", Tree->Key);
}

void Inorder(TREE *Tree, FILE *g)
{
    if (Tree==NULL)
    {
        return;
    }
    Inorder(Tree->Left, g);
    fprintf(g, "%c ", Tree->Key);
    Inorder(Tree->Right, g);
}

void Transversal(TREE *Tree, char Mode, FILE *g)
{
    if (Mode == 'p')
    {
        Preorder(Tree, g);
    }
    else if (Mode == 'P')
    {
        Postorder(Tree, g);
    }
    else if (Mode == 'i')
    {
        Inorder(Tree, g);
    }
    else
    {
        fprintf(g, "Incorect code for transversal!");
    }
    fprintf(g, "\n");
}

char FindMin(TREE *Node)
{
    TREE *current = Node;
    while (current && current->Left)
    {
        current = current->Left;
    }
    return current->Key;
}

 char FindMax(TREE *Node)
{
    TREE *current = Node;
    while (current && current->Right)
    {
        current = current->Right;
    }
    return current->Key;
}


char GetExtremum(TREE *Tree, char Mode)
{
    if (Mode == 'm')
    {
        return FindMin(Tree);
    }
    else if (Mode == 'M')
    {
        return FindMax(Tree);
    }
    else return NULL;
}
