#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int money,time;
    struct node * next;
    struct node * prev;
} ClienT;
typedef struct time
{
    int times;
    struct time * next;
    struct time * prev;
}TimeT;
TimeT Sentin, *sentin=&Sentin;
ClienT Sentinel,*sentinel=&Sentinel;
void initializeSentinel()
{
    sentinel->next=sentinel;
    sentinel->prev=sentinel;
}
void initializeSentin()
{
    sentin->next=sentin;
    sentin->prev=sentin;
}
void ALTime(int time)
{
    TimeT * newElem=(TimeT*)malloc(sizeof(TimeT));

    newElem->times=time;
    if(sentin->next==sentin)
    {
        newElem->next=sentin;
        newElem->prev=sentin;
        sentin->next=newElem;
        sentin->prev=newElem;
    }
    else{
        newElem->prev=sentin->prev;
        sentin->prev->next=newElem;
        sentin->prev=newElem;
        newElem->next=sentin;
    }
}
void ALClient(int money,int time)
{
    ClienT * newElem=(ClienT*)malloc(sizeof(ClienT));
    newElem->money=money;
    newElem->time=time;
    if(sentinel->next==sentinel)
    {
        newElem->next=sentinel;
        newElem->prev=sentinel;
        sentinel->next=newElem;
        sentinel->prev=newElem;
    }
    else{
        newElem->prev=sentinel->prev;
        sentinel->prev->next=newElem;
        sentinel->prev=newElem;
        newElem->next=sentinel;
    }
}
void DFClient()
{
    ClienT * oldNode=(ClienT*)malloc(sizeof(ClienT));
    oldNode=sentinel->next->next;
    free(sentinel->next);
    sentinel->next=oldNode;
    oldNode->prev=sentinel;
}
void DFTime()
{
    TimeT * oldNode=(TimeT*)malloc(sizeof(TimeT));
    oldNode=sentin->next->next;
    free(sentin->next);
    sentin->next=oldNode;
    oldNode->prev=sentin;
}
void readClients(FILE *f,FILE *g)
{
    char *strbuff=(char*)malloc(sizeof(char)*80);
    char *strbuf=(char*)malloc(sizeof(char)*80);
    char *name=(char*)malloc(sizeof(char)*20);
    int time,money;
    fgets(strbuff,80,f);
    char *p;
    p=strtok(strbuff," ");
    while(p!= NULL)
    {
        strcpy(name,p);
        time=atoi(name);
        ALTime(time);
        p=strtok(NULL," ");
    }
    while(fgets(strbuf,40,f))
    {
        sscanf(strbuf,"%s %d %d",name,&money,&time);
        ALClient(money,time);
    }
    int totalTime=0,timeDisplay=0,totMoney=0;
    while(sentin->next!=sentin)
    {
        timeDisplay=sentin->next->times;
        while((totalTime+sentinel->next->time) <= timeDisplay && sentinel->next != sentinel)
        {
            totalTime+=sentinel->next->time;
            totMoney+=sentinel->next->money;
            DFClient();

        }
        fprintf(g,"Afetr %d seconds: %d\n",timeDisplay,totMoney);

        DFTime();
    }
}

int main()
{
    FILE *i=fopen("input.dat.txt","rw+");
    FILE *o=fopen("output.dat.txt","rw+");
    initializeSentin();
    initializeSentinel();
    readClients(i,o);
    return 0;
}
