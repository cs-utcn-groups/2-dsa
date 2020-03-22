//
// Created by ileana on 3/21/2020.
//


#include "list.h"


void addElement(NodeL ** first, char givenKey)
{
    NodeL * newElement = (NodeL*)malloc(sizeof(NodeL));
    newElement->key=givenKey;
    if(*first==NULL)
    {
        *first=newElement;
        (*first)->next=NULL;
        (*first)->previous=NULL;
    }
    else {
        NodeL *currentElement = *first;
        while (currentElement ->next!= NULL) {
            currentElement = currentElement->next;
        }
        currentElement->next=newElement;
        newElement->previous=currentElement;
        newElement->next=NULL;
    }

}

void traverseList(NodeL * first)
{
    if(first!=NULL) {
        printf("The list is:\n");
        NodeL *element = first;
        while (element != NULL) {
            printf("%c ", element->key);
            element=element-> next;
        }
        printf("\n");
    }
}
