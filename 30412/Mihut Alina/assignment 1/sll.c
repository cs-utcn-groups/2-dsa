//
// Created by Alina Mihut on 3/1/20.
//
#include "sll.h"
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
        last = first;
    }
    else
        newElement->next=first;
    first=newElement;
}
void addLast (int data) {
    NodeT *newElement = (NodeT *) malloc(sizeof(NodeT));

    if (first == NULL){
        first->data=data;
        first->next=NULL;
        last=first;
    }
    else if (last != NULL) {
        newElement->next = NULL;
        last->next = newElement;
        newElement->data = data;
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
            last = NULL;}
}
void deleteLast(){
    NodeT *currentNode , *previousNode ;
    previousNode = NULL;
    currentNode=first;
    if ( currentNode != NULL )
        while ( currentNode!= last )
        {   previousNode = currentNode;
            currentNode = currentNode->next; }
    if ( currentNode == first )
        first = last = NULL;
    else
    { previousNode->next = NULL;
        last=previousNode; }

}

void doomTheList (){
    NodeT *currentNode;
    while (first !=NULL){
        currentNode=first;
        first=first->next;
        free(currentNode);
    }
    last=NULL;
}

void deleteElement (int data) {
    NodeT *currentElement = first;
    NodeT *previousElement = NULL;

    while (currentElement != NULL) {
        if (currentElement->data == data) {
            if (currentElement == first)
                first = first->next;
            else if (currentElement == last) {
                last = previousElement;
                last->next = NULL;
            } else {
                previousElement->next = currentElement->next;
            }
            previousElement = currentElement;
            currentElement = currentElement->next;
            free(previousElement);
            previousElement = currentElement;
        } else {
            previousElement = currentElement;
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
    NodeT *currentElement=first;
    int noOfElements=0;
    while (currentElement!=NULL)
    {
        noOfElements++;
        currentElement=currentElement->next;

    }
    int k=noOfElements-x;
    if (k<=0) printAllElements(fout);
    else
    {   int i=0;
        currentElement=first;
        while(currentElement!=NULL)
        {
            if(i>=k) fprintf (fout, " %d ", currentElement->data);
            currentElement=currentElement->next;
            i++;
        }
        fprintf (fout, "\n");
    }



}