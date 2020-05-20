#include <stdio.h>
#include <stdlib.h>

typedef struct node_type {
    int key;
    struct node_type *left, *right;
    int height;
} BSTNodeT;


BSTNodeT *createNode(int givenKey) {
    BSTNodeT *p = (BSTNodeT *) malloc(sizeof(BSTNodeT));
    if (p) {
        p->key = givenKey;
        p->left = NULL;
        p->right = NULL;
        p->height = 1;
    }
    return p;
}

int maxi(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int height(BSTNodeT *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(BSTNodeT *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

BSTNodeT *rightRotate(BSTNodeT *root) {
    BSTNodeT *newRoot = root->left;
    BSTNodeT *t2 = newRoot->right;

    newRoot->right = root;
    root->left = t2;

    root->height = maxi(height(root->left), height(root->right)) + 1;
    newRoot->height = maxi(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

BSTNodeT *leftRotate(BSTNodeT *root) {
    BSTNodeT *newRoot = root->right;
    BSTNodeT *t2 = newRoot->left;

    newRoot->left = root;
    root->right = t2;

    root->height = maxi(height(root->left), height(root->right)) + 1;
    newRoot->height = maxi(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}


BSTNodeT *AVLinsert(BSTNodeT *root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else {
        if (key < root->key) {
            root->left = AVLinsert(root->left, key);
        } else if (key > root->key) {
            root->right = AVLinsert(root->right, key);
        } else {
            return root;
        }
    }

    root->height = 1 + maxi(height(root->left), height(root->right));

    int balance = getBalance(root);
    if (balance > 1) {
        if (key < root->left->key) {
            return rightRotate(root); // LL
        } else if (key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root); // LR
        }
    }
    if (balance < -1) {
        if (key > root->right->key) {
            return leftRotate(root); // RR
        } else if (key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root); // RL
        }
    }

    return root;
}

void deleteTree(BSTNodeT *root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

void prettyPrint(BSTNodeT *tree, int level) {
    if (tree == NULL) {
        return;
    }
    prettyPrint(tree->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("     ");
    }
    printf("%d\n", tree->key);
    prettyPrint(tree->left, level + 1);
}

int main() {
    int n, key;
    printf("Number of nodes to insert: ");
    scanf("%d", &n);
    BSTNodeT *root = NULL;
    printf("Please type the keys of the nodes you wish to insert: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = AVLinsert(root, key);
    }

    printf("\nListing: \n");
    prettyPrint(root, 0);


    return 0;
}