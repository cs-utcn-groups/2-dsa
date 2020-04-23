//
// Created by ileana on 4/14/2020.
//

#include "list.h"
#include <stdlib.h>

void makeEmpty()
{
    coverSet=NULL;
}

void addNewNode(int content)
{
    NodeT * newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode ->content=content;
    newNode->next=NULL;
    if(coverSet==NULL)
        coverSet=newNode;
    else
    {
        NodeT * last = coverSet;
        while(last->next!=NULL)
            last=last->next;
        last->next = newNode;
    }
}