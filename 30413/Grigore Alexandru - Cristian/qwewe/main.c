#include "head.h"

int main()
{
    FILE *f=fopen("input.dat","r");
    FILE *o=fopen("output.dat","w");
    initializeQwewe();
    char *str=(char*)malloc(sizeof(char)*100);
    fgets(str,100,f);
    char *strbuf=strtok(str," \n");
    AddSeconds(atoi(strbuf));
    while((strbuf=strtok(NULL," \n")))
    {
        AddSeconds(atoi(strbuf));
    }
    while(fgets(str,100,f)!=NULL)
    {
        strbuf=strtok(str," \n");
        strbuf=strtok(NULL," \n");
        int rubles=atoi(strbuf);
        strbuf=strtok(NULL," \n");
        AddCustomers(rubles,atoi(strbuf));
    }
    SecondsT *time;
    while(firstS!=NULL)
    {
        fprintf(o,"After %d seconds: %d\n",firstS->data,compute(firstS->data));
        time=firstS;
        firstS=firstS->next;
        free(time);
    }
    return 0;
}
