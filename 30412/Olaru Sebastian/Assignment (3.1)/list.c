#include "list.h"

void traverseList(NodeL *first) {
    printf("\n");
    NodeL *currentNode = first;
    while (currentNode != NULL) {
        printf("%c", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void addNodeInList(NodeL **first, char data) {
    NodeL *newNode = createNewListNode(data);
    NodeL *currentNode = *first;
    if (*first == NULL) {
        *first = newNode;
    } else {
        while (currentNode->next != NULL)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }
}

void makePreorderList(NodeL **list, NodeT *currentRoot) {
    if (currentRoot == NULL) {
        addNodeInList(list, '*');
    } else {
        addNodeInList(list, currentRoot->data);
        makePreorderList(list, currentRoot->left);
        makePreorderList(list, currentRoot->right);
    }
}

NodeL *getListFromTree(NodeT *currentRoot) {
    NodeL *newList = NULL;
    makePreorderList(&newList, currentRoot);

    return newList;
}

