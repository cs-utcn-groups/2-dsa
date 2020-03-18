//
// Created by q on 3/11/2020.
//

#ifndef CREATEBINARYTREE_TREE_H
#define CREATEBINARYTREE_TREE_H

#endif //CREATEBINARYTREE_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ERR_MEM_ALLOC "Error allocating memory"
#define MAX_SIZE 5
#define newLine printf("\n")

typedef struct node {
    char * id;
    struct node * left, * right;
}NodeT;
//create node
NodeT * createNode(char * id);
//display error message and exit program when memory could not be allocated
void errorMessage();
//create binary tree
NodeT * createBinTree(FILE * fp);
//print pretty
void printPretty(NodeT * root, int level);
// create list
NodeT *  createSentinel() ;
void createList(NodeT * sentinel, NodeT * root);
//tree->list
void addLast(NodeT * sentinel, char * id) ;
NodeT * getListFromTree(NodeT * root);
//traverse list
void traverseList(NodeT * head);
//list -> tree
NodeT * getTreeFromList(NodeT * sentinel);
//delete first node from the list
void deleteFirst(NodeT * sentinel) ;
