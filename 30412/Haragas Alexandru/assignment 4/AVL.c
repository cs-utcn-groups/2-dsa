//
// Created by Alex on 28.03.2020.
//

#include "AVL.h"

void afisTree(NodeT *node, int depth) {
    if (node != NULL) {
        afisTree(node->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf(" ");
        }
        printf("%d\n", node->val);
        afisTree(node->left, depth + 1);
    }
}

NodeT *addNode(NodeT *node, int x) {
    if (node == NULL) {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->val = x;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }
    if (x < node->val) {
        node->left = addNode(node->left, x);
    }
    if (x > node->val) {
        node->right = addNode(node->right, x);
    }
    return node;
}

NodeT *leftMost(NodeT *node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

NodeT *rightMost(NodeT *node) {
    while (node != NULL && node->right != NULL) {
        node = node->right;
    }
    return node;
}

NodeT *delNode(NodeT *node, int x) {
    if (node == NULL)
        return NULL;
    if (x > node->val) {
        node->right = delNode(node->right, x);
    }
    if (x < node->val) {
        node->left = delNode(node->left, x);
    }
    if (x == node->val) {
        NodeT *currentNode = node;
        if (node->right == NULL) {
            node = node->left;
            free(currentNode);
        } else if (node->left == NULL) {
            node = node->right;
            free(currentNode);
        } else {
            NodeT *s = leftMost(node->right);
            node->val = s->val;
            node = delNode(node->right, s->val);
        }
    }
    return node;
}

NodeT *balanceTree(NodeT *node, int rd, int ld) {
    NodeT *newRoot;
    if (rd > ld) {
        newRoot = node->right;
        if (newRoot->right != NULL) {
            node->right = newRoot->left;
            newRoot->left = node;
        } else {
            node->right = NULL;
            NodeT *s = leftMost(newRoot);
            int x = s->val;
            newRoot = delNode(newRoot, x);
            NodeT *copy = NULL;
            copy = addNode(copy, x);
            copy->left = node;
            copy->right = newRoot;
            newRoot = copy;
        }
    } else {
        newRoot = node->left;
        if (newRoot->left != NULL) {
            node->left = newRoot->right;
            newRoot->right = node;
        } else {
            node->left = NULL;
            NodeT *s = rightMost(newRoot);
            int x = s->val;
            newRoot = delNode(newRoot, x);
            NodeT *copy = NULL;
            copy = addNode(copy, x);
            copy->right = node;
            copy->left = newRoot;
            newRoot = copy;
        }
    }
    return newRoot;
}


int depth(NodeT *node) {
    if (node == NULL) {
        return 0;
    }
    return max(depth(node->left), depth(node->right)) + 1;
}