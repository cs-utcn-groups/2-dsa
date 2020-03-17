#include "queue.h"

void initializeList()
{
    firstT = NULL;
    lastT = NULL;
    firstC = NULL;
    lastC = NULL;
}

void readLists()
{
    FILE *f=fopen("input.dat","r");
    char *strbuf=(char*)malloc(sizeof(char)*100);
    char *p=(char*)malloc(sizeof(char)*100);
    while(fgets(strbuf,100,f) != NULL)
    {
        if(firstT == NULL)
        {
            addElementT(p,strbuf);
        }
        else
        {
            addElementC(p,strbuf);
        }
    }
    fclose(f);
}

void addElementT(char *p,char *strbuf)
{
    int x;
    p=strtok(strbuf," ");
    x=atoi(p);
    while (p!=NULL)
    {
        if(firstT==NULL)
        {
            firstT=(NodeT*)malloc(sizeof(NodeT));
            firstT->data=x;
            firstT->next=lastT;
            firstT->previous=NULL;
            lastT=firstT;
        }
        else
        {

            NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
            lastT->next = newE1;
            newE1->next = NULL;
            newE1->data = x;
            newE1->previous = lastT;
            lastT = newE1;
        }
        p=strtok(NULL," ");
        x=atoi(p);
    }
}

void addElementC(char *p,char *strbuf)
{
    int x;
    if(firstC==NULL)
    {
        firstC=(NodeC*)malloc(sizeof(NodeC));
        firstC->name=(char*)malloc(sizeof(char)*100);
        p=strtok(strbuf," ");
        strcpy(firstC->name,p);
        p=strtok(NULL," ");
        x=atoi(p);
        firstC->money=x;
        p=strtok(NULL," ");
        x=atoi(p);
        firstC->time=x;
        firstC->previous=NULL;
        lastC=firstC;
    }
    else
    {
        NodeC *newEl=(NodeC*)malloc(sizeof(NodeC));
        newEl->name=(char*)malloc(sizeof(char)*100);
        lastC->next=newEl;
        newEl->next=NULL;
        p=strtok(strbuf," ");
        strcpy(newEl->name,p);
        p=strtok(NULL," ");
        x=atoi(p);
        newEl->money=x;
        p=strtok(NULL," ");
        x=atoi(p);
        newEl->time=x;
        newEl->previous=lastC;
        lastC=newEl;
    }
}

void printSums()
{
    FILE *g=fopen("output.dat","w");
    NodeT *currentT=firstT;
    int t,sum;
    while(currentT != NULL)
    {
        sum=0;
        fprintf(g,"After %d seconds: ",currentT->data);
        NodeC *currentC=firstC;
        t=0;
        while(t < currentT->data && currentC != NULL)
        {
            sum=sum+currentC->money;
            t=t+currentC->time;
            currentC=currentC->next;
        }
        if(t > currentT->data )
        {
            sum=sum-currentC->previous->money;
        }
        fprintf(g,"%d\n",sum);
        currentT=currentT->next;
    }
    fclose(g);
}
