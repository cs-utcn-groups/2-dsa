#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * f;

typedef struct node
{
    int data;
    struct node * next, * previous;

} NodeT;

NodeT * sentinelFirst, * sentinelLast;

void initializeDll()
{
    sentinelFirst =(NodeT*)malloc(sizeof(NodeT));
    sentinelLast = (NodeT*)malloc(sizeof(NodeT));
    sentinelFirst->next = sentinelLast;
    sentinelLast->previous = sentinelFirst;
    sentinelFirst->previous = NULL;
    sentinelLast->next = NULL;
}

void addFirst(int data)
{
    NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->data = data;
    newElement->next = sentinelFirst->next;
    sentinelFirst->next = newElement;
    newElement->previous = sentinelFirst;
    newElement->next->previous = newElement;
}

void addLast(int data)
{
    NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->data = data;
    newElement->next = sentinelLast;
    newElement->previous = sentinelLast->previous;
    newElement->previous->next = newElement;
    sentinelLast->previous = newElement;

}

void deleteLast()
{
    if(sentinelFirst->next == sentinelLast)
    {
        return;
    }
    NodeT * currentElement = sentinelLast->previous;
    currentElement->previous->next = sentinelLast;
    sentinelLast->previous = currentElement->previous;
    free(currentElement);
}

void deleteFirst()
{
    if(sentinelFirst->next == sentinelLast)
    {
        return;
    }
    NodeT * currentElement = sentinelFirst->next;
    currentElement->next->previous = sentinelFirst;
    sentinelFirst->next = currentElement->next;
    free(currentElement);
}

void removeElement(int data)
{
    NodeT * currentElement = sentinelFirst->next;
    while(currentElement != sentinelLast)
    {
        if(currentElement->data == data)
        {
            currentElement->previous->next = currentElement->next;
            currentElement->next->previous = currentElement->previous;
            free(currentElement);
            return;
        }
        else
        {
            currentElement = currentElement->next;
        }

    }
}

void removeAll()
{

    NodeT * currentElement = sentinelFirst->next;
    while(currentElement != sentinelLast)
    {
        sentinelFirst->next = currentElement->next;
        free(currentElement);
        currentElement = sentinelFirst->next;
    }

    sentinelFirst->next = sentinelLast;
    sentinelLast->previous = sentinelFirst;

}

void printAll()
{
    if(sentinelFirst->next == sentinelLast)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = sentinelFirst->next;
        while(currentElement != sentinelLast)
        {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
    }

}

void print_f(int nr)
{
    int i;
    if(sentinelFirst->next == sentinelLast)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = sentinelFirst->next;
        for(i=0; i<nr; i++)
        {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
    }
}

void print_l(int nr)
{
    int i=0, j;
    if(sentinelFirst->next == sentinelLast)
    {
        printf("List is empty!\n");
    }
    else
    {
        NodeT * currentElement = sentinelLast->previous;
        while(i<nr-1)
        {
            currentElement = currentElement->previous;
            i++;
        }
        for(j=0; j<=i; j++)
        {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
    }

}

void verifyInstruction(char * instruction, int nr)
{
    if(strlen(instruction) == 2)
    {
        if(instruction[0]=='A')
        {
            if(instruction[1]=='F')
            {
                addFirst(nr);

            }
            else
            {
                addLast(nr);
            }
        }
        else
        {
            if(instruction[1]=='F')
            {
                deleteFirst();
            }
            else
            {
                if(instruction[1]=='L')
                {
                    deleteLast();
                }
                else
                {
                    removeElement(nr);
                }
            }
        }

    }
    else
    {
        if(instruction[2]=='O')
        {
            removeAll();
        }
        else
        {
            if(instruction[6]=='A')
            {
                printAll();
            }
            else
            {
                if(instruction[6]=='F')
                {
                    print_f(nr);
                }
                else
                {
                    print_l(nr);
                }
            }
        }
    }
}

int main()
{
    initializeDll();
    int nr;
    char * instruction = (char*)malloc(sizeof(char)*15);
    char * line = (char*)malloc(sizeof(char)*15);
    char * piece = (char*)malloc(sizeof(char)*15);
    f = fopen("input.dat", "r");
    while((fgets(line, 15, f)!=NULL))
    {
        piece = strtok(line, " ");
        strcpy(instruction, piece);
        piece = strtok(NULL, " ");
        nr = atoi(piece);
        if(instruction[2]=='\n')
        {
            instruction[2]='\0';
        }
        verifyInstruction(instruction,nr);
    }
    return 0;
}
