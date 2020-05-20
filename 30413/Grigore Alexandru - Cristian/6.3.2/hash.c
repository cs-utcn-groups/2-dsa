#include "hash.h"

void initialize()
{
    for(int i=0;i<B;i++)
    {
        Table[i].flag=0;
        Table[i].data=NULL;
    }
}

int f(char *data)
{
    int sum=0;
    for(int i=0;i<strlen(data);i++)
    {
        sum+=data[i];
    }
    return (sum%B);
}

void insertT(char *name)
{
    int p=f(name);
    int i=p;
    NodeT *elem=(NodeT*)malloc(sizeof(NodeT));
    strcpy(elem->name,name);
    while(Table[i].flag==1)
    {
        if(strcmp(Table[i].data->name,name)==0)
        {
            printf("\nItem exists\n");
            strcpy(Table[i].data->name,name);
            return;
        }
        i=(i+1)%B;
        if(i==p)
        {
            printf("\nTable is full.\n");
            return;
        }
    }
    Table[i].flag=1;
    Table[i].data=elem;
}

void deleteT(char *name)
{
    int p=f(name);
    int i=p;
    while(Table[i].flag!=0)
    {
        if(Table[i].flag==1 && strcmp(Table[i].data->name,name)==0)
        {
            Table[i].flag=2;
            Table[i].data=NULL;
            printf("\n Data removed.\n");
            return;
        }
        i=(i+1)%B;
        if(i==p)
        {
            break;
        }
    }
    printf("\nNo data.\n");
}


void listData()
{
    for(int i=0;i<B;i++)
    {
        NodeT *current=(NodeT*)Table[i].data;
        if(current==NULL)
        {
            printf("table %d has no elements.",i);
        }
        else
        {
            printf("\nTable[%d] elements: %s\n",i,current->name);
        }
    }
}

void findT(char *name)
{
    int p=f(name);
    int i=p;
    if(Table[i].flag==1 && strcmp(Table[i].data->name,name)==0)
    {
        printf("\nYES\n");
    }
    else
    {
        printf("\nNO\n");
    }
}
