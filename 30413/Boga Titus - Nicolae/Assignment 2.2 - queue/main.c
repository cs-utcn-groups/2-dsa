#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SECONDS{
    int data;
    struct _SECONDS *next;
}SECONDS;

typedef struct _CUSTOMERS{
    int rubles,seconds;
    struct _CUSTOMERS *next;

}CUSTOMERS;



SECONDS *FirstS=NULL,*LastS=NULL;
CUSTOMERS *FirstC=NULL,*LastC=NULL;

void AddToSeconds(int Value)
{
    if(FirstS == NULL)
    {
        FirstS=(SECONDS*)malloc(sizeof(SECONDS));
        FirstS->data=Value;
        FirstS->next=NULL;
        LastS=FirstS;
    } else
    {
        SECONDS *Node=(SECONDS*)malloc(sizeof(SECONDS));
        Node->next=NULL;
        Node->data=Value;
        LastS->next=Node;
        LastS=Node;
    }
}

void AddCustomers(int rubles, int seconds)
{
    if(FirstC == NULL)
    {
        FirstC=malloc(sizeof(CUSTOMERS));
        FirstC->next=NULL;
        FirstC->rubles=rubles;
        FirstC->seconds=seconds;
        LastC=FirstC;

    } else
    {
        CUSTOMERS *NewNode=(CUSTOMERS*)malloc(sizeof(CUSTOMERS));
        NewNode->seconds=seconds;
        NewNode->rubles=rubles;
        NewNode->next=NULL;
        LastC->next=NewNode;
        LastC=NewNode;
    }

}


int Calculate(int x)
{
    static seconds=0,rubles=0;
    while(FirstC && FirstC->seconds+seconds<x)
    {

        seconds+=FirstC->seconds;
        rubles+=FirstC->rubles;
        CUSTOMERS *node=FirstC;
        FirstC=FirstC->next;
        free(node);
    }
    return rubles;

}

int main() {
    FILE *f=fopen("input.dat","r");
    FILE *g=fopen("output.dat","w");
    char *s=(char*)malloc(sizeof(char)*256);
    fgets(s,256,f);
    char *p=strtok(s," \n");
    AddToSeconds(atoi(p));
    while(p=strtok(NULL, " \n"))
    {
        AddToSeconds(atoi(p));
    }
    while(fgets(s,256,f) != NULL)
    {
        p=strtok(s," \n");
        p=strtok(NULL," \n");
        int rubles=atoi(p);
        p=strtok(NULL," \n");
        AddCustomers(rubles,atoi(p));

    }
    SECONDS *S;
    while(FirstS)
    {
        fprintf(g,"After %d seconds:%d\n",FirstS->data,Calculate(FirstS->data));
        S=FirstS;
        FirstS=FirstS->next;
        free(S);

    }

    return 0;
}
