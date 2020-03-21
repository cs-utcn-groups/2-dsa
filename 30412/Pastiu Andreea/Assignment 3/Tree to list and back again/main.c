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

void prettyPrint(vertexT *pVertex, int i);
vertexT *getTreeFromList(nodeT *t);
void traverseList(nodeT *t);
nodeT *getListFromTree(vertexT *pVertex);
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
        root = getTreeFromList(firstFromList);
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
        printf("%d ", currentNode->id);
        currentNode = currentNode->next;
    }
    printf("\n");
}

vertexT *getTreeFromList(nodeT *t)
{
    return NULL;
}

void prettyPrint(vertexT *pVertex, int i)
{

}
