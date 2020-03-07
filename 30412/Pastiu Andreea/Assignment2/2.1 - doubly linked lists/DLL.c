//
// Created by Andreea on 3/7/2020.
//

#include "DLL.h"

void initializeSentinelList()
{
    nodeT *newNode = (nodeT *) malloc(sizeof(nodeT));
    newNode->next = newNode;
    newNode->prev = newNode;
    sentinel = newNode;
}
void addFirst(int x)
{
    nodeT *element = (nodeT *) malloc(sizeof(nodeT));
    element->value = x;
    element->next = sentinel->next;
    sentinel->next->prev = element;
    element->prev = sentinel;
    sentinel->next = element;
}
void addLast(int x)
{
    nodeT *element = (nodeT *) malloc(sizeof(nodeT));
    element->value = x;
    element->prev = sentinel->prev;
    element->next = sentinel;
    sentinel->prev->next = element;
    sentinel->prev = element;
}
void deleteFirst()
{
    nodeT* oldFirst = sentinel->next;
    sentinel->next = oldFirst->next;
    oldFirst->next->prev = sentinel;
    if(oldFirst != sentinel)
        free(oldFirst);
}
void deleteLast()
{
    nodeT* oldLast = sentinel->prev;
    sentinel->prev = oldLast->prev;
    oldLast->prev->next = sentinel;
    if(oldLast != sentinel)
        free(oldLast);
}
void doomTheList()
{
    while(sentinel->next != sentinel)
        deleteFirst();
}
void deleteElement(int x)
{
    nodeT *currentElement = sentinel->next;
    while(currentElement != sentinel)
    {
        if(currentElement->value == x)
        {
            currentElement->prev->next = currentElement->next;
            currentElement->next->prev = currentElement->prev;
            nodeT *oldElement = currentElement;
            currentElement = currentElement->next;
            free(oldElement);
        }
        else
        {
            currentElement = currentElement->next;
        }
    }
}
void printAll(FILE* ofptr)
{
    nodeT* currentElement = sentinel->next;
    while(currentElement != sentinel)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}
void printFirstXValues(FILE* ofptr, int x)
{
    nodeT* currentElement = sentinel->next;
    int noOfElements = 0;
    while(noOfElements != x && currentElement != sentinel)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        noOfElements++;
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}
void printLastXValues(FILE* ofptr, int x)
{
    nodeT* currentElement = sentinel->prev;
    int noOfElements = 0;
    while(noOfElements != x && currentElement != sentinel)
    {
        noOfElements++;
        currentElement = currentElement->prev;
    }
    currentElement = currentElement->next;
    while(currentElement != sentinel)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}