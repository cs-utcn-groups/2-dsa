#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>

char *function;
char *element;
FILE *f;
FILE *o;
int arg;

void init()
{
    function=(char*)malloc(sizeof(char)*100);
    element=(char*)malloc(sizeof(char)*100);
    f=fopen("input.dat","r");
    o=fopen("output.txt","a");
}

int readnr(FILE *f)
{
    fscanf(f,"%s",element);
    char *p;
    return strtol(element,&p,10);
}

int main()
{
    init();
    initializeSll();
    while(fscanf(f,"%s",function)!=EOF)
    {
        if(strcmp(function,"AF")==0)
        {
            arg=readnr(f);
            AF(arg);
        }
        if(strcmp(function,"AL")==0)
        {
            arg=readnr(f);
            AL(arg);
        }
        if(strcmp(function,"DF")==0)
        {
            DF();
        }
        if(strcmp(function,"DL")==0)
        {
            DL();
        }
        if(strcmp(function,"DE")==0)
        {
            arg=readnr(f);
            DE(arg);
        }
        if(strcmp(function,"print_All")==0)
        {
            print_All(o);
        }
        if(strcmp(function,"PRINT_F")==0)
        {
            arg=readnr(f);
            PRINT_F(arg,o);
        }
        if(strcmp(function,"PRINT_L")==0)
        {
            arg=readnr(f);
            PRINT_L(arg,o);
        }
        if(strcmp(function,"DOOM_THE_LIST")==0)
        {
            DOOM_THE_LIST();
        }
    }




    return 0;
}
