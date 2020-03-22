//
// Created by ileana on 3/21/2020.
//

#include "queue.h"
#include<stdbool.h>
#define MAX_LEN 150


bool isOperator(char * op);
void enqueueOperand(double op);
void enqueueOperator(char op);

void initialize() {
    first = last = NULL;
}
void enqueueOperand(double op)
{
    NodeL * newElement= (NodeL*)malloc(sizeof(NodeL));
    newElement->operand=op;
    newElement->type=1;
    newElement->next=NULL;
    if(last!=NULL)
        last->next=newElement;
    else
        first=newElement;
    last=newElement;
}
void enqueueOperator(char op)
{
    NodeL * newElement= (NodeL*)malloc(sizeof(NodeL));
    newElement->operator=op;
    newElement->next=NULL;
    newElement->type=0;
    if(last!=NULL)
        last->next=newElement;
    else
        first=newElement;
    last=newElement;
}
void dequeue()
{
    if(first!=NULL) {
        NodeL * element =first;
        first = first->next;
        if (first == NULL)
            last = NULL;
        free(element);
    }
}

void createQueue()
{
    initialize();
    char * line =(char *)malloc(MAX_LEN* sizeof(char));
    char *p;
    fgets(line,MAX_LEN,fin);
    for(p=strtok(line," ");p!=0;p=strtok(NULL," "))
    {
        if(!isOperator(p))
        {
            double operand = atof(p);
            enqueueOperand(operand);
            enqueueOperator('#');
            enqueueOperator('#');
        }
        else
            enqueueOperator(p[0]);
    }

}

bool isOperator(char * op)
{
    if(strcmp(op,"+")==0 || strcmp(op,"-")==0 ||strcmp(op,"*")==0 || strcmp(op,"/")==0)
        return true;
    return false;
}