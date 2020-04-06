//
// Created by ileana on 4/6/2020.
//

#include "list.h"

void addElementList( int content)
{
    if(auxiliaryList==NULL)
        auxiliaryList=createNode(content);
    else
    {
        NodeT * newElement = createNode(content);
        NodeT *aux =auxiliaryList;
        while(aux->next!=NULL)
            aux=aux->next;
        aux->next=newElement;
    }
}

void deleteLast()
{
    if(auxiliaryList!=NULL)
    {
        NodeT * last = auxiliaryList;
        NodeT * prevLast = auxiliaryList;
        while(last->next!=NULL) {
            prevLast = last;
            last = last->next;
        }
        if(prevLast==auxiliaryList)
            auxiliaryList=NULL;
        else
            prevLast->next=NULL;
        free(last);
    }

}
