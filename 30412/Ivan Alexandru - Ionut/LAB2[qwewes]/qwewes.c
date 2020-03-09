//
// Created by Ivan on 3/7/2020.
//
#include <stdlib.h>
#include <string.h>
#include "qwewes.h"

listPtr* instantiateQwewe()
{
    listPtr *l = (listPtr*)malloc(sizeof(listPtr));
    if(l)
    {
        l->last = NULL;
        l->first = NULL;
        l->noOfElements = 0;
    }
    return l;
}

Node* instantiateNode(char* name, int roubles, int time)
{
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->name = (char*)malloc(sizeof(char)*MAX_NAME);
    strcpy(newElement->name, name);
    newElement->roubles = roubles;
    newElement->time = time;
    return newElement;
}

void addNode(Node* t)
{
    if(qwewe->first == NULL)
    {
        qwewe->first = (Node*)malloc(sizeof(Node));
        qwewe->first = t;
        qwewe->first->next = NULL;
    }else if(qwewe->last == NULL)
    {
        qwewe->last = (Node*)malloc(sizeof(Node));
        qwewe->last = t;
        qwewe->last->next = NULL;
        qwewe->first->next = qwewe->last;
    }else
    {
        qwewe->last->next = t;
        qwewe->last = t;
        qwewe->last->next = NULL;
    }
}

void printAll()
{
    Node* el = qwewe->first;
    while(el != NULL)
    {
        printf("%s \n", el->name);
        el = el->next;
    }
}

int computeTime(int TIME)
{
    int sum = 0;
    Node* el = qwewe->first;
    while(TIME > 0 && el != NULL)
    {
        TIME -= el->time;
        if(TIME >= 0) sum += el->roubles;
        el = el->next;
    }

    return sum;
}