#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    struct node *left, *right;
} nodeT;

int findNrLeaves(nodeT *currentNode)
{
    int nrLeaves;
    if(currentNode->right != NULL && currentNode->left != NULL)
    {
        int nrLeavesRight,nrLeavesLeft;
        nrLeavesRight = findNrLeaves(currentNode->right);
        nrLeavesLeft = findNrLeaves(currentNode->left);
        nrLeaves = nrLeavesRight + nrLeavesLeft;
    }
    else if(currentNode->right != NULL && currentNode ->left == NULL)
    {
        nrLeaves = findNrLeaves(currentNode->right);
    }
    else if(currentNode->right == NULL && currentNode ->left != NULL)
    {
        nrLeaves = findNrLeaves(currentNode->left);
    }
    else
    {
        nrLeaves = 1;
    }
    return nrLeaves;
}
