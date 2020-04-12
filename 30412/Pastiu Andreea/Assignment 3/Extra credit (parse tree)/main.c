#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256

typedef struct vertex
{
    char *treeNode;
    struct vertex *left, *right;
}vertexT;
typedef struct node
{
    vertexT *id;
    struct node *next;
}nodeT;
nodeT *firstQueue, *lastQueue;

vertexT *createBinTree(char *line);
void printTree(vertexT *root);
void addLast(vertexT *newNode);
void deleteFirst();

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
        char *line;
        line = (char*) malloc(sizeof(char));
        fgets(line, MAX_LINE, ifptr);
        vertexT *root = createBinTree(line);
        printTree(root);
    }
    return 0;
}

vertexT *createBinTree(char *line)
{
    vertexT *currentVertex = (vertexT *) malloc(sizeof(vertexT));
    char *token = (char*) malloc(sizeof(char));
    sscanf(line, "%s", token);
    char *spacePtr = strchr(line, ' ');
    if(spacePtr != NULL)
        strcpy(line, spacePtr+1);
    currentVertex->treeNode = (char*) malloc(sizeof(char));
    if((strpbrk("+-*/", token) != NULL) && ((token[1] == '\0')))
    {
        strcpy(currentVertex->treeNode, token);
        currentVertex->left = createBinTree(line);
        currentVertex->right = createBinTree(line);
        return currentVertex;
    }
    else
    {
        strcpy(currentVertex->treeNode, token);
        currentVertex->left = NULL;
        currentVertex->right = NULL;
        return currentVertex;
    }
}

void initializeQueue()
{
    firstQueue = NULL;
    lastQueue = NULL;
}
void addLast(vertexT *newNode)
{
    nodeT *element = (nodeT*) malloc(sizeof(nodeT));
    element->id = newNode;
    if (firstQueue == NULL)
    {
        element->next = NULL;
        firstQueue = element;
        lastQueue = element;
    }
    else
    {
        lastQueue->next = element;
        lastQueue = element;
        lastQueue->next = NULL;
    }
}
void deleteFirst()
{
    nodeT* oldFirst = firstQueue;
    if(firstQueue != NULL)
    {
        firstQueue = firstQueue->next;
        free(oldFirst);
    }
    if(firstQueue == NULL)
        lastQueue = NULL;
}
void printTree(vertexT *root)
{
    if(root!= NULL)
    {
        initializeQueue();
        vertexT *currentVertex;
        addLast(root);
        vertexT *newNode = (vertexT*) malloc(sizeof(vertexT));
        newNode->treeNode = (char*) malloc(sizeof(char));
        strcpy(newNode->treeNode, "$");
        addLast(newNode);
        while(firstQueue->next != NULL)
        {
            vertexT *newNode2 = (vertexT*) malloc(sizeof(vertexT));
            newNode2->treeNode = (char*) malloc(sizeof(char));
            strcpy(newNode2->treeNode, "$");
            currentVertex = firstQueue->id;
            deleteFirst();
            if (strcmp(currentVertex->treeNode, "$") == 0)
            {
                addLast(newNode2);
                printf("\n");
            }
            else
            {
                if(currentVertex->left != NULL)
                {
                    addLast(currentVertex->left);
                }
                if (currentVertex->right != NULL)
                {
                    addLast(currentVertex->right);
                }
                printf("%s ", currentVertex->treeNode);
            }
        }
    }
}