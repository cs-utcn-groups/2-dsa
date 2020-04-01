//
// Created by Ivan on 3/23/2020.
//
#include "func.h"

int sizeOfDll(NodeT* root)
{
    int count = 0;
    while(root != NULL)
    {
        root = root->right;
        count++;
    }
    return count;
}

NodeT* createBinTree() {
    char *c = (char*)malloc(sizeof(char));
    fscanf(f, "%s", c);
    if(strcmp(c, "*") == 0)
    {
        return NULL;
    }
    NodeT *p = (NodeT*)malloc(sizeof(NodeT));
    p->id = c[0];
    p->left = createBinTree();
    p->right = createBinTree();
    return p;
}

void createListFromTree(NodeT *root, NodeT **head)
{
    if (root == NULL) return;
    static NodeT* prev = NULL;
    createListFromTree(root->left, head);

    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    createListFromTree(root->right, head);
}

NodeT* createTreeFromList(int size) {
    if (size <= 0) {
        return NULL;
    }
    NodeT* left = createTreeFromList(size / 2);
    NodeT* root = head;
    root->left = left;
    head = head->right;
    root->right = createTreeFromList(size-(size / 2)-1);
    return root;
}

void padd(char ch, int n){
    int i;
    for (i = 0; i < n; i++)
        putchar(ch);
}

void prettyPrint(NodeT *root, int floor){
    int i;
    if (root == NULL) {
        padd('\t', floor);
        puts("*");
    } else {
        prettyPrint ( root->right, floor + 1 );
        padd('\t', floor);
        printf("%c\n", root->id);
        prettyPrint(root->left, floor + 1);
    }
}

void traverse(NodeT* root)
{
    while(root != NULL)
    {
        printf("%c -> ", root->id);
        root = root->right;
    }
    printf("*\n");
}
