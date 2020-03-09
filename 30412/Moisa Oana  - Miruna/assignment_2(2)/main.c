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
ListT M,T;
int main() {
    FILE *in,*out;
    in=fopen(DATA_PATH_IN,"r");
    out=fopen(DATA_PATH_OUT,"w");
    int time[100];
    char names[100];
    char *line;
    line=(char*)malloc(MAX_LINE*sizeof(char*));
    fgets(line,MAX_LINE,in);
    char *p;
    int nrOfTimePeriods=0;
    for(p=strtok(line," ");p!=0;p=strtok(NULL," "))
    {
        time[nrOfTimePeriods]=atof(p);
        nrOfTimePeriods++;
    }

    M.first=M.last=T.first=T.last=NULL;
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
                if(M.first==NULL)
                {
                    M.first=(NodeT*)malloc(sizeof(NodeT));
                    M.first->data=atoi(r);
                    M.first->next=M.last;
                    M.last=M.first;
                }
                else
                {
                    NodeT *newNode;
                    newNode=(NodeT*)malloc(sizeof(NodeT));
                    M.last->next=newNode;
                    newNode->next=NULL;
                    newNode->data=atoi(r);
                    M.last=newNode;
                }
                k++;
            }else if(k==2)
            {
                if(T.first==NULL)
                {
                    T.first=(NodeT*)malloc(sizeof(NodeT));
                    T.first->data=atoi(r);
                    T.first->next=T.last;
                    T.last=T.first;
                }
                else
                {
                    NodeT *newNode;
                    newNode=(NodeT*)malloc(sizeof(NodeT));
                    T.last->next=newNode;
                    newNode->next=NULL;
                    newNode->data=atoi(r);
                    T.last=newNode;
                }
            }
        }
    }
    int sumCashier=0,sumTime=T.first->data;
    NodeT *currentNodeTime, *currentNodeMoney;
    currentNodeMoney=M.first;
    currentNodeTime=T.first;
    int timeCount=0,ok=0;
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
            if(currentNodeTime==T.last)
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
    return 0;
}
