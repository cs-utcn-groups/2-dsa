//
// Created by Bori on 3/19/2020.
//

#include "binTree.h"
#include <stdlib.h>
#include <string.h>

#define MEM_ERR_CODE 2
#define MEM_ERR_MESS "error allocating memory for node"

binTree *createBinTree(FILE *inFile) {
    binTree *newTree = (binTree *) malloc(sizeof(binTree));
    if (newTree == NULL) {
        perror(MEM_ERR_MESS);
        exit(MEM_ERR_CODE);
    }
    newTree->rootData = (char *) malloc(sizeof(char) * MAX_DATA_LENGTH);
    if (newTree->rootData == NULL) {
        perror(MEM_ERR_MESS);
        exit(MEM_ERR_CODE);
    }
    fscanf(inFile, "%s", newTree->rootData);
    if (strcmp(newTree->rootData, NULL_NODE) != 0) {
        newTree->left = createBinTree(inFile);
        newTree->right = createBinTree(inFile);
    } else {
        newTree->right = NULL;
        newTree->left = NULL;
    }
}

void inOrder(binTree *myTree, int level, FILE *outFile) {
    if (strcmp(myTree->rootData, NULL_NODE) != 0) //existing node
    {
        inOrder(myTree->left, level + 1, outFile);
        for (int i = 1; i <= level; i++) fprintf(outFile, "   ");
        fprintf(outFile, "%s\n", myTree->rootData);
        inOrder(myTree->right, level + 1, outFile);
    }
}

static void addTreeToList(binTree *myTree, dlList *myList) {
    addLast(myList, myTree->rootData);
    if (strcmp(myTree->rootData, NULL_NODE) != 0) //existing node
    {
        addTreeToList(myTree->left, myList);
        addTreeToList(myTree->right, myList);
    }
}

dlList getListFromTree(binTree *myTree) {
    dlList myList = createDLList();
    addTreeToList(myTree, &myList);
    return myList;
}

binTree *getBinTreeFromList(dlList *myList) {
    binTree *newTree = (binTree *) malloc(sizeof(binTree));
    if (newTree == NULL) {
        perror(MEM_ERR_MESS);
        exit(MEM_ERR_CODE);
    }
    newTree->rootData = (char *) malloc(sizeof(char) * MAX_DATA_LENGTH);
    strcpy(newTree->rootData, popFirst(myList));
    if (strcmp(newTree->rootData, NULL_NODE) != 0) {
        newTree->left = getBinTreeFromList(myList);
        newTree->right = getBinTreeFromList(myList);
    } else {
        newTree->right = NULL;
        newTree->left = NULL;
    }
    return newTree;
}
