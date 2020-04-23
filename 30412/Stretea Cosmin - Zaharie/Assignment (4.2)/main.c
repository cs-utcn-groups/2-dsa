#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
}NodeT;

int max(int a, int b);
void prettyPrint(NodeT *root, int space);
NodeT* insert(NodeT* node, int key);
NodeT* delete(NodeT* node, int key);
NodeT *getSuccessor(NodeT *node);
NodeT *getPredecessor(NodeT *node);

int main()
{
    NodeT *root = NULL;

    /* Constructing tree */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    printf("Initial AVL tree is \n");
    prettyPrint(root, 0);

    root = delete(root, 10);

    printf("\nThe AVL tree after deletion of 10 \n");
    prettyPrint(root, 0);
    return 0;
}
void prettyPrint(NodeT *root, int space) {
    if (root == NULL)
        return;
    space += 7;

    // Process right child first
    prettyPrint(root->right, space);

    // Print current node after space
    // count
    for (int i = 7; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    prettyPrint(root->left, space);
}

int height(NodeT *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

NodeT* newNode(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}


NodeT *rightRotate(NodeT *y)
{
    NodeT *x = y->left;
    NodeT *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

NodeT *leftRotate(NodeT *x)
{
    NodeT *y = x->right;
    NodeT *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

int getBalance(NodeT *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

NodeT* insert(NodeT* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}
NodeT* delete(NodeT* node, int key)
{
    /* 1.  Perform the normal BST deletion */
    if (node == NULL) {
        return node;
    }
    if (key < node->key) {
        node->left = delete(node->left, key);
    } else if (key > node->key) {
        node->right = delete(node->right, key);
    } else {
        if (node->left == NULL) {
            NodeT *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            NodeT *temp = node->left;
            free(node);
            return temp;
        }

        NodeT *temp = getPredecessor(node);
        node->key = temp->key;
        node->left = delete(node->left, temp->key);
    }

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}
NodeT *getSuccessor(NodeT *node) {
    NodeT *current = node->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}
NodeT *getPredecessor(NodeT *node) {
    NodeT *current = node->left;
    while (current != NULL && current->right != NULL) {
        current = current->right;
    }
    return current;
}