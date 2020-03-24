//
// Created by Anca on 3/22/2020.
//

#ifndef ASSIGNMENT3_HEAD_H
#define ASSIGNMENT3_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_tree{
    char id;
    struct node_tree *left;
    struct node_tree *right;
}NodeT;

typedef struct node_list{
    char data;
    struct node_list *prev;
    struct node_list *next;
}NodeL;

FILE *fin;

NodeT *createBinaryTree();
void prettyPrint(NodeT *root, int level);
void addElementToTheList(NodeL **head, NodeL **last, char newData);
void initializeDLL(NodeL**head, NodeL **last);
void preorder(NodeL **head, NodeL **last, NodeT *currentRoot);
NodeL *getListFromTree(NodeT *root);
NodeT *getTreeFromList(NodeL **currentNode);

#endif //ASSIGNMENT3_HEAD_H
