//
// Created by Alex on 19.03.2020.
//

#include "nodes.h"


NodeT *createTree() {
    char c;
    scanf("%c", &c);
    if (c == '*') {
        return NULL;
    } else {
        NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
        newNode->data = c;
        newNode->left = createTree();
        newNode->right = createTree();
        return newNode;
    }
}

void intializeList() {
    first = NULL;
    last = NULL;
}

NodeL createList(NodeT *x) {
    if (first == NULL) {
        first = (NodeL *) malloc(sizeof(NodeL));
        first->data = x->data;
        first->prev = NULL;
        first->next = last;
        last = first;
        createList(x->left);
        createList(x->right);
    } else {
        NodeL *newNode = (NodeL *) malloc(sizeof(NodeL));
        newNode->prev = last;
        last->next = newNode;
        last=newNode;
        newNode->next = NULL;
        if (x != NULL) {
            newNode->data = x->data;
            createList(x->left);
            createList(x->right);
        } else
            newNode->data = '*';
    }

}

NodeT *goBack() {
    if(first!=NULL)
    {
        if(first->data=='*')
            return NULL;
        else{
            NodeT *newNode=(NodeT*)malloc(sizeof(NodeT));
            newNode->data=first->data;
            NodeL *ListNode=first;
            first=first->next;
            newNode->left=goBack();
            free(ListNode);
            ListNode=first;
            first=first->next;
            newNode->right=goBack();
            free(ListNode);
            return newNode;
        }
    }
}

void printTree(NodeT *x, int level) {
    if (x != NULL) {
        for (int i = 0; i < level; i++)
            printf("%c", ' ');
        printf("%c", x->data);
        printTree(x->left, level + 1);
        printTree(x->right, level + 1);
    }
}

void printList() {
    NodeL *curNode = first;
    while (curNode != NULL) {
        printf("%c", curNode->data);
        curNode = curNode->next;
    }
    printf("\n");
}

void freeTree()
{
    if(root!=NULL) {
        NodeT *curNode = root;
        root = curNode->right;
        freeTree();
        root=curNode->left;
        freeTree();
        free(curNode);
    }
}