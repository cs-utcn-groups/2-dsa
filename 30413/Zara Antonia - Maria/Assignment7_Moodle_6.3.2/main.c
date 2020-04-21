#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 23

typedef struct node
{
    char *data;
    struct node *next;
} nodeT;

nodeT *BucketTable[B];

void initializeBucket()
{
    int i;
    for(i=0; i<B; i++)
    {
        BucketTable[i] = NULL;
    }
}

int hashFunction(char *string)
{
    int length = strlen(string);
    int i,sum = 0;

    for(i=0; i<length; i++)
    {
        sum = sum + string[i];
    }
    return sum%B;
}

void printH()
{
    int i;
    for(i=0; i<B; i++)
    {
        if(BucketTable[i] != NULL)
        {
            nodeT *p = BucketTable[i];
            while(p!=NULL)
            {
                printf("%s\t",p->data);
                p = p->next;
            }
            printf("\n");
        }
    }
}

void insert (char *string)
{
    int index = hashFunction(string);
    nodeT *p = (nodeT*)malloc(sizeof(nodeT));
    p->data = string;
    p->next = NULL;
    if(BucketTable[index] == NULL)
    {
        BucketTable[index] = p;
    }
    else
    {
        nodeT *newNode = BucketTable[index];
        while(newNode->next)
        {
            newNode = newNode->next;
        }
        newNode->next = p;
    }
}

nodeT *find(char *string, int index)
{
    if(BucketTable[index])
    {
        nodeT *copy = BucketTable[index];
        int isFound = 0;
        while(copy)
        {
            if(strcmp(copy->data,string)==0)
            {
                isFound = 1;
                break;
            }
            else copy = copy->next;
        }
        if(isFound == 0)return NULL;
                    else return copy;
    }
    else return NULL;
}

void findH(char *string)
{
    int index = hashFunction(string);
    nodeT *temp = find(string,index);
    if(temp == NULL) printf("Not found.\n");
                else printf("Found at index %d.\n",index);
}

void deleteH(char *string)
{
    int index = hashFunction(string);
    nodeT *copy = find(string,index);
    if(copy)
    {
        if(BucketTable[index] == copy)
        {
            ///daca e primul
           BucketTable[index] = BucketTable[index]->next;
        }
        else
        {
            nodeT *currentNode = BucketTable[index];
            nodeT *parent = NULL;
            while(currentNode != copy)
            {
                parent = currentNode;
                currentNode = currentNode->next;
            }

            if(currentNode->next)
            {
                parent->next = currentNode->next;
                free(currentNode);
                currentNode = parent->next;
            }
            else
            {
                parent->next = NULL;
                currentNode = NULL;
            }
        }
    }
}

int main()
{
    initializeBucket();
    printf("Start entering instructions:\n");
    do
    {
        char *instruction = (char*)malloc(sizeof(char)*200);
        gets(instruction);
        if(instruction[0] == 'i')insert(instruction+1);
        else if(instruction[0] == 'd')deleteH(instruction+1);
        else if(instruction[0] == 'f')findH(instruction+1);
        else if(instruction[0] == 'l')printH();
        else break;

    }
    while(1);

    printf("\nThe program has ended.");
    return 0;
}
