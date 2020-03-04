#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
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

    for(i=0; i<length-1; i++)
    {
        lastDigit = (int)string[i] - '0';
        number = number*10 + lastDigit;
    }

    return number;
}

void AddFirst(int data)
{
    if(first == NULL)
    {
        first = (nodeT*)malloc(sizeof(nodeT));
        first->data = data;
        first->next = last;
        last = first;
    }
    else
    {
        nodeT *newNode = (nodeT*)malloc(sizeof(nodeT));
        newNode->data = data;
        newNode->next = first;
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
        last = first;
    }
    else
    {
        nodeT * newNode = (nodeT*)malloc(sizeof(nodeT));
        newNode->data = data;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

void deleteFirst()
{
    nodeT *currentNode = first->next;
    free(first);
    first = currentNode;
}

void deleteLast()
{
    if(first != NULL)
    {
        nodeT *currentNode = first;
        while(currentNode->next != last)
        {
            currentNode = currentNode->next;
        }
        free(last);
        last = currentNode;
        last->next = NULL;
    }
}

void doomTheList()
{
    nodeT *currentNode = first;
    while(currentNode != NULL)
    {
        first = first->next;
        free(currentNode);
        currentNode = first;
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
                previousNode = first;
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
    nodeT *currentNode = first;
    while(currentNode != NULL)
    {
        fprintf(g,"%d ",currentNode->data);
        currentNode = currentNode->next;
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
    nodeT *currentNode = first;

    int nrElements = 0;
    while(currentNode != NULL)
    {
        nrElements++;
        currentNode = currentNode->next;
    }

    int i;
    currentNode = first;
    if(nrElements <= nr)
    {
        printAll(g);
    }
    else
    {
        for(i=1; i<=nrElements; i++)
        {
            if(i > nrElements - nr)
            {
                fprintf(g,"%d ",currentNode->data);
            }
            currentNode = currentNode->next;
        }
    }
    fprintf(g,"\n");
}

void recognizeFunction(char *strbuf, FILE *g)
{
    ///AddFirst
    if(strbuf[0] == 'A' && strbuf[1] == 'F')
    {
        char *number = (char*)malloc(sizeof(char)*10);
        number = createStringNumber(strbuf,3);

        int x;
        x = charToInt(number);

        AddFirst(x);
    }

    ///AddLast
    if(strbuf[0] == 'A' && strbuf[1] == 'L')
    {
        char *number = (char*)malloc(sizeof(char)*10);
        number = createStringNumber(strbuf,3);

        int x;
        x = charToInt(number);

        AddLast(x);
    }

    if(strbuf[0] == 'D' && strbuf[1] == 'F')deleteFirst();

    if(strbuf[0] == 'D' && strbuf[1] == 'L')deleteLast();

    if(strbuf[0] == 'D' && strbuf[1] == 'O')doomTheList();

    ///deleteElement
    if(strbuf[0] == 'D' && strbuf[1] == 'E')
    {
        char *number = (char*)malloc(sizeof(char)*10);
        number = createStringNumber(strbuf,3);

        int x;
        x = charToInt(number);

        deleteElement(x);
    }

    if(strbuf[0] == 'P' && strbuf[6] == 'A')printAll(g);

    ///printFirst
    if(strbuf[0] == 'P' && strbuf[6] == 'F')
    {
        char *number = (char*)malloc(sizeof(char)*10);
        number = createStringNumber(strbuf,8);

        int x;
        x = charToInt(number);

        printFirst(x,g);
    }

    ///printLast
    if(strbuf[0] == 'P' && strbuf[6] == 'L')
    {
        char *number = (char*)malloc(sizeof(char)*10);
        number = createStringNumber(strbuf,8);

        int x;
        x = charToInt(number);

        printLast(x,g);
    }
}

int main()
{
    initializeList();

    FILE *f = fopen("input.dat","r");
    FILE *g = fopen("output.dat","w");

    char *strbuf = (char*)malloc(sizeof(char)*20);

    while(fgets(strbuf,20,f) != NULL)
    {
        recognizeFunction(strbuf,g);
    }

    return 0;
}
