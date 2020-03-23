
#include <stdbool.h>
#include "head.h"


NodeT *createNode(int key);

NodeT *insert(NodeT *root, int key);

bool find(NodeT *root, int key);

void findWithPrint(NodeT *root, int key);

NodeT *delete(NodeT *root, int key);

NodeT *getParent(NodeT *root, int key);

bool hasChildKey(const NodeT *root, int key);

NodeT *getSuccessor(NodeT *node);

int main() {
    NodeT *root = createNode(10);
    insert(root, 1);
    insert(root, 19);
    insert(root, 5);
    insert(root, 8);
    insert(root, 99);
    insert(root, 4);
    insert(root, 3);
    insert(root, 3);
    insert(root, 2);
    insert(root, 1);
    insert(root, 0);
    prettyPrint(root, 0);
    printf("\n");

    findWithPrint(root, 0);
    findWithPrint(root, -4);
    findWithPrint(root, 4);
    printf("\n");
    printf("\n");

    delete(root, 0);
    prettyPrint(root, 0);

    root = delete(root, 10);
    prettyPrint(root, 0);

    return 0;
}

NodeT *delete(NodeT *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = delete(root->left, key);
    } else if (key > root->key) {
        root->right = delete(root->right, key);
    } else {
        if (root->left == NULL) {
            NodeT *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NodeT *temp = root->left;
            free(root);
            return temp;
        }

        NodeT *temp = getSuccessor(root);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}

NodeT *getSuccessor(NodeT *node) {
    NodeT *current = node->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

NodeT *getParent(NodeT *root, int key) {
    if (root == NULL) {
        return NULL;
    } else {
        if (hasChildKey(root, key)) {
            return root;
        } else {
            if (key < root->key) {
                return getParent(root->left, key);
            } else {
                return getParent(root->right, key);
            }
        }
    }
}

bool hasChildKey(const NodeT *root, int key) {
    return (root->left != NULL && root->left->key == key) || (root->right != NULL && root->right->key == key);
}

void findWithPrint(NodeT *root, int key) {
    printf(find(root, key) ? "Element %d found!\n" : "Element %d not found!\n", key);
}

bool find(NodeT *root, int key) {
    if (root == NULL) {
        return false;
    } else {
        if (root->key == key) {
            return true;
        } else {
            if (key < root->key) {
                return find(root->left, key);
            } else {
                return find(root->right, key);
            }
        }
    }
}


NodeT *insert(NodeT *root, int key) {
    NodeT *node = createNode(key);
    if (root == NULL) {
        return node;
    }
    NodeT *aux = root;

    for (;;) {
        if (key < aux->key) {
            if (aux->left == NULL) {
                aux->left = node;
                return node;
            } else {
                aux = aux->left;
            }
        } else if (key > aux->key) {
            if (aux->right == NULL) {
                aux->right = node;
                return node;
            } else {
                aux = aux->right;
            }
        } else {
            printf("Key %d already in tree!", key);
            free(node);
            return NULL;
        }
    }
}

NodeT *createNode(int key) {
    NodeT *node = (NodeT *) malloc(sizeof(NodeT));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    return node;
}
