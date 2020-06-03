#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node_type {
    char id;
    struct node_type *left, *right; //left may also be previous and right may be next in a Double Linked List
} NodeT;

typedef struct node {
    char id;
    struct node *next, *prev;
} NodeL;

NodeT *createBinaryTree();

void showList(NodeT *first);

NodeL *makeListFromTree(NodeT *root);

NodeT *makeTreeFromList(NodeL *first);

int main() {
    NodeT *root = createBinaryTree();
    NodeL *first = makeListFromTree(root);
    root = makeTreeFromList(first);
    showList(root);
    return 0;
}

NodeT *makeTreeFromList(NodeL *first) {
    NodeL *root = (NodeL*)malloc(sizeof(NodeL));
    if (first!=NULL) {
        if (first->id!='*') {
            
        }
    }
}

void showList(NodeT *first) {
    if (first != NULL) {
        printf("%c ", first->id);
        if (first->right != NULL)
            showList(first->right);
    }
}

NodeT *createBinaryTree() {
    char *id = malloc(sizeof(char));
    scanf("%s", id);
    if (strcmp(id, "*") == 0) return NULL;

    NodeT *p = (NodeT *) malloc(sizeof(NodeT));
    p->id = *id;
    p->left = createBinaryTree();
    p->right = createBinaryTree();
    return p;
}

NodeL *makeListFromTree(NodeT *root) {
    NodeL *currentNode = (NodeL *) malloc(sizeof(NodeL));
    if (root->left != NULL) {
        currentNode->id = root->id;
        printf("%c ", root->id);
        currentNode->next = makeListFromTree(root->left);
    } else {
        currentNode->id = '*';
        printf("%c ", root->id);
    }
    if (root->right != NULL) {
        currentNode->id = root->id;
        printf("%c ", root->id);
        currentNode->next = makeListFromTree(root->right);
    }
    else {
        currentNode->id = '*';
        printf("%c ", root->id);
    }
    return currentNode;
}
