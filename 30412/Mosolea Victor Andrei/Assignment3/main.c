#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char id;
    struct node *left, *right;
} NodeT;

typedef struct nodeL {
    char id;
    struct nodeL *previous, *next;
} NodeL;

typedef struct list {
    NodeL *first, *last;
} List;

NodeT *createBinTree() {
    char c[1];
    scanf("%s", c);
    if (strcmp(c, "*") != 0) {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        strcpy(&newNode->id, c);
        newNode->left = createBinTree();
        newNode->right = createBinTree();
        return newNode;
    } else
        return NULL;
}

void addLast(List *list, char id) {
    NodeL *newNode = (NodeL *) malloc(sizeof(NodeL));
    newNode->id = id;
    newNode->next = NULL;
    if (list->first != NULL) {
        newNode->previous = list->last;
        list->last->next = newNode;
        list->last = newNode;
    } else {
        list->first = newNode;
        list->last = newNode;
        newNode->previous = NULL;
    }
}

void getListFromTree(NodeT *root, List *list) {
    if (root == NULL) {
        addLast(list, '*');
    } else {
        addLast(list, root->id);
        getListFromTree(root->left, list);
        getListFromTree(root->right, list);
    }
}

void initList(List *list) {
    list->first = list->last = NULL;
}

void traverseList(List list) {
    NodeL *currentNode = list.first;
    while (currentNode != NULL) {
        printf("%c", currentNode->id);
        currentNode = currentNode->next;
    }
}

NodeT *getTreeFromList(NodeL **currentNode) {
    char c = (*currentNode)->id;
    (*currentNode) = (*currentNode)->next;
    if (c != '*') {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->id = c;
        newNode->left = getTreeFromList(currentNode);
        newNode->right = getTreeFromList(currentNode);
        return newNode;
    } else {
        return NULL;
    }
}

void prettyPrint(NodeT *root, int level) {
    if (root->right != NULL)
        prettyPrint(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%c\n", root->id);
    if (root->left != NULL)
        prettyPrint(root->left, level + 1);
}

int main() {
    NodeT *root = createBinTree();
    List list;
    initList(&list);
    getListFromTree(root, &list);
    traverseList(list);
    NodeL *aux = list.first;
    root = getTreeFromList(&aux);
    printf("\n");
    prettyPrint(root, 0);
    return 0;
}
