#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

typedef struct node_type
{
    int key, height;
    struct node_type * left, * right;
} nodeT;

nodeT * root;

nodeT * createNode (int key)
{
    nodeT * newNode = (nodeT*) malloc (sizeof (nodeT));
    newNode->key = key;
    newNode->right = newNode->left = NULL;
    newNode->height = 1;
    return newNode;
}

void print (nodeT * node, int space)
{
    if (root == NULL)
    {
        printf ("Tree is empty.\n");
    }
    if (node)
    {
        space += COUNT;
        print (node->right, space);
        for (int i = 0; i < space; i++)
        {
            printf (" ");
        }
        printf ("%d\n", node->key);
        print (node->left, space);
    }
}

int getMax (int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int getHeight (nodeT * node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getHeightDiff (nodeT * node)
{
    return getHeight (node->left) - getHeight (node->right);
}

nodeT * rotateRight (nodeT * x)
{
    nodeT * y = x->left;
    nodeT * z = y->right;
    y->right = x;
    x->left = z;
    x->height = 1 + getMax (getHeight (x->left), getHeight (x->right));
    y->height = 1 + getMax (getHeight (y->left), getHeight (y->right));
    return y;
}

nodeT * rotateLeft (nodeT * x)
{
    nodeT * y = x->right;
    nodeT * z = y->left;
    y->left = x;
    x->right = z;
    x->height = 1 + getMax (getHeight (x->left), getHeight (x->right));
    y->height = 1 + getMax (getHeight (y->left), getHeight (y->right));
    return y;
}

nodeT * insert (nodeT * node, int key)
{
    if (node == NULL)
    {
        return createNode (key);
    }
    if (key < node->key)
    {
        node->left = insert (node->left, key);
    }
    else
    {
        if (key > node->key)
        {
            node->right = insert (node->right, key);
        }
        else
        {
            printf ("This key already exists.\n");
        }
    }
    node->height = 1 + getMax (getHeight (node->left), getHeight (node->right));

    int heightDiff = getHeightDiff (node);

    if (heightDiff > 1 && key < node->left->key)
    {
        return rotateRight (node);
    }

    if (heightDiff < -1 && key > node->right->key)
    {
        return rotateLeft (node);
    }

    if (heightDiff > 1 && key > node->left->key)
    {
        node->left = rotateLeft (node->left);
        return rotateRight (node);
    }

    if (heightDiff < -1 && key < node->right->key)
    {
        node->right = rotateRight (node->right);
        return rotateLeft (node);
    }

    return node;

}

void printMessage ()
{
    printf ("What you want to do?\n1. Insert node\n2. Print AVL tree\n0. Exit\n");
}

char readChar ()
{
    char opt;
    scanf ("%c", &opt);
    getchar ();
    return opt;
}
int readInt ()
{
    int no;
    scanf ("%d", &no);
    getchar ();
    return no;
}

void execute ()
{
    char option;
    do
    {
        printMessage ();
        option = readChar ();
        switch (option)
        {
        case '1':
        {
            int key;
            printf ("Give a key to insert: ");
            key = readInt ();
            root = insert (root, key);
        }
        break;
        case '2':
        {
            print (root, 0);
        }
        break;
        case '0':
        {
            printf ("End of program.\n");
        }
        break;
        default:
        {
            printf ("Choose from {0, 1, 2}.\n");
        }
        break;
        }
    }
    while (option != '0');
}

int main()
{
    root = NULL;
    execute ();
    return 0;
}
