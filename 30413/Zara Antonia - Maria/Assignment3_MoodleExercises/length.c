#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    struct node *left, *right;
} nodeT;

int findHeightTree(nodeT *currentNode)
{
    int rightHeight,leftHeight,height;

    if(currentNode->left != NULL && currentNode->right != NULL)
    {
        rightHeight = 1 + findHeightTree(currentNode->right);
        leftHeight = 1 + findHeightTree(currentNode->left);
        if(rightHeight > leftHeight)
        {
            height = rightHeight;
        }
        else
        {
            height = leftHeight;
        }
    }
    else if(currentNode->right == NULL && currentNode->left != NULL)
    {
        height = 1 + findHeightTree(currentNode->left);
    }
    else if(currentNode->right != NULL && currentNode->left == NULL)
    {
        height = 1 + findHeightTree(currentNode->right);
    }
    else
    {
        height = 1;
    }
    return height;
}
