#include "treeAVL.h"

int height(NodeAVL *N) {
    if (N == NULL) return 0;
    return N->height;
}

int maxBetween(int a, int b) {
    return (a > b) ? a : b;
}

int heightDifference(NodeAVL *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

NodeAVL *rightRotation(NodeAVL *y) {
    NodeAVL *x = y->left;
    NodeAVL *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxBetween(height(y->left), height(y->right)) + 1;
    x->height = maxBetween(height(x->left), height(x->right)) + 1;

    return x;
}

NodeAVL *leftRotation(NodeAVL *x) {
    NodeAVL *y = x->right;
    NodeAVL *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxBetween(height(x->left), height(x->right)) + 1;
    y->height = maxBetween(height(y->left), height(y->right)) + 1;

    return y;
}

NodeAVL *getSuccessor(NodeAVL *node) {
    NodeAVL *current = node->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

NodeAVL *balaceTree(NodeAVL *node, int key) {
    int heightDiff = heightDifference(node);

    // Left Left Case
    if (heightDiff > 1 && key < node->left->key)
        return rightRotation(node);

    // Right Right Case
    if (heightDiff < -1 && key > node->right->key)
        return leftRotation(node);

    // Left Right Case
    if (heightDiff > 1 && key > node->left->key) {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    // Right Left Case
    if (heightDiff < -1 && key < node->right->key) {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

NodeAVL *insert(NodeAVL *node, int key) {
    if (node == NULL)
        return (createNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + maxBetween(height(node->left),
                                  height(node->right));

    node = balaceTree(node, key);

    return node;
}

NodeAVL *delete(NodeAVL *node, int key) {
    if (node == NULL) {
        return node;
    }
    if (key < node->key) {
        node->left = delete(node->left, key);
    } else if (key > node->key) {
        node->right = delete(node->right, key);
    } else {
        if (node->left == NULL) {
            NodeAVL *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            NodeAVL *temp = node->left;
            free(node);
            return temp;
        }

        NodeAVL *temp = getSuccessor(node);
        node->key = temp->key;
        node->right = delete(node->right, temp->key);
    }

    node->height = 1 + maxBetween(height(node->left),
                                  height(node->right));

    node = balaceTree(node, key);

    return node;
}


void prettyPrint(NodeAVL *root, int padding) {
    if (root != NULL) {
        padding += PADDING_STEP;
        prettyPrint(root->right, padding);
        for (int i = PADDING_STEP; i < padding; i++)
            printf(" ");
        printf("%d\n", root->key);
        prettyPrint(root->left, padding);
    }
}