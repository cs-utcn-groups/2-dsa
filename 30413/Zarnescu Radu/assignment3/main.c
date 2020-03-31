#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    char data;
    struct node * next, * previous;

}NodeL;

NodeL * first, * last;

typedef struct node_type
{

    char id;
    struct node_type * left, * right;

}NodeT;

void initializeDLL()
{

    first = NULL;
    last = NULL;

}

void addLast(char c)
{

    if(first == NULL)
    {
        first = (NodeL*)malloc(sizeof(NodeL));
        first->data = c;
        first->next = NULL;
        first->previous = NULL;
        last = first;
    }
    else
    {
        NodeL * newElement = (NodeL*)malloc(sizeof(NodeL));
        newElement->data = c;
        newElement->previous = last;
        last->next = newElement;
        newElement->next = NULL;
        last = newElement;
    }

}

NodeT * createBinTree()
{
    NodeT * p = (NodeT*)malloc(sizeof(NodeT));
    char c;

    scanf("%c", &c);
    if(c == '*')
    {
        return NULL;
    }
    else
    {
        if(p == NULL)
        {
            printf("out of space in binary tree\n");
        }
        p->id = c;
        p->left = createBinTree();
        p->right = createBinTree();
    }
    return p;
}

void getListFromTree(NodeT * root)
{

    if(root == NULL)
    {
        addLast('*');
    }
    else
    {
        addLast(root->id);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }

}

NodeL * current;

NodeT * getTreeFromList()
{
    NodeT * p;
    if(current->data == '*')
    {
        current = current->next;
        return NULL;
    }
    else
    {
        p = (NodeT*)malloc(sizeof(NodeT));
        p->id = current->data;
        current = current->next;;
        p->left = getTreeFromList();
        p->right = getTreeFromList();
    }
    return p;
}

void preorder(NodeT *p, int level)
{
    int i;
    if(p != NULL)
    {
        for(i=0; i<=level; i++)
        {
            printf(" ");
        }
        printf( "%c\n", p->id );
        preorder(p->left, level+1);
        preorder(p->right, level+1);


    }
}

void traverseList()
{

    NodeL * currElement = first;
    while(currElement != NULL)
    {
        printf("%c", currElement->data);
        currElement = currElement->next;
    }
    printf("\n");

}

int main()
{
    initializeDLL();
    NodeT * root = createBinTree();
    preorder(root, 0);
    getListFromTree(root);
    traverseList();
    current = first;
    root = getTreeFromList();
    preorder(root, 0);
    return 0;
}
