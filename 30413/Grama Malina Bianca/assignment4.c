#include <stdio.h>
#include <stdlib.h>

typedef struct node_type {
    char id;
    struct node_type *left, *right;
} NodeT;

typedef struct node {
    struct node *next;
    struct node *prev;
    char val;
} NodeL;

NodeL *first, *last;

void fatalError(const char *msg) {
    printf("%s", msg);
    printf("\n");
    exit(1);
}

void addLast(char data) {
    if (first == NULL) {
        first = (NodeL *) malloc(sizeof(NodeL));
        first->next = last;
        first->prev = NULL;
        first->val = data;
        last = first;
    } else {
        NodeL *newElement = (NodeL *) malloc(sizeof(NodeL));
        last->next = newElement;
        newElement->prev = last;
        newElement->next = NULL;
        newElement->val = data;
        last = newElement;
    }
}

NodeT *createBinTree() {
    NodeT *p;
    char c;
    scanf("%c", &c);
    if (c == '*') {
        return NULL;
    } else {
        p = (NodeT *) malloc(sizeof(NodeT));
        if (p == NULL) {
            fatalError("Out of space in createBinTree");
        }
        p->id = c;
        p->left = createBinTree(f);
        p->right = createBinTree(f);
    }
    return p;
}

void getListFromTree(NodeT *p) {
    if (p != NULL) {
        addLast(p->id);
        getListFromTree(p->left);
        getListFromTree(p->right);
    } else {
        addLast('*');
    }
}

void traverseList() {
    if (first == NULL) {
        printf("List is empty!\n");
    } else {
        NodeL *currentElement = first;
        while (currentElement != NULL) {
            printf("%c ", currentElement->val);
            currentElement = currentElement->next;
        }
        printf("\n");
    }
}

NodeT *createTree(NodeL **Dllist) {
    NodeT *p;
    *Dllist = (*Dllist)->next;
    if ((*Dllist)->val == '*') {
        return NULL;
    } else {
        p = (NodeT *) malloc(sizeof(NodeT));
        if (p == NULL)
            fatalError("Out of space in createTree");

        p->id = (*Dllist)->val;
        p->left = createTree(Dllist);
        p->right = createTree(Dllist);
    }
    return p;
}

NodeT *getTreeFromList(NodeL *first) {
    NodeL *current = (NodeL *) malloc(sizeof(NodeL));
    current->val = first->val;
    current->prev = NULL;
    current->next = first;

    NodeL *aux = current;
    NodeT *tree = createTree(&current);
    free(aux);

    return tree;
}

void prettyPrint(NodeT *tree, int level) {
    if (tree == NULL) {
        return;
    }
    prettyPrint(tree->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("     ");
    }
    printf("%c\n", tree->id);
    prettyPrint(tree->left, level + 1);
}

int main() {
    NodeT *root = createBinTree();
    getListFromTree(root);
    traverseList();
    root = getTreeFromList(first);
    prettyPrint(root, 0);

    return 0;
}