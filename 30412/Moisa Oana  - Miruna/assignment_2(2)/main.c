#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LINE 100
#define DATA_PATH_IN "../input.dat"
#define DATA_PATH_OUT "../output.dat"
typedef struct node{
    int data;
    struct node *next;
}NodeT;
typedef  struct list{
    NodeT *first;
    NodeT *last;
}ListT;
void addLast(ListT *x, int data);
void readData(char*line,int *time, char *names,ListT *x,ListT*y, int *NrOfTimePeriods);
void findSum(ListT *x, ListT *y, int nrOfTimePeriods,int *time);
void freeMemory(char *line, int *time, char *names);
FILE *in,*out;
int main() {
    ListT M,T;
    in=fopen(DATA_PATH_IN,"r");
    out=fopen(DATA_PATH_OUT,"w");
    int *time,nrOfTimePeriods=0;
    char *names,*line;
    line=(char*)malloc(MAX_LINE*sizeof(char*));
    time=(int*)malloc(MAX_LINE*sizeof(char*));
    names=(char*)malloc(MAX_LINE*sizeof(char*));
    readData(line,time,names,&M,&T,&nrOfTimePeriods);
    findSum(&M,&T,nrOfTimePeriods,time);
    freeMemory(line,time,names);
    fclose(in);
    fclose(out);
    return 0;
}
void addLast(ListT *x, int data)
{
    if(x->first==NULL)
    {
        x->first=(NodeT*)malloc(sizeof(NodeT));
        x->first->data=data;
        x->first->next=x->last;
        x->last=x->first;
    }
    else
    {
        NodeT *newNode;
        newNode=(NodeT*)malloc(sizeof(NodeT));
        x->last->next=newNode;
        newNode->next=NULL;
        newNode->data=data;
        x->last=newNode;
    }
}
void readData(char*line,int *time, char *names,ListT *x,ListT*y,int *nrOfTimePeriods)
{

    fgets(line,MAX_LINE,in);
    char *p;
    for(p=strtok(line," ");p!=0;p=strtok(NULL," "))
    {
        time[*nrOfTimePeriods]=atof(p);
        (*nrOfTimePeriods)++;
    }
    x->first=x->last=y->first=y->last=NULL;
    while(fgets(line,MAX_LINE,in)>0) {
        char *r;
        int k=0,count=0;

        for(r=strtok(line," ");r!=0;r=strtok(NULL," "))
        {
            if(k==0)
            {
                strcpy(&names[count],r);
                count++;
                k++;
            }else if(k==1)
            {
                addLast(x,atoi(r));
                k++;
            }else if(k==2)
            {
                addLast(y,atoi(r));
            }
        }
    }
}
void findSum(ListT *x, ListT *y, int nrOfTimePeriods,int *time)
{
    NodeT *currentNodeMoney, *currentNodeTime;
    currentNodeMoney=x->first;
    currentNodeTime=y->first;
    int timeCount=0,sumTime=y->first->data,sumCashier=0,ok=0;
    while(timeCount!=nrOfTimePeriods)
    {
        if(time[timeCount]==sumTime)
        {
            sumCashier+=currentNodeMoney->data;
            fprintf(out,"After %d seconds: %d.\n",time[timeCount],sumCashier);
            timeCount++;
            currentNodeTime=currentNodeTime->next;
            currentNodeMoney=currentNodeMoney->next;
            sumTime+=currentNodeTime->data;

        }else if(time[timeCount]>sumTime)
        {
            if(ok!=1)
                sumCashier+=currentNodeMoney->data;
            if(currentNodeTime==y->last)
            {
                ok=1;
                sumTime+=currentNodeTime->data;
                fprintf(out,"After %d seconds: %d.\n",time[timeCount],sumCashier);
                timeCount++;
            }
            else {

                currentNodeTime = currentNodeTime->next;
                currentNodeMoney = currentNodeMoney->next;
                sumTime += currentNodeTime->data;
            }

        }else if(time[timeCount]<sumTime)
        {
            fprintf(out,"After %d seconds: %d.\n",time[timeCount],sumCashier);
            timeCount++;
        }
    }
}
void freeMemory(char *line, int *time, char *names)
{
    free(line);
    free(time);
    free(names);
}