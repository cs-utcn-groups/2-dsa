#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertex
{
    int id;
    struct vertex *left, *right;
}vertexT;

typedef struct node
{
    int id;
    struct node *prev, *next;
}nodeT;

void prettyPrint(vertexT *root, int level);
vertexT *getTreeFromList(nodeT **firstFromList);
void traverseList(nodeT *t);
nodeT *getListFromTree(vertexT *root);
vertexT *createBinTree(FILE *ifptr);
void addNodeLast(nodeT **firstFromList, nodeT **lastFromList, int id);
void preorderTreeToList(nodeT **firstFromList, nodeT **lastFromList, vertexT *root);
void initializeList(nodeT **firstFromList, nodeT **lastFromList);

int main()
{
    FILE *ifptr = fopen("input.dat", "r");
    if(ifptr == NULL)
    {
        perror("ifptr");
        exit(EXIT_FAILURE);
    }
    else
    {
        vertexT *root = createBinTree(ifptr);
        nodeT *firstFromList = getListFromTree(root);
        traverseList(firstFromList);
        root = getTreeFromList(&firstFromList);
        printf("A very very pretty printing right here:\n");
        prettyPrint(root, 0);
    }

    return 0;
}

vertexT *createBinTree(FILE *ifptr)
{
    vertexT *currentVertex = (vertexT *) malloc(sizeof(vertexT));
    char *s = (char*) malloc(sizeof(char));
    fscanf(ifptr, "%s", s);
    if(strcmp(s, "*") == 0)
    {
        return NULL;
    }
    int id = strtol(s, &s, 10);
    currentVertex->id = id;
    currentVertex->left = createBinTree(ifptr);
    currentVertex->right = createBinTree(ifptr);
    return currentVertex;
}

void initializeList(nodeT **firstFromList, nodeT **lastFromList)
{
    (*firstFromList) = NULL;
    (*lastFromList) = NULL;
}

void addNodeLast(nodeT **firstFromList, nodeT **lastFromList, int id)
{
    nodeT *newNode = (nodeT*) malloc(sizeof(nodeT));
    newNode->id = id;
    if((*firstFromList) == NULL)
    {
        (*firstFromList) = newNode;
        (*firstFromList)->next = NULL;
        (*firstFromList)->prev = NULL;
        (*lastFromList) = newNode;
        (*lastFromList)->next = NULL;
        (*lastFromList)->prev = NULL;
    }
    else
    {
        (*lastFromList)->next = newNode;
        newNode->prev = (*lastFromList);
        (*lastFromList) = newNode;
        (*lastFromList)->next = NULL;
    }
}

void preorderTreeToList(nodeT **firstFromList, nodeT **lastFromList, vertexT *root)
{
    vertexT *currentVertex = root;
    if(currentVertex != NULL)
    {
        addNodeLast(firstFromList, lastFromList, root->id);
        preorderTreeToList(firstFromList, lastFromList, root->left);
        preorderTreeToList(firstFromList, lastFromList, root->right);
    }
    else
    {
        addNodeLast(firstFromList, lastFromList, -1);
    }
}

nodeT *getListFromTree(vertexT *root)
{
    nodeT *firstFromList = (nodeT*) malloc(sizeof(nodeT));
    nodeT *lastFromList = (nodeT*) malloc(sizeof(nodeT));
    initializeList(&firstFromList, &lastFromList);
    preorderTreeToList(&firstFromList, &lastFromList, root);
    return firstFromList;
}

void traverseList(nodeT *firstFromList)
{
    printf("The list formed from the tree is:\n");
    nodeT *currentNode = firstFromList;
    while(currentNode != NULL)
    {
        if (currentNode->id == -1)
        {
            printf("* ");
        }
        else
        {
            printf("%d ", currentNode->id);
        }
        currentNode = currentNode->next;
    }
    printf("\n");
}

vertexT *getTreeFromList(nodeT **firstFromList)
{
    vertexT *currentVertex = (vertexT*) malloc(sizeof(vertexT));
    if(firstFromList != NULL)
    {
        if ((*firstFromList)->id == -1)
        {
            return NULL;
        }
        currentVertex->id = (*firstFromList)->id;
        *firstFromList = (*firstFromList)->next;
        currentVertex->left = getTreeFromList(firstFromList);
        *firstFromList = (*firstFromList)->next;
        currentVertex->right = getTreeFromList(firstFromList);
        return currentVertex;
    }
}

void prettyPrint(vertexT *root, int level)
{
    if(root != NULL)
    {
        prettyPrint(root->right, level+1);
        for(int i = 0; i < level; i++)
        {
            printf("       ");
        }
        printf("%d\n", root->id);
        prettyPrint(root->left, level+1);
    }
}
