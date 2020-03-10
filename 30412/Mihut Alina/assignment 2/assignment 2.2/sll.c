//
// Created by Alina Mihut on 3/8/20.
//
#include "sll.h"
void initializeList()
{
    first=(NodeT*) malloc (sizeof(NodeT));
    last=(NodeT*) malloc (sizeof(NodeT));
    first = NULL;
    last = NULL;
}

void AddLastCostumer (int rubles, int seconds){
    NodeT *newCostumer = (NodeT *) malloc(sizeof(NodeT));
    if (first == NULL){
        first=(NodeT*) malloc (sizeof(NodeT));
       first->rubles=rubles;
        first->seconds=seconds;
        first->next=NULL;
        last=first;
    }
    else if (last != NULL) {
        newCostumer->next = NULL;
        last->next = newCostumer;
        newCostumer->rubles=rubles;
        newCostumer->seconds=seconds;
        last = newCostumer;
    }
}

void deleteFirstCostumer()
{
        NodeT *costumer;
        if (first != NULL){
            costumer=first;
            first=first->next;
            free(costumer);
            if (first == NULL) last = NULL;}
    }
void printAllElements (FILE *fout)
{
    NodeT *currentElement=first;
    while (currentElement!=NULL)
    {
        fprintf (fout, " %d %d", currentElement->rubles, currentElement->seconds);
        currentElement=currentElement->next;
    }
    fprintf(fout, " \n ");

}