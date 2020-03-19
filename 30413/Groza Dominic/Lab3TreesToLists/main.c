#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    char id;//node name
    struct node *left, *right;
} NodeT;

typedef struct _node {
    char id;
    struct _node *prev, *next;
} NodeL;

NodeL *first, *last;

NodeT *createBinTree() {
    NodeT *p;
    char c;
    scanf("%c", &c);
    if (c == '*')
        return NULL;
    else {
        p = (NodeT *) malloc(sizeof(NodeT));
        p->id = c;
        p->left = createBinTree();
        p->right = createBinTree();
    }
    return p;
}

void addAtEnd(char x) {
    NodeL *newNode = (NodeL *) malloc(sizeof(NodeL));
    newNode->id = x;
    if (first == NULL) {//empty list
        last = newNode;
        first = last;
        newNode->next = NULL;
        newNode->prev = NULL;
    } else {//non-empty
        last->next = newNode;
        newNode->prev = last;
        newNode->next = NULL;
        last = newNode;
    }
}

void treeToList(NodeT *p) {
    NodeL *newNode = (NodeL *) malloc(sizeof(NodeL));
    if (p == NULL) {
        addAtEnd('*');
    }
    if (p != NULL) {
        addAtEnd(p->id);
        treeToList(p->left);
        treeToList(p->right);
    }
}

NodeT *listToTree() {
    NodeT *newTree= (NodeT *) malloc(sizeof(NodeT));
    NodeL *currNode;
    currNode = first;
    if (currNode->next != NULL) {
        if (currNode->id != '*') {
            newTree->id=currNode->id;
            first = first->next;
            newTree->left = listToTree();
            newTree->right = listToTree();
        } else {
            first=first->next;
            return NULL;
        }
    }
    return newTree;
}

void printAll() {
    NodeL *temp = first;
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%c", temp->id);
        temp = temp->next;
    }
    printf("\n");
}

void prettyPrint(NodeT *p, int level) {
    if (p != NULL) {
        prettyPrint(p->left, level + 1);
        prettyPrint(p->right, level + 1);
        for (int i = 0; i <= level; i++)
            printf(" ");
        printf("%c\n", p->id);
    }
}

int main() {
    NodeT *root = createBinTree();
    treeToList(root);
    printAll();
    root = listToTree();
    prettyPrint(root, 0);
    return 0;
}
