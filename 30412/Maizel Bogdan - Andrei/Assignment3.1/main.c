#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_tree {
    char id;
    struct node_tree *left, *right;
} nodeT;

typedef struct node_list {
    char id;
    struct node_list *prev, *next;
} nodeL;

nodeT *createBinaryTree();

nodeL *newNodeL();

nodeL *getListFromTree(nodeT *root);

void addLast(nodeL **first, nodeL **last, char c);

void addListElements(nodeT *p, nodeL **first, nodeL **last);

void goTroughList(nodeL *first);

nodeT *getTreeFromList(nodeL **pList);

void printTree(nodeT *root, int space);

int main() {
    nodeT *root = createBinaryTree();
    nodeL *firstFromList = getListFromTree(root);
    goTroughList(firstFromList);
    printf("\n");
    root = getTreeFromList(&firstFromList);
    printTree(root, 0);
    return 0;
}

void printTree(nodeT *root, int space) {
    if (root == NULL)
        return;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%c\n", root->id);
    printTree(root->left, space);
}

nodeT *getTreeFromList(nodeL **pList) {
    char c;
    if (pList) {
        c = (*pList)->id;
        (*pList) = (*pList)->next;
        if (c == '*')
            return NULL;

        nodeT *p = (nodeT *) malloc(sizeof(nodeT));
        if (p == NULL) {
            perror("O crapat!");
        }
        p->id = c;
        p->left = getTreeFromList(pList);
        p->right = getTreeFromList(pList);
        return p;
    } else
        return NULL;
}

nodeT *createBinaryTree() {
    char c;
    scanf("%c", &c);
    getc(stdin);
    if (c == '*')
        return NULL;

    nodeT *p = (nodeT *) malloc(sizeof(nodeT));
    if (p == NULL) {
        perror("Failed to create list.");
    }
    p->id = c;
    p->left = createBinaryTree();
    p->right = createBinaryTree();
    return p;
}

nodeL *getListFromTree(nodeT *root) {
    nodeL *first = NULL, *last = NULL;
    addListElements(root, &first, &last);
    return first;
}

void addListElements(nodeT *p, nodeL **first, nodeL **last) {
    if (p) {
        addLast(first, last, p->id);
        if (p->left == NULL)
            addLast(first, last, '*');
        else
            addListElements(p->left, first, last);

        if (p->right == NULL)
            addLast(first, last, '*');
        else
            addListElements(p->right, first, last);
    }
}

void addLast(nodeL **first, nodeL **last, char c) {
    if ((*last) == NULL) {
        (*last) = newNodeL();
        (*last)->id = c;
        (*first) = (*last);
    } else {
        nodeL *newNode = newNodeL();
        newNode->id = c;
        newNode->next = NULL;
        newNode->prev = (*last);
        (*last)->next = newNode;
        (*last) = newNode;
    }
}

nodeL *newNodeL() {
    nodeL *new = (nodeL *) malloc(sizeof(nodeL));
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void goTroughList(nodeL *first) {
    while (first) {
        printf("%c ", first->id);
        first = first->next;
    }
}