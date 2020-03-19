//
// Created by Bori on 3/19/2020.
//

#include "binTree.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MEM_ERR_CODE 2
#define MEM_ERR_MESS "error allocating memory for node"

void checkMemoryAllocation(void* ptr)
{
    if (ptr == NULL) {
        perror(MEM_ERR_MESS);
        exit(MEM_ERR_CODE);
    }
}

bool isOperator(char* s)
{
    char operators[] = "+-*/";
    return strlen(s)==1 && strchr(operators, s[0])!=NULL;
}

binTree* createBinTree(Queue* expQueue) {
    binTree *newTree = (binTree *) malloc(sizeof(binTree));
    checkMemoryAllocation(newTree);
    newTree->rootData = (char *) malloc(sizeof(char) * MAX_DATA_LENGTH);
    checkMemoryAllocation(newTree->rootData);
    strcpy(newTree->rootData, pop(expQueue));

    if(isOperator(newTree->rootData))
    {
        newTree->left = createBinTree(expQueue);
        newTree->right = createBinTree(expQueue);
    }
    else
    {
        newTree->left=NULL;
        newTree->right=NULL;
    }
    return newTree;
}

void inOrder(binTree *myTree, int level, FILE *outFile) {
    if (myTree!=NULL) //existing node
    {
        inOrder(myTree->left, level + 1, outFile);
        for (int i = 1; i <= level; i++) fprintf(outFile, "   ");
        fprintf(outFile, "%s\n", myTree->rootData);
        inOrder(myTree->right, level + 1, outFile);
    }
}

