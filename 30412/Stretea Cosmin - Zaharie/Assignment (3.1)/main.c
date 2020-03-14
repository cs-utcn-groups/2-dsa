#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_tree {
    char id;
    struct node_tree *left, *right;
} NodeT;

typedef struct node_list {
    char id;
    struct node_list *prev, *next;
} NodeL;

NodeT *createBinTree();

NodeL *newNodeL();

NodeL *getListFromTree(NodeT *root);

void addLast(NodeL **first, NodeL **last, char c);
void preorderAddList(NodeT *p, NodeL **first, NodeL **last);
void traverseList( NodeL * first);

NodeT *getTreeFromList(NodeL **pList);

void prettyPrint(NodeT *root, int space);

int main() {

    NodeT *root = createBinTree();
    NodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    printf("\n");
    root = getTreeFromList(&firstFromList);
    prettyPrint(root, 0);

    return 0;
}

void prettyPrint(NodeT *root, int space) {
    if (root == NULL)
        return;
    space += 5;

    // Process right child first
    prettyPrint(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%c\n", root->id);

    // Process left child
    prettyPrint(root->left, space);
}

NodeT *getTreeFromList(NodeL **pList) {
    char c ;
    if(pList) {
        c = (*pList)->id;
        (*pList) = (*pList)->next;
        if (c == '*')
            return NULL;

        NodeT *p = (NodeT *) malloc(sizeof(NodeT));
        if (p == NULL) {
            perror("O crapat!");
        }
        p->id = c;
        p->left = getTreeFromList(&(*pList));
        p->right = getTreeFromList(&(*pList));
        return p;
    }
    else
        return NULL;
}

NodeT *createBinTree() {
    char c ;
    scanf("%c", &c); // input line with spaces ex: 1 2 3 * * 4 * * 5 6 * * 7 * *
    getc(stdin);

    if (c == '*')
        return NULL;

    NodeT *p = (NodeT *) malloc(sizeof(NodeT));
    if (p == NULL) {
        perror("O crapat!");
    }
    p->id = c;
    p->left = createBinTree();
    p->right = createBinTree();
    return p;
}

NodeL *getListFromTree(NodeT *root) {
    NodeL *first = NULL, *last = NULL;
    preorderAddList(root, &first, &last);
    return first;
}

void preorderAddList(NodeT *p, NodeL **first, NodeL **last) {
    if (p) {
        addLast(&(*first), &(*last), p->id);
        if (p->left == NULL)
            addLast(&(*first), &(*last), '*');
        else
            preorderAddList(p->left, &(*first), &(*last));

        if(p->right == NULL)
            addLast(&(*first), &(*last), '*');
        else
            preorderAddList(p->right, &(*first), &(*last));
    }
}

void addLast(NodeL **first, NodeL **last, char c) {
    if ((*last) == NULL) {
        (*last) = newNodeL();
        (*last)->id = c;
        (*first) = (*last);
    } else {
        NodeL *newNode = newNodeL();
        newNode->id = c;
        newNode->next = NULL;
        newNode->prev = (*last);
        (*last)->next = newNode;
        (*last) = newNode;
    }
}

NodeL *newNodeL() {
    NodeL *new = (NodeL *) malloc(sizeof(NodeL));
    new->next = NULL;
    new->prev = NULL;
    return new;
}
void traverseList( NodeL * first){
    while(first){
        printf("%c ", first->id);
        first = first->next;
    }
}