#include "extra.h"

int main()
{
    FILE *f=fopen("input.dat","r");
    FILE *g=fopen("output.dat","w");
    initializeSll();
    int cts=0;
    readSentinels(f,&cts);
    int i,m,cta=0,strongest=0,weakest=32000;
    char *strong=(char*)malloc(sizeof(char)*100);
    char *weak=(char*)malloc(sizeof(char)*100);
    char *p=(char*)malloc(sizeof(char)*100);
    char *aux=(char*)malloc(sizeof(char)*100);
    fscanf(f,"%d",&m);

    for(i=0; i<=m; i++)
    {
        fgets(p,100,f);
        aux=strtok(p," ");
        if(firstC == NULL)
        {
            firstC = (Country*)malloc(sizeof(Country));
            firstC->name=(char*)malloc(sizeof(char)*100);
            firstC->next = lastC;
            strcpy(firstC->name,aux);
            lastC = firstC;
        }
        else
        {
            Country * newE1 = (Country*)malloc(sizeof(Country));
            newE1->name=(char*)malloc(sizeof(char)*100);
            lastC->next = newE1;
            newE1->next = NULL;
            strcpy(newE1->name,aux);
            lastC = newE1;
        }
        lastC->Fattack = (NodeT*)malloc(sizeof(NodeT));
        lastC->Lattack = (NodeT*)malloc(sizeof(NodeT));
        lastC->Fattack=NULL;
        lastC->Lattack=NULL;
        int s=0;
        aux=strtok(NULL," ");
        while(aux!=NULL)
        {
            lastC->Fattack = (NodeT*)malloc(sizeof(NodeT));
            lastC->Lattack = (NodeT*)malloc(sizeof(NodeT));
            int x=atoi(aux);
            s=s+x;
            cta=cta+x;
            if(lastC->Fattack == NULL)
            {
                lastC->Fattack->next = lastC->Lattack;
                lastC->Fattack->data = x;
                lastC->Fattack = lastC->Lattack;
            }
            else
            {
                NodeT * newE1 = (NodeT*)malloc(sizeof(NodeT));
                lastC->Lattack->next = newE1;
                newE1->next = NULL;
                newE1->data = x;
                lastC->Lattack = newE1;
            }
            aux=strtok(NULL," ");
        }
        if(s>strongest)
        {
            strongest=s;
            strcpy(strong,lastC->name);
        }
        if(s<weakest)
        {
            weakest=s;
            strcpy(weak,lastC->name);
        }
    }
    if(cta>cts)
    {
         fputs("The tyrant was killed!\n",g);
    }
    else
    {
        fputs("The tyrant survived!\n",g);
    }
    fprintf(g,"The strongest county was: %s\n",strong);
    fprintf(g,"The weakest county was: %s\n",weak); //aici nu afiseaza nimic dupa :
    return 0;
}
