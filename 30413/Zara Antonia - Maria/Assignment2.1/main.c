#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
AF 5
AF 6
AF 21
AL 12
DF
DL
DE 3
DE 6
AF 2
AL 200
PRINT_ALL
AF 1
PRINT_F 2
PRINT_L 3
DOOM_THE_LIST
DL
AF 42
AL 24
AF 9
PRINT_ALL
PRINT_L 2
**/

typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
} nodeT;

nodeT *first, *last;

void initializeList()
{
    first = NULL;
    last = NULL;
}

char *createStringNumber(char *strbuf, int start)
{
    int currentPosition,currentPositionInNumber = 0;

    char *number = (char*)malloc(sizeof(char)*10);
    number[0] = '\0';

    for(currentPosition = start; strbuf[currentPosition] != '\0'; currentPosition++)
    {
        number[currentPositionInNumber] = strbuf[currentPosition];
        number[currentPositionInNumber+1] = '\0';
        currentPositionInNumber++;
    }

    return number;
}

int charToInt(char *string)
{
    int number = 0,lastDigit,i;
    int length = strlen(string);

    for(i=0; i<length; i++)
    {
        lastDigit = (int)string[i] - '0';
        number = number*10 + lastDigit;
    }

    return number;
}

void AddFirst(int data)
{
    if(last == NULL)
    {
        last = (nodeT*)malloc(sizeof(nodeT));
        last->data = data;
        last->previous = NULL;
        last->next = NULL;
        first = last;
    }
    else
    {
        nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
        newNode->next = first;
        newNode->data = data;
        newNode->previous = NULL;
        first = newNode;
    }
}

void AddLast(int data)
{
    if(first == NULL)
    {
        first = (nodeT*)malloc(sizeof(nodeT));
        first->data = data;
        first->next = NULL;
        first->previous = NULL;
        last = first;
    }
    else
    {
        nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
        last->next = newNode;
        newNode->next = NULL;
        newNode->data = data;
        newNode->previous = last;
        last = newNode;
    }
}

void deleteFirst()
{
    if(last != NULL && first!=NULL)
    {
        nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
        newNode = first->next;
        free(first);
        first = newNode;
        first->previous = NULL;
    }
}

void deleteLast()
{
    if(last != NULL && first!=NULL)
    {
        nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
        newNode = last->previous;
        free(last);
        newNode->next = NULL;
        last = newNode;
    }
}

void doomTheList()
{

    nodeT *newNode;
    newNode = first;
    while(newNode != NULL)
    {
        first = first->next;
        free(newNode);
        newNode = first;
    }

}

void deleteElement(int data)
{
    nodeT *currentNode = first;
    nodeT *previousNode = first;

    while(currentNode != NULL)
    {
        if(currentNode->data == data)
        {
            if(currentNode == first)
            {
                first = currentNode->next;
                free(currentNode);
                currentNode = first;
                currentNode->previous = NULL;
                previousNode = first;
                previousNode->previous = NULL;
            }
            else if(currentNode == last)
            {
                free(currentNode);
                last = previousNode;
                last->next = NULL;
                currentNode = NULL;
            }
            else
            {
                previousNode->next = currentNode->next;
                free(currentNode);
                currentNode = previousNode->next;
                currentNode->previous = previousNode;
            }
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

void printAll(FILE *g)
{
    if(first == NULL)
    {
        fprintf(g,"List is already empty.");
    }
    else
    {
        nodeT *currentNode = first;
        while(currentNode != NULL)
        {
            fprintf(g,"%d ",currentNode->data);
            currentNode = currentNode->next;
        }
    }
    fprintf(g,"\n");
}

void printFirst(int nr, FILE *g)
{
    int i;
    nodeT *currentNode = first;
    for(i=0; i<nr && currentNode != NULL; i++)
    {
        fprintf(g,"%d ",currentNode->data);
        currentNode = currentNode->next;
    }
    fprintf(g,"\n");
}

void printLast(int nr, FILE *g)
{
    int i;
    nodeT *newNode = first;
    int nrElements = 0;
    while(newNode != NULL)
    {
        nrElements++;
        newNode = newNode->next;
    }

    newNode = first;
    for(i=0; i<nr && newNode != NULL; i++)
    {

        ///if(i > nrElements - nr)
        {
            fprintf(g,"%d ",newNode->data);
            newNode = newNode->next;
        }
    }
    fprintf(g,"\n");
}

void recognizeFunction(char *strbuf, FILE *g)
{
    int number;
    char *p = (char*)malloc(sizeof(char)*20);
    char *functionName = (char*)malloc(sizeof(char)*20);

    p = strtok(strbuf," \n");
    strcpy(functionName,p);

    p = strtok(NULL,"\n");
    if(p)number = charToInt(p);

    if(strcmp(functionName,"AF") == 0)AddFirst(number);
    if(strcmp(functionName,"AL") == 0)AddLast(number);
    if(strcmp(functionName,"DF") == 0)deleteFirst();
    if(strcmp(functionName,"DL") == 0)deleteLast();
    if(strcmp(functionName,"DE") == 0)deleteElement(number);
    if(strcmp(functionName,"PRINT_L") == 0)printLast(number,g);
    if(strcmp(functionName,"PRINT_F") == 0)printFirst(number,g);
    if(strcmp(functionName,"PRINT_ALL") == 0)printAll(g);
    if(strcmp(functionName,"DOOM_THE_LIST") == 0)doomTheList();
}

int main()
{
    initializeList();

    FILE *f = fopen("input.dat","r");
    FILE *g = fopen("output.dat","w");

    char *strbuf = (char*)malloc(sizeof(char)*30);

    while(fgets(strbuf,30,f) != NULL)
    {
        recognizeFunction(strbuf,g);
    }

    fclose(f);
    fclose(g);

    return 0;
}
