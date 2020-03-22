//
// Created by Andreea on 3/7/2020.
//

#include "DLL.h"

void initializeSentinelList()
{
    sentinelT *newNode = (sentinelT *) malloc(sizeof(sentinelT));
    newNode->head = NULL;
    newNode->tail = NULL;
    sentinel = newNode;
}
void addFirst(int x)
{
    nodeT *element = (nodeT *) malloc(sizeof(nodeT));
    element->value = x;
    element->next = sentinel->head;
    if(sentinel->head != NULL)
    {
        sentinel->head->prev = element;
    }
    element->prev = NULL;
    sentinel->head = element;
    if(sentinel->tail == NULL)
    {
        sentinel->tail = element;
    }
}
void addLast(int x)
{
    nodeT *element = (nodeT *) malloc(sizeof(nodeT));
    element->value = x;
    element->prev = sentinel->tail;
    element->next = NULL;
    if(sentinel->tail != NULL)
    {
        sentinel->tail->next = element;
    }
    sentinel->tail = element;
    if(sentinel->head == NULL)
    {
        sentinel->head = element;
    }
}
void deleteFirst()
{
    nodeT* oldFirst = sentinel->head;
    if(oldFirst != NULL)
    {
        sentinel->head = oldFirst->next;
        if (oldFirst->next != NULL)
        {
            oldFirst->next->prev = NULL;
        } else
        {
            sentinel->tail = NULL;
        }
        free(oldFirst);
    }
}
void deleteLast()
{
    nodeT* oldLast = sentinel->tail;
    if(oldLast != NULL)
    {
        sentinel->tail = oldLast->prev;
        if (oldLast->prev != NULL)
        {
            oldLast->prev->next = NULL;
        } else
        {
            sentinel->head = NULL;
        }
        free(oldLast);
    }
}
void doomTheList()
{
    while(sentinel->head != NULL)
        deleteFirst();
}
void deleteElement(int x)
{
    nodeT *currentElement = sentinel->head;
    while(currentElement != NULL)
    {
        if(currentElement->value == x)
        {
            if(currentElement->prev)
            {
                currentElement->prev->next = currentElement->next;
            }
            else
            {
                if(currentElement->next != NULL)
                {
                    sentinel->head = currentElement->next;
                }
                else
                {
                    sentinel->head = NULL;
                    sentinel->tail = NULL;
                }
            }
            if(currentElement->next != NULL)
            {
                currentElement->next->prev = currentElement->prev;
            }
            else
            {
                if(currentElement->prev != NULL)
                {
                    sentinel->tail = currentElement->prev;
                }
                else
                {
                    sentinel->head = NULL;
                    sentinel->tail = NULL;
                }
            }
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
    nodeT* currentElement = sentinel->head;
    while(currentElement != NULL)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}
void printFirstXValues(FILE* ofptr, int x)
{
    nodeT* currentElement = sentinel->head;
    int noOfElements = 0;
    while(noOfElements != x && currentElement != NULL)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        noOfElements++;
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}
void printLastXValues(FILE* ofptr, int x)
{
    nodeT* currentElement = sentinel->tail;
    int noOfElements = 0;
    while(noOfElements != x && currentElement != NULL)
    {
        noOfElements++;
        currentElement = currentElement->prev;
    }
    currentElement = currentElement->next;
    while(currentElement != NULL)
    {
        fprintf(ofptr, "%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    fprintf(ofptr, "\n");
}