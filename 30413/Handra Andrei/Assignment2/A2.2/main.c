#include "head.h"
#include<string.h>

int main()
{
    FILE *f,*g;
    f=fopen("input.txt","r");
    g=fopen("output.txt","w");
    char *strbuf=(char*)malloc(sizeof(char)*200);
    fgets(strbuf,200,f);
    char *str=(char*)malloc(sizeof(char)*100);
    str=strtok(strbuf," \n");
    Add_Time(atoi(str));
    while((str=strtok(NULL," \n")))
    {
        Add_Time(atoi(str));
    }
    while(fgets(strbuf,200,f)!=NULL)
    {
        int rubles,sec;
        str=strtok(strbuf," \n");
        str=strtok(NULL," \n");
        rubles=atoi(str);
        str=strtok(NULL," \n");
        sec=atoi(str);
        Add_Customer(rubles,sec);
    }
    while(first_t!=NULL)
    {
        int nr_rubles;
        nr_rubles=Nr_of_Rubles(first_t->sec);
        fprintf(g,"After %d seconds: %d \n",first_t->sec,nr_rubles);
        first_t=first_t->next;
    }
    return 0;
}

