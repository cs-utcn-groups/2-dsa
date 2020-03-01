//
// Created by Andreea on 3/1/2020.
//

#include "SLL.h"

void initializeList()
{
    first = NULL;
    last = NULL;
}
void addFirst(int x)
{
    nodeT *element = (nodeT *) malloc(sizeof(nodeT));
    element->value = x;
    if (last == NULL)
        last = element;
    element->next = first;
    first = element;
}
void addLast(int x)
{
    nodeT *element = (nodeT *) malloc(sizeof(nodeT));
    element->value = x;
    if (first == NULL)
        first = element;
    last->next = element;
    last = element;
    last->next = NULL;
}
void deleteFirst()
{
    nodeT* oldFirst = first;
    if(first != NULL)
    {
        first = first->next;
        free(oldFirst);
    }
    if(first == NULL)
        last = NULL;
}
void deleteLast()
{
    nodeT* oldLast = last, *currentElement = first;
    if(first == last)
    {
        free(first);
        first = NULL;
        last = NULL;
    }
    else
        if (last != NULL)
        {
            while(currentElement->next != last)
                currentElement = currentElement->next;
            currentElement->next = NULL;
            last = currentElement;
            free(oldLast);
        }
}
void doomTheList()
{
    nodeT* currentElement = first;
    while(first != NULL)
        deleteFirst();
}
void deleteElement(int x)
{
    nodeT* currentElement = first;
    nodeT* oldCurrentElement;
    nodeT* previousElement;
    while(currentElement != NULL)
    {
        if(currentElement -> value == x)
        {
            if(currentElement == first)
            {
                deleteFirst();
                currentElement = first;
            }
            else
                if(currentElement == last)
                {
                    deleteLast();
                    currentElement= NULL;
                }
                else
                {
                    oldCurrentElement = currentElement;
                    previousElement->next = currentElement ->next;
                    free(oldCurrentElement);
                    previousElement = currentElement;
                    currentElement = currentElement->next;
                }
        }
        else
            currentElement = currentElement->next;
    }
}
void printAll(FILE* ofptr)
{
    nodeT* currentElement = first;
    while(currentElement != NULL)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}
void printFirstXValues(FILE* ofptr, int x)
{
    nodeT* currentElement = first;
    int noOfElements = 0;
    while(noOfElements != x && currentElement != NULL)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        noOfElements++;
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}
int countElementsOfList()
{
    nodeT* currentElement = first;
    int noOfElements = 0;
    while(currentElement != NULL)
    {
        noOfElements++;
        currentElement = currentElement->next;
    }
    return noOfElements;
}
void printLastXValues(FILE* ofptr, int x)
{
    nodeT* currentElement = first;
    int noOfElements = 0;
    while(noOfElements < countElementsOfList() - x)
    {
        noOfElements++;
        currentElement = currentElement->next;
    }
    while(currentElement != NULL)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}