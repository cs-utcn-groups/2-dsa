#include "head.h"

void initializeSll()
{
    first = NULL;
    last = NULL;
}

void addElement(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = last;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
        last->next = newE1;
        newE1->next = Null;
        newE1->data = data;
        last = newE1;
    }
}

void removeElement(int data)
{
    NodeT*currentNode = first;
    NodeT*previousNode = first;
    while(currentNode != Null)
    {
        if(currentNode->data == data)
        {
            if(currentNode = first)
            {
                first = currentNode->next;
                free(currentNode);
                currentNode = first;
                previousNode = first;
            }
            else if(currentNode = last)
            {
                free(currentNode);
                last = previousNode;
                last->next = Null;
                currentNode = Null;
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

void printSllData()
{
    NodeT*currentNode = first;
    while(currentNode != Null)
    {
        printf("%d", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void removeAll()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
    printf("List have been cleared");
}
