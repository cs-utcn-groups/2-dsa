#include "head.h"
#include<string.h>


void instructions(char *,int, FILE *);
int main()
{
    FILE *g,*f;
    f=fopen("input.txt","r");
    g=fopen("output.txt","a");
    InitializeSLL();
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
        add_first(n);
    }
    if(strcmp(p,"AL")==0)
    {
        add_last(n);
    }
    if(strcmp(p,"DF")==0)
    {
        Delete_first();
    }
    if(strcmp(p,"DL")==0)
    {
        Delete_Last();
    }
    if(strcmp(p,"DOOM_THE_LIST")==0)
    {
        doom_list();
    }
    if(strcmp(p,"DE")==0)
    {
        DE(n);
    }
    if(strcmp(p,"PRINT_ALL")==0)
    {
        print_all(g);
    }
    if(strcmp(p,"PRINT_F")==0)
    {
        print_f(n,g);
    }
    if(strcmp(p,"PRINT_L")==0)
    {
        print_l(n,g);
    }
}
