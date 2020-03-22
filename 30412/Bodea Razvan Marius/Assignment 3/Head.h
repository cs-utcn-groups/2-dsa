//
// Created by razvi on 3/22/2020.
//

#ifndef CODE_HERE_HEAD_H
#define CODE_HERE_HEAD_H


typedef struct list {
    char data;
    struct list *next, *prev;
} NodeL;

NodeL *first, *last;

typedef struct node {
    char id;
    struct node *left, *right;
} NodeT;

void initializeList();

NodeT *createBinaryTree();

void addNode(char data);

NodeL *getListFromTree(NodeT *root);

void traverseList(NodeL *node);

NodeT *getTreeFromList();

void prettyPrint(NodeT *root, int level);


#endif //CODE_HERE_HEAD_H
