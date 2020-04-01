//
// Created by Andreea on 23-Mar-20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define MAX_SIZE 5

nodeT *createBinaryTree(FILE *inputFile) {
    if (!feof(inputFile)) {
        char *c = (char *) malloc(MAX_SIZE * sizeof(char));
        fscanf(inputFile, "%s", c);
        if (strcmp(c, "*") == 0) {
            free(c);
            return NULL;
        }
        nodeT *p = (nodeT *) malloc(sizeof(nodeT));
        p->id = (char *) malloc(MAX_SIZE * sizeof(char));
        strcpy(p->id, c);
        free(c);
        p->left = createBinaryTree(inputFile);
        p->right = createBinaryTree(inputFile);
        return p;

    }
}

void prettyPrint(nodeT *currentRoot, int level, FILE *outputFile) {
    if (currentRoot != NULL) {
        prettyPrint(currentRoot->right, level + 1, outputFile);
        for (int i = 0; i < 6 * level; i++) {
            fprintf(outputFile, " ");
        }
        fprintf(outputFile, "%s\n", currentRoot->id);
        prettyPrint(currentRoot->left, level + 1, outputFile);
    }
}

void preOrder(nodeT *currentRoot) {
    if (currentRoot != NULL) {
        addLast(currentRoot->id);
        preOrder(currentRoot->left);
        preOrder(currentRoot->right);
    } else {
        addLast("*");
    }
}

nodeL *getListFromTree(nodeT *currentRoot) {
    initializeDLL();
    preOrder(currentRoot);

}

nodeT *getTreeFromList() {
    currentElement = sentinel->next;
    if (currentElement != sentinel) {
        if (strcmp(currentElement->data, "*") == 0) {
            return NULL;
        }
        nodeT *p = (nodeT *) malloc(sizeof(nodeT));
        p->id = (char *) malloc(MAX_SIZE * sizeof(char));
        strcpy(p->id, currentElement->data);
        deleteFirst();
        p->left = getTreeFromList();
        deleteFirst();
        p->right = getTreeFromList();
        return p;
    }

}