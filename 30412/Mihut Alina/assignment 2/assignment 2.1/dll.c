//
// Created by Alina Mihut on 3/7/20.
//
#include "dll.h"

void initializeList()
    {
        first=(NodeT*) malloc (sizeof(NodeT));
        last=(NodeT*) malloc (sizeof(NodeT));
        first = NULL;
        last = NULL;
    }
void addFirst(int data) {
    NodeT *newElement=(NodeT*) malloc (sizeof(NodeT));
    newElement->data=data;
    if ( first == NULL ) {
        first = newElement;
        first->next= NULL;
        first->prev=NULL;
        last = first;
    }
    else {
        first->prev=newElement;
        newElement->next = first;
        newElement->prev = NULL;
        first=newElement;
    }

}
void addLast (int data) {
    NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));
    newElement->data=data;
    if ( first == NULL ) {
        first = newElement;
        first->next= NULL;
        first->prev=NULL;
        last = first;
    }
    else if (last != NULL) {
        newElement->next = NULL;
        newElement->prev=last;
        last->next = newElement;
        last = newElement;
    }
}

void deleteFirst() {
    NodeT *element;
    if (first != NULL){
        element=first;
        first=first->next;
        free(element);
        if (first == NULL)
            last = NULL;
        else first->prev=NULL;}
}
void deleteLast() {
    NodeT *currentElement;
    currentElement = first;
    if (currentElement != NULL)
        while (currentElement != last) {
            currentElement = currentElement->next;
        }
    if (currentElement == first)
        first = last = NULL;
    else {
        last->prev->next = NULL;
        last = last->prev;

    }
}
void doomTheList (){
    NodeT *currentElement;
    while (first !=NULL){
        currentElement=first;
        first=first->next;
        free(currentElement);
    }
    last=NULL;
}
void deleteElement (int data) {
    NodeT *currentElement= first;

    while (currentElement != NULL) {
        if (currentElement->data == data) {
            if (first == currentElement && last == currentElement)
            {
                first=NULL;
                last=NULL;
                free(currentElement);
            }
            else
                if (currentElement == first)
                { first = first->next;
                    if (first == NULL)
                        last = NULL;
                    else first->prev=NULL;
                free(currentElement);}
                else
                    if (currentElement == last)
                {
                    last=last->prev;
                    last->next=NULL;
                    free(currentElement);
                }
                else {
                currentElement=currentElement->prev;
                free(currentElement);
            }
        } else {
            currentElement = currentElement->next;
        }
    }
}

void printAllElements (FILE *fout)
{
    NodeT *currentElement=first;
    while (currentElement!=NULL)
    {
        fprintf (fout, " %d ", currentElement->data);
        currentElement=currentElement->next;
    }
    fprintf(fout, " \n ");

}

void printFirst (int x, FILE *fout){
    NodeT *currentElement=first;
    int i=0;
    while (i<x || currentElement!=NULL)
    {
        fprintf (fout, " %d ", currentElement->data);
        currentElement=currentElement->next;
        i++;
    }
    fprintf(fout, "\n");
}


void printLast (int x, FILE *fout){
    NodeT *p;
    int noOfElements=0;
    for ( p = first; p != NULL; p = p->next )
        noOfElements++;
    int k=noOfElements-x;
    int count=0;
    if (k<=0) printAllElements(fout);
    else for ( p = first; p != NULL; p = p->next )
    {
        count++;
        if (count>=x)   fprintf (fout, " %d ", p->data);
    }
    fprintf (fout, "\n");
    }






