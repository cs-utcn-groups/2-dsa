#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left,*right;
} nodeT;

nodeT *root = NULL;

void inorder(nodeT *currentNode, int level)
{
    if(currentNode)
    {
        inorder(currentNode->left,level+1);
        int i;
        for(i=0; i<=level; i++)
        {
            printf("   ");
        }
        printf("%d\n",currentNode->data);
        inorder(currentNode->right,level+1);
    }
}

int findHeight(nodeT *currentNode)
{
    int rightHeight,leftHeight,height;

    if(currentNode->left != NULL && currentNode->right != NULL)
    {
        rightHeight = 1 + findHeight(currentNode->right);
        leftHeight = 1 + findHeight(currentNode->left);
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
        height = 1 + findHeight(currentNode->left);
    }
    else if(currentNode->right != NULL && currentNode->left == NULL)
    {
        height = 1 + findHeight(currentNode->right);
    }
    else
    {
        height = 1;
    }
    return height;
}

nodeT *rotateLeft(nodeT *currentNode)
{
    nodeT *copy = currentNode->right;
    nodeT *copy2 = copy->left;
    copy->left = currentNode;
    currentNode->right = copy2;
    return copy;
}

nodeT *rotateRight(nodeT *currentNode)
{
    nodeT *copy = currentNode->left;
    nodeT *copy2 = copy->right;
    currentNode->right = currentNode;
    currentNode->left = copy2;
    return copy;
}

nodeT *checkAVL(nodeT *currentNode)
{
    int heightLeft,heightRight;
    if(currentNode->left != NULL)
    {
        heightLeft = findHeight(currentNode->left);
    }
    else
    {
        heightLeft = 0;
    }
    if(currentNode->right)
    {
        heightRight = findHeight(currentNode->right);
    }
    else
    {
        heightRight = 0;
    }
    if(heightLeft - heightRight > 1)
    {
        int heightLeftLeft, heightLeftRight;
        if(currentNode->left->left)
        {
            heightLeftLeft = findHeight(currentNode->left->left);
        }
        else
        {
            heightLeftLeft = 0;
        }
        if(currentNode->left->right)
        {
            heightLeftRight = findHeight(currentNode->left->right);
        }
        else
        {
            heightLeftRight = 0;
        }
        if(heightLeftLeft > heightLeftRight)
        {
            currentNode = rotateRight(currentNode);
        }
        else
        {
            currentNode->left= rotateLeft(currentNode->left);
            currentNode = rotateRight(currentNode);
        }
    }
    else if(heightRight - heightLeft > 1)
    {
        int heightRightRight,heightRightLeft;
        if(currentNode->right->right)
        {
            heightRightRight = findHeight(currentNode->right->right);
        }
        else
        {
            heightRightRight = 0;
        }
        if(currentNode->right->left)
        {
            heightRightLeft = findHeight(currentNode->right->left);
        }
        else
        {
            heightRightLeft = 0;
        }

        if(heightRightRight > heightRightLeft)
        {
            currentNode = rotateLeft(currentNode);
        }
        else
        {
            currentNode->right = rotateRight(currentNode->right);
            currentNode = rotateLeft(currentNode);
        }
    }
    return currentNode;
}

nodeT *insertInAVL(nodeT *currentNode, int nr)
{
    if(currentNode == NULL)
    {
        currentNode = (nodeT*)malloc(sizeof(nodeT));
        currentNode->data = nr;
        currentNode->left = NULL;
        currentNode->right = NULL;
    }
    else if(nr < currentNode->data)
    {
        currentNode->left = insertInAVL(currentNode->left,nr);
    }
    else
    {
        currentNode->right = insertInAVL(currentNode->right,nr);
    }
    currentNode = checkAVL(currentNode);
    return currentNode;
}

int main()
{
    int nrElements,i;
    printf("The nr of elements the AVL will have is: ");
    scanf("%d",&nrElements);
    for(i=0; i<nrElements; i++)
    {
        printf("New element to insert: ");
        int nr;
        scanf("%d",&nr);
        root = insertInAVL(root,nr);
    }
    inorder(root,0);
    return 0;
}
