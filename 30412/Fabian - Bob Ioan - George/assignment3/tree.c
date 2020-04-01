//
// Created by Bobby on 3/19/2020.
//

#include "tree.h"


NodeT *createTree() {
    char carac;
    scanf("%c", &carac);
    if (carac == '*') {
        return NULL;
    } else {
        NodeT *node = (NodeT *) malloc(sizeof(NodeT));
        node->data = carac;
        node->left = createTree();
        node->right = createTree();
        return node;
    }
}

void intializeList() {
    first = NULL;
    last = NULL;
}

Node createList(NodeT *k) {
    if (first == NULL) {
        first = (Node *) malloc(sizeof(Node));
        first->data = k->data;
        first->prev = NULL;
        first->next = last;
        last = first;
        createList(k->left);
        createList(k->right);
    } else {
        Node *node = (Node *) malloc(sizeof(Node));
        node->prev = last;
        last->next = node;
        last=node;
        node->next = NULL;
        if (k != NULL) {
            node->data = k->data;
            createList(k->left);
            createList(k->right);
        } else
            node->data = '*';
    }

}

NodeT *back() {
    if(first!=NULL)
    {
        if(first->data=='*')
            return NULL;
        else{
            NodeT *node=(NodeT*)malloc(sizeof(NodeT));
            node->data=first->data;
            Node *ListNode=first;
            first=first->next;
            node->left= back();
            free(ListNode);
            ListNode=first;
            first=first->next;
            node->right= back();
            free(ListNode);
            return node;
        }
    }
}

void printT(NodeT *x, int layer) {
    if (x != NULL) {
        for (int i = 0; i < layer; i++)
            printf("%c", ' ');
        printf("%c", x->data);
        printT(x->left, layer + 1);
        printT(x->right, layer + 1);
    }
}

void printL() {
    Node *cNode = first;
    while (cNode != NULL) {
        printf("%c", cNode->data);
        cNode = cNode->next;
    }
    printf("\n");
}

void freeTree()
{
    if(root!=NULL) {
        NodeT *rNode = root;
        root = rNode->right;
        freeTree();
        root=rNode->left;
        freeTree();
        free(rNode);
    }
}
