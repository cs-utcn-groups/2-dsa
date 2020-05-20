#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    struct node *left, *right;
} nodeT;

nodeT *findNodeInTree(nodeT *currentNode, int number)
{
    ///credit to GeeksForGeeks i'm not gonna lie
   nodeT *newNode = NULL;
   if(currentNode == NULL) return NULL;
   if(currentNode->id == number) return currentNode;

   newNode = findNodeInTree(currentNode->left,number);
   if(newNode == NULL) newNode = findNodeInTree(currentNode->right,number);

   return newNode;
}

void interchangeSubtrees(nodeT *ourNode)
{
    if(ourNode->left != NULL && ourNode->right != NULL)
    {
        nodeT *aux;
        aux = ourNode->right;
        ourNode->right = ourNode->left;
        ourNode->left = aux;
    }
    else if(ourNode->left == NULL)
    {
        ourNode->left = ourNode->right;
        ourNode->right = NULL;
    }
    else if(ourNode->right == NULL)
    {
        ourNode->right = ourNode->left;
        ourNode->left = NULL;
    }
}
