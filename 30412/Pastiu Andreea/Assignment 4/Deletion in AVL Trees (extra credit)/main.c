#include <stdio.h>
#include <stdlib.h>
#define SPACES_NO 2

typedef struct node {
    struct node *left, *right;
    int key, height;
} nodeT;
nodeT *root = NULL;
nodeT* createNode(int key);
void prettyPrint(nodeT *root, int space);
nodeT* insertNodeBST(nodeT* node, int key);
int max(int a, int b);
int height(nodeT *node);
nodeT* leftRotate(nodeT *node1);
nodeT* rightRotate(nodeT *node1);
int getBalance(nodeT *node);
nodeT* insertAVL(nodeT *node, int key);
void readTree(FILE *ifptr);
nodeT* deleteAVL(nodeT *node, int key);
nodeT* deleteNodeBST(nodeT *node, int key);

int main()
{
    FILE *ifptr = fopen("input.dat", "r");
    if (ifptr == NULL)
    {
        perror("ifptr");
    }
    else
    {
        readTree(ifptr);
        printf("AVL Tree:\n");
        prettyPrint(root, 0);
        root = deleteAVL(root, 5);
        root = deleteAVL(root, 6);
        printf("\nAVL Tree after deletion:");
        prettyPrint(root, 0);
    }

    return 0;
}

void readTree(FILE *ifptr)
{
    int key;
    while (fscanf(ifptr, "%d", &key) != EOF)
    {
        root = insertAVL(root, key);
    }
}

nodeT* insertAVL(nodeT *node, int key)
{
    node = insertNodeBST(node, key);
    int balance = getBalance(node);
    // left left case
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // right right case
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // left right case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    // right left case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

nodeT* deleteAVL(nodeT* node, int key)
{
    node = deleteNodeBST(node, key);
    if (node == NULL)
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // left left case
    if (balance > 1 && getBalance(node->left) >= 0)
    {
        return rightRotate(node);
    }
    // left right case
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right right case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    // right keft case
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int getBalance(nodeT *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

nodeT *rightRotate(nodeT *node1)
{
    nodeT *node2 = node1->left;
    nodeT *temp = node2->right;
    node2->right = node1;
    node1->left = temp;
    node1->height = max(height(node1->left), height(node1->right)) + 1;
    node2->height = max(height(node2->left), height(node2->right)) + 1;

    return node2;
}

nodeT *leftRotate(nodeT *node1)
{
    nodeT *node2 = node1->right;
    nodeT *temp = node2->left;
    node2->left = node1;
    node1->right = temp;
    node1->height = max(height(node1->left), height(node1->right)) + 1;
    node2->height = max(height(node2->left), height(node2->right)) + 1;

    return node2;
}

int height(nodeT *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

nodeT* insertNodeBST(nodeT* node, int key)
{
    if (node == NULL)
        return (createNode(key));

    if (key < node->key)
    {
        node->left = insertNodeBST(node->left, key);
    }
    else
    {
        if (key > node->key)
        {
            node->right = insertNodeBST(node->right, key);
        }
        else
        {
            return node;
        }
    }
    node->height = 1 + max(height(node->left), height(node->right));
    return node;
}

nodeT* deleteNodeBST(nodeT *node, int key)
{
    if (node == NULL)
        return node;
    if (key < node->key)
        node->left = deleteNodeBST(node->left, key);
    else if( key > node->key )
        node->right = deleteNodeBST(node->right, key);
    else
    {
        if( (node->left == NULL) || (node->right == NULL) )
        {
            nodeT *temp = node->left ? node->left : node->right;
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
            {
                *node = *temp;
            }
            free(temp);
        }
        else
        {
            nodeT * temp = node;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            node->key = temp->key;
            node->right = deleteNodeBST(node->right, temp->key);
        }
    }
    return node;
}

void prettyPrint(nodeT *root, int space)
{
    {
        if (root != NULL)
        {
            space += SPACES_NO;
            prettyPrint(root->right, space);
            printf("\n");
            for (int i = SPACES_NO; i < space; i++)
                printf(" ");
            printf("%d", root->key);
            prettyPrint(root->left, space);
        }
    }
}

nodeT *createNode(int key)
{
    nodeT *node = (nodeT *) malloc(sizeof(nodeT));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}