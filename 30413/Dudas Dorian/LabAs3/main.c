#include <stdio.h>
#include <stdlib.h>

typedef struct node_tree
{
    char id;
    struct node_tree *right, *left;
}NodeT;

typedef struct node_list
{
    char data;
    struct node_list *next, *prev;
}NodeL;

NodeL *first, *last;

NodeT *createBinTree()
{
    NodeT *p;
    char x;
    printf("\nGive value: ");
    scanf("%c",&x);
    if(x == '*')
    {
        return NULL;
    }
    else
    {
        p = (NodeT*)malloc(sizeof(NodeT));
        p->id = x;
        p->right = createBinTree();
        p->left = createBinTree();
        return p;
    }
}

void appendToList(char x)
{
    if(first == NULL)
    {
        first = (NodeL*)malloc(sizeof(NodeL));
        first->next = NULL;
        first->prev = NULL;
        first->data = x;
        last = first;
    }
    else
    {
        NodeL * newElement = (NodeL*)malloc(sizeof(NodeL));
        last->next = newElement;
        newElement->data = x;
        newElement->next = NULL;
        newElement->prev = last;
        last = newElement;
    }
}

NodeL *getListFromTree(NodeT *p)
{
    first = NULL;
    last = NULL;
    if(p == NULL)
    {
        appendToList('*');
    }
    else
    {
        appendToList(p->id);
        getListFromTree(p->right);
        getListFromTree(p->left);
    }
    return first;
}

void traverseList(NodeL *first)
{
    NodeL *p = first;
    printf("\n");
    while(p != NULL)
    {
        printf("%c", p->data);
        p->prev = p;
        p = p->next;
    }
}

NodeT *getTreeFromList(NodeL *first)
{
    NodeT *newTree = (NodeT*)malloc(sizeof(NodeT));
    NodeL *currentElement = first;
    if(currentElement == NULL || currentElement->data == '*')
    {
        return NULL;
    }
    else
    {
        if(currentElement != NULL)
        {
            currentElement->prev = currentElement;
            currentElement = currentElement->next;
        }
        newTree->id = currentElement->data;
        newTree->right = getTreeFromList(currentElement);
        newTree->left = getTreeFromList(currentElement);
        return newTree;
    }
}

void prettyPrint(NodeT *p, int level)
{
    if(p != NULL)
    {
        prettyPrint(p->right, level + 1);
        for(int i = 0; i < level; i++)
        {
            printf("    ");
        }
        printf("%c\n", p->id);
        prettyPrint(p->left, level + 1);
    }
}

int main()
{
    NodeT * root = createBinTree();
    NodeL * firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root = getTreeFromList(firstFromList);
    prettyPrint(root, 0);
    return 0;
}
