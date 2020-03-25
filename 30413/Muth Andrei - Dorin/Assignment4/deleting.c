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
    if (node == NULL) return 0;
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

nodeT * findMin (nodeT * node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->left)
    {
        return findMin (node->left);
    }
    return node;
}

nodeT * balanceTree (nodeT * node)
{
    if (node == NULL)
    {
        return NULL;
    }
    node->left = balanceTree (node->left);
    node->right = balanceTree (node->right);
    int heightDiff = getHeightDiff (node);
    if (heightDiff > 1 && node->left->left)
    {
        return rotateRight (node);
    }
    if (heightDiff < -1 && node->right->right)
    {
        return rotateLeft (node);
    }
    if (heightDiff > 1 && node->left->right)
    {
        node->left = rotateLeft (node->left);
        return rotateRight (node);
    }
    if (heightDiff < -1 && node->right->left)
    {
        node->right = rotateRight (node->right);
        return rotateLeft (node);
    }
    return node;
}

nodeT * deleteNode (nodeT * node, int key)
{
    if (root == NULL)
    {
        printf ("Tree is empty.\n");
    }
    if (node == NULL)
    {
        printf ("This node does not exist in tree.\n");
        return NULL;
    }
    if (key > node->key)
    {
        node->right = deleteNode (node->right, key);
    }
    else
    {
        if (key < node->key)
        {
            node->left = deleteNode (node->left, key);
        }
        else
        {
            if (node->left && node->right)
            {
                nodeT * temp = findMin (node->right);
                node->key = temp->key;
                node->right = deleteNode (node->right, temp->key);
            }
            else
            {
                nodeT * temp = node;
                if (node->left == NULL)
                {
                    node = node->right;
                }
                else
                {
                    node = node->left;
                }
                free (temp);
            }
        }
    }
    if (node == NULL)
    {
        return NULL;
    }
    node->height = 1 + getMax (getHeight (node->left), getHeight (node->right));

    node = balanceTree (node);

    return node;
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

    node = balanceTree (node);

    return node;

}

void printMessage ()
{
    printf ("What you want to do?\n1. Insert node\n2. Delete node\n3. Print AVL tree\n0. Exit\n");
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
            int key;
            printf ("Give a key to delete: ");
            key = readInt ();
            root = deleteNode (root, key);
        }
        break;
        case '3':
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
            printf ("Choose from {0, 1, 2, 3}.\n");
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
