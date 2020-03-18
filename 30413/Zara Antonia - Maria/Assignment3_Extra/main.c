#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_height 100

int totalHeight;

typedef struct node1
{
    char *id;
    struct node1 *left,*right;
} nodeT;

nodeT *root;

typedef struct node2
{
    char *id;
    struct node2 *next;
} nodeQ;

nodeQ *first,*last,*globalCurrent;

void initializeQueue()
{
    first = NULL;
    last = NULL;
}

void addElementInQueue(char *id)
{
    if(first == NULL)
    {
        first = (nodeQ*)malloc(sizeof(nodeQ));
        first->id = (char*)malloc(sizeof(char)*10);
        strcpy(first->id,id);
        first->next = NULL;
        last = first;
    }
    else
    {
        nodeQ *newNode = (nodeQ*)malloc(sizeof(nodeQ));
        newNode->id = (char*)malloc(sizeof(char)*10);
        strcpy(newNode->id,id);
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

void createQueueFromInput()
{
    char *strbuf = (char*)malloc(sizeof(char)*MAX_height);
    gets(strbuf);
    char *p;
    for(p = strtok(strbuf," "); p; p = strtok(NULL," \n"))
    {
        addElementInQueue(p);
    }
}

void printAllInQueue()
{
    nodeQ *newNode = first;
    printf("The list has the elements: ");
    do
    {
        printf("%s ",newNode->id);
        newNode = newNode->next;
    }
    while(newNode!=NULL);
    printf("\n\n");
}

int isNumber(char *p)
{
    if(strlen(p) == 1 && (p[0]=='+'||p[0]=='-'||p[0]=='*'||p[0]=='\\'))return 0;
    return 1;
}
nodeT *getTreeFromList()
{
    nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
    newNode->id = (char*)malloc(sizeof(char)*10);
    if(isNumber(globalCurrent->id) == 1)
    {
        strcpy(newNode->id,globalCurrent->id);
        newNode->right = NULL;
        newNode->left = NULL;
        globalCurrent = globalCurrent->next;
    }
    else
    {
        strcpy(newNode->id,globalCurrent->id);
        globalCurrent = globalCurrent->next;
        newNode->left = getTreeFromList();
        newNode->right = getTreeFromList();
    }
    return newNode;
}

void inorder(nodeT *currentNode, int level)
{
    if(currentNode != NULL)
    {
        inorder(currentNode->left,level+1);
        int i;
        for(i=0; i<=level; i++)printf("    ");
        printf("%s\n",currentNode->id);
        inorder(currentNode->right,level+1);
    }
}

int findHeight(nodeT *currentNode)
{
    if(currentNode->left == NULL && currentNode->right == NULL)
    {
        return 1;
    }
    else if(currentNode->left == NULL)
    {
        return 1+findHeight(currentNode->right);
    }
    else if(currentNode->right == NULL)
    {
        return 1+findHeight(currentNode->left);
    }
    else
    {
        int right,left;
        right = 1+findHeight(currentNode->right);
        left = 1+findHeight(currentNode->left);
        if(right>left)return right;
        else return left;
    }
}

void printGivenLevel(nodeT* currentNode, int level, int initialLevel)
{
    if (currentNode == NULL)
    {
        int i;
        for(i=0; i<totalHeight-initialLevel+1; i++)printf("    ");
        printf("   ");///because there's nothing there
    }
    else
    {
        if (level == 1)
        {
            int i;
            for(i=0; i<totalHeight-initialLevel+1; i++)printf("    ");
            printf("%s", currentNode->id);
        }
        else if (level > 1)
        {
            printGivenLevel(currentNode->left, level-1,initialLevel);
            printGivenLevel(currentNode->right, level-1,initialLevel);
        }
    }
}

void printLevelOrder(nodeT* root)
{
    int height = findHeight(root);
    int i;
    for (i=1; i<=height; i++)
    {
        printGivenLevel(root, i,i);
        printf("\n\n");
    }
}

int main()
{
    initializeQueue();
    createQueueFromInput();
    printAllInQueue();
    globalCurrent = first;
    root = getTreeFromList();
    totalHeight = findHeight(root);

    ///i tried for 3 days to do this function and couldn't
    ///so i used stack overflow and added fancy stuff sorry
    printLevelOrder(root);
    return 0;
}
