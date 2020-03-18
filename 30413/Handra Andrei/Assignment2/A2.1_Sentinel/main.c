#include "head.h"
#include<string.h>


void instructions(char *,int, FILE *);
int main()
{
    FILE *g,*f;
    f=fopen("input.txt","r");
    g=fopen("output.txt","a");
    Initialize_Dll();
    char *strbuf=(char *)malloc(sizeof(char)*256);
    while(fgets(strbuf,100,f))
    {
        char *p;
        int data;
        p=strtok(strbuf," \n");
        char *instr=(char *)malloc(sizeof(char)*256);
        strcpy(instr,p);
        p=strtok(NULL,"\n");
        if(p)
        {
          data=atoi(p);
        }

        instructions(instr,data,g);

    }

    return 0;
}
void instructions(char *p,int n,FILE *g)
{
     if(strcmp(p,"AF")==0)
    {
        Add_first(n);
    }
    if(strcmp(p,"AL")==0)
    {
        Add_last(n);
    }
    if(strcmp(p,"DF")==0)
    {
        Delete_first();
    }
    if(strcmp(p,"DL")==0)
    {
        Delete_last();
    }
    if(strcmp(p,"DOOM_THE_LIST")==0)
    {
        Delete_all();
    }
    if(strcmp(p,"DE")==0)
    {
        Delete_el(n);
    }
    if(strcmp(p,"PRINT_ALL")==0)
    {
        Print_all(g);
    }
    if(strcmp(p,"PRINT_F")==0)
    {
        Print_f(n,g);
    }
    if(strcmp(p,"PRINT_L")==0)
    {
        Print_l(n,g);
    }
}
