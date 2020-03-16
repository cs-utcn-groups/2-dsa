#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

///please let's assume there are no two nodes with the same id

nodeT *createBinaryTree(int branch, nodeT *parent)
{
    nodeT *p = (nodeT*)malloc(sizeof(nodeT));
    if(branch == 0)
    {
        printf("Root identifier is: ");
    }
    else if(branch == 1)
    {
        printf("Left child of %d is: ",parent->id);
    }
    else
    {
        printf("Right child of %d is: ",parent->id);
    }

    int nodeId = 0;
    scanf("%d",&nodeId);

    if(nodeId == 0)
    {
        return NULL;
    }
    else
    {
        if(p==NULL)printf("\neruare");
        p->id = nodeId;
        p->left = createBinaryTree(1,p);
        p->right = createBinaryTree(2,p);
    }
    return p;
}

int main()
{
    nodeT *root = createBinaryTree(0,NULL);

    printf("\nInitial tree in inorder is:\n");
    inorder(root,0);

    int height;
    height = findHeightTree(root);
    printf("\nThe height of the tree is: %d\n",height);

    int nrLeaves;
    nrLeaves = findNrLeaves(root);
    printf("\nThe number of leaves of the tree is: %d\n",nrLeaves);

    int nodeNumber;
    printf("\nThe node whose subtrees you want to interchange is labeled with number: ");
    scanf("%d",&nodeNumber);
    nodeT *ourNode = findNodeInTree(root,nodeNumber);
    if(ourNode != NULL)
    {
        interchangeSubtrees(ourNode);

        printf("\nThe interchanged subtree printed in preorder is:\n");
        preorder(root,0);
        printf("\nThe interchanged subtree printed in inorder is:\n");
        inorder(root,0);
        printf("\nThe interchanged subtree printed in postorder is:\n");
        postorder(root,0);
    }
    else
    {
        printf("\nThere is no node labeled %d.",nodeNumber);
    }
    return 0;
}
