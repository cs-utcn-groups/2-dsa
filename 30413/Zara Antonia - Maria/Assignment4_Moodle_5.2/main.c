#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char id;
    struct node *left,*right;
} nodeT;

nodeT *root;

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
        printf("%c\n",currentNode->id);
        inorder(currentNode->right,level+1);
    }
}

void preorder(nodeT *currentNode, int level)
{
    if(currentNode)
    {
        int i;
        for(i=0; i<level; i++)printf("   ");
        printf("%c",currentNode->id);
        preorder(currentNode->left,level+1);
        preorder(currentNode->right,level+1);
    }
}

void postorder(nodeT *currentNode, int level)
{
    if(currentNode)
    {
        postorder(currentNode->left,level+1);
        postorder(currentNode->right,level+1);
        int i;
        for(i=0; i<level; i++)printf("   ");
        printf("%c",currentNode->id);
    }
}

nodeT *insert(nodeT *currentNode, char newLetter)
{
    if(currentNode == NULL)
    {
        currentNode = (nodeT*)malloc(sizeof(nodeT));
        currentNode->id = newLetter;
        currentNode->left = NULL;
        currentNode->right = NULL;
    }
    else if(newLetter < currentNode->id)
    {
        currentNode->left = insert(currentNode->left,newLetter);
    }
    else if(newLetter > currentNode->id)
    {
        currentNode->right = insert(currentNode->right,newLetter);
    }
    return currentNode;
}

nodeT *findMax(nodeT *root)
{
    nodeT *currentNode = root;
    nodeT *max = (nodeT*)malloc(sizeof(nodeT));
    if(currentNode == NULL)
    {
        max = NULL;
    }
    else
    {
        do
        {
            max = currentNode;
            currentNode = currentNode->right;
        }
        while(currentNode != NULL);
    }
    return max;
}

nodeT *findMin(nodeT *root)
{
    nodeT *currentNode = root;
    nodeT *min = (nodeT*)malloc(sizeof(nodeT));
    if(currentNode == NULL)
    {
        min = NULL;
    }
    else
    {
        do
        {
            min = currentNode;
            currentNode = currentNode->left;
        }
        while(currentNode != NULL);
    }
    return min;
}

nodeT *deleteNode(nodeT *currentNode, char letter)
{
    if(letter < currentNode->id)
    {
        currentNode->left = deleteNode(currentNode->left,letter);
    }
    else if(letter > currentNode->id)
    {
        currentNode->right = deleteNode(currentNode->right,letter);
    }
    else
    {
        nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));

        if(currentNode->left && currentNode->right)
        {
            newNode = findMin(currentNode->right);
            currentNode->id = newNode->id;
            currentNode->right = deleteNode(currentNode->right,newNode->id);
        }
        else if(currentNode->left == NULL && currentNode->right != NULL)
        {
            newNode = currentNode;
            currentNode = currentNode->right;
            free(newNode);
        }
        else
        {
            newNode = currentNode;
            currentNode = currentNode->left;
            free(newNode);
        }
    }
    return currentNode;
}

nodeT *findNode(nodeT *currentNode, char letter)
{
    if(currentNode == NULL)
    {
        printf("No such node\n");
        return NULL;
    }
    else if(currentNode->id == letter)
    {
        return currentNode;
    }
    else if(letter < currentNode->id)
    {
        currentNode = findNode(currentNode->left,letter);
    }
    else if(letter > currentNode->id)
    {
        currentNode = findNode(currentNode->right,letter);
    }
    return currentNode;
}

int main()
{
    root = NULL;
    char *instruction = (char*)malloc(sizeof(char)*4);
    do
    {
        gets(instruction);
        if(instruction[0] == 'i')
        {
            root = insert(root,instruction[1]);
        }
        else if(instruction[0] == 'd')
        {
            root = deleteNode(root,instruction[1]);
        }
        else if(instruction[0] == 'f')
        {
            nodeT *newNode = findNode(root,instruction[1]);
            printf("Found the node %c\n",newNode->id);
        }
        else if(instruction[0] == 't')
        {
            if(instruction[1] == 'p')preorder(root,0);
            else if(instruction[1] == 'i')inorder(root,0);
            else if(instruction[1] == 'P')postorder(root,0);
        }
        else if(instruction[0] == 'g')
        {
            nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
            if(instruction[1] == 'm')
            {
                newNode = findMin(root);
                printf("The minimum is: %c\n",newNode->id);
            }
            else
            {
                newNode = findMax(root);
                printf("The maximum is: %c\n",newNode->id);
            }
        }
        else break;
    }
    while(strcmp(instruction,"end")!=0);

    printf("\nThe program has ended.\n");
    return 0;
}
