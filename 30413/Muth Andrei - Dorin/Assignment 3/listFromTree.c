#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

typedef struct nodeTree
{
    char id;
    struct nodeTree * left, * right;
} nodeT;

typedef struct nodeList
{
    char id;
    struct nodeList * previous, * next;
} nodeL;

nodeL * lastFromList;
nodeL * currentFromList;

nodeT * createBinTree ()
{
    nodeT * p;
    char c;
    scanf ("%c", &c);
    if (c == '*')
    {
        return NULL;
    }
    p = (nodeT*) malloc (sizeof (nodeT));
    if (p == NULL)
    {
        printf ("Out of space in createBinTree.\n");
    }
    p->id = c;
    p->left = createBinTree ();
    p->right = createBinTree ();
    return p;
}

void preetyPrint (nodeT * p, int space)
{
    if (p != NULL)
    {
        space += COUNT;
        preetyPrint (p->right, space);
        for (int i = 0; i <= space; i++)
        {
            printf (" ");
        }
        printf ("%c\n", p->id);
        preetyPrint (p->left, space);
    }
}

nodeL * getListFromTree (nodeT * p)
{
    nodeL * newNode = (nodeL*) malloc (sizeof (nodeL));
    if (p != NULL)
    {
        newNode->id = p->id;
        if (lastFromList == NULL)
        {
            lastFromList = (nodeL*) malloc (sizeof (newNode));
            newNode->previous = NULL;
            lastFromList = newNode;
            lastFromList->next = getListFromTree (p->left);
            lastFromList->next = getListFromTree (p->right);
        }
        else
        {
            newNode->previous = lastFromList;
            lastFromList->next = newNode;
            lastFromList = newNode;
            lastFromList->next = getListFromTree (p->left);
            lastFromList->next = getListFromTree (p->right);
        }
        return newNode;
    }
    else
    {
        newNode->id = '*';
        newNode->previous = lastFromList;
        lastFromList = newNode;
        lastFromList->next = NULL;
        return newNode;
    }
}

void traverseList (nodeL * first)
{
     nodeL * q = first;
     while (q != NULL)
     {
         printf ("%c ", q->id);
         q = q->next;
     }
     printf ("\n");
}

nodeT * getTreeFromList (nodeL * first)
{
    nodeT * newNode = (nodeT*) malloc (sizeof (nodeT));
    if (currentFromList == NULL)
    {
        currentFromList = first;
    }
    else
    {
        currentFromList = currentFromList->next;
    }
    if (currentFromList->id == '*')
    {
        return NULL;
    }
    newNode->id = currentFromList->id;
    newNode->left = getTreeFromList (first);
    newNode->right = getTreeFromList (first);
    return newNode;
}

int main()
{
    nodeT * root = createBinTree ();
    nodeL * firstFromList = getListFromTree (root);
    traverseList (firstFromList);
    root = getTreeFromList (firstFromList);
    preetyPrint (root, 0);
    return 0;
}
