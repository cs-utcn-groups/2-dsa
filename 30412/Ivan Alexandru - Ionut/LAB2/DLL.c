//
// Created by Ivan on 3/5/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

listPtr* createEmptyList()
{
    listPtr* l = (listPtr*)malloc(sizeof(listPtr));
    if(l)
    {
        l->first = NULL;
        l->last = NULL;
        l->numberOfElements = 0;
        return l;
    }else return NULL;
}

void addFirst(int key)
{
    if(LIST->first == NULL)
    {
        LIST->first = (Node*)malloc(sizeof(Node));
        LIST->first->data = key;
        LIST->first->next = NULL;
        LIST->first->prev = NULL;
    }else if(LIST->last == NULL)
    {
        LIST->last = (Node*)malloc(sizeof(Node));
        LIST->last->data = LIST->first->data;
        LIST->last->next = NULL;
        LIST->first->data = key;
        LIST->first->next = LIST->last;
        LIST->last->prev = LIST->first;
    } else
    {
        Node* newElem = (Node*)malloc(sizeof(Node));
        newElem->data = key;
        newElem->next = LIST->first;
        newElem->prev = NULL;
        LIST->first->prev = newElem;
        LIST->first = newElem;
    }
    LIST->numberOfElements++;
}

void addLast(int key)
{
    if(LIST->first == NULL)
    {
        LIST->first = (Node*)malloc(sizeof(Node));
        LIST->first->data = key;
        LIST->first->next = NULL;
        LIST->first->prev = NULL;
    }else if(LIST->last == NULL)
    {
        LIST->last = (Node*)malloc(sizeof(Node));
        LIST->last->data = key;
        LIST->last->next = NULL;
        LIST->first->next = LIST->last;
        LIST->last->prev = LIST->first;
    } else
    {
        Node* newElem = (Node*)malloc(sizeof(Node));
        newElem->data = key;
        newElem->next = NULL;
        newElem->prev = LIST->last;
        LIST->last->next = newElem;
        LIST->last = newElem;
    }
    LIST->numberOfElements++;
}

void deleteFirst()
{
    Node* element = LIST->first;
    LIST->first = LIST->first->next;
    LIST->first->prev = NULL;
    free(element);
    LIST->numberOfElements--;
}

void deleteLast()
{
    Node* element = LIST->last;
    if(element != NULL)
    {
        LIST->last = LIST->last->prev;
        LIST->last->next = NULL;
        free(element);
        LIST->numberOfElements--;
    }
}

void deleteAll()
{
    Node* element = LIST->first;
    while(element != NULL)
    {
        LIST->first = LIST->first->next;
        free(element);
        element = LIST->first;
    }
    LIST->numberOfElements = 0;
    LIST->first = LIST->last = NULL;
}

void deleteElement(int key) {
    Node *element = LIST->first;
    while (element != NULL) {
        if(element->data == key)
            break;
        else element = element->next;
    }

    if (element != NULL)
    {
        if(element == LIST->first)
        {
            deleteFirst();
        }else if(element == LIST->last)
        {
            deleteLast();
        }else
        {
            element->prev->next = element->next;
            element->next->prev = element->prev;
            free(element);
            LIST->numberOfElements--;
        }
    }
}

void printFirst(int x)
{
    Node* element = LIST->first;
    while(x != 0 && element != NULL)
    {
        fprintf(g, "%d ", element->data);
        element = element->next;
        x--;
    }
    fprintf(g, "\n");
}

void printLast(int x)
{
    int y = x;
    Node* element = LIST->last;
    while(x != 1 && element != NULL)
    {
        element = element->prev;
        x--;
    }

    while(y != 0 && element != NULL)
    {
        fprintf(g, "%d ", element->data);
        element = element->next;
        y--;
    }
    fprintf(g, "\n");
}

void printAll()
{
    Node* curr = LIST->first;
    while(curr != NULL)
    {
        fprintf(g, "%d ", curr->data);
        curr = curr->next;
    }
    fprintf(g, "\n");
}
