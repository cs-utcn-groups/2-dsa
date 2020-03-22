#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char id;
    struct node *left, *right;
} NodeT;

NodeT *createBinaryTree();

void preorder(NodeT *currentRoot, int level);

void inorder(NodeT *currentRoot, int level);

void postorder(NodeT *currentRoot, int level);

int main() {
    NodeT *root = createBinaryTree();
    preorder(root, 0);
    printf("\n");
    inorder(root, 0);
    printf("\n");
    postorder(root, 0);
    return 0;
}

void postorder(NodeT *currentRoot, int level) {
    if (currentRoot != NULL) {
        postorder(currentRoot->left, level + 1);
        postorder(currentRoot->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        printf("%c", currentRoot->id);
    }
}


void inorder(NodeT *currentRoot, int level) {
    if (currentRoot != NULL) {
        inorder(currentRoot->left, level + 1);
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        printf("%c", currentRoot->id);
        inorder(currentRoot->right, level + 1);
    }
}

void preorder(NodeT *currentRoot, int level) {
    if (currentRoot != NULL) {
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        printf("%c", currentRoot->id);
        preorder(currentRoot->left, level + 1);
        preorder(currentRoot->right, level + 1);
    }
}

NodeT *createBinaryTree() {
    char *c = malloc(sizeof(char));
    scanf("%s", c);
    if (strcmp(c, "*") == 0) {
        return NULL;
    }

    NodeT *p = (NodeT *) malloc(sizeof(NodeT));
    p->id = c[0];
    p->left = createBinaryTree();
    p->right = createBinaryTree();
    return p;
}
