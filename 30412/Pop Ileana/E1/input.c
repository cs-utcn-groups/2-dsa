//
// Created by ileana on 3/1/2020.
//

#include "input.h"
#include<string.h>
#define MAX_LEN 150


int returnCapacity(char s[]);

void readSentinels(int * n,int * total,FILE * fptr)
{
    int data;
    *total=0;
    fscanf(fptr,"%d",n);
    for(int i=0;i<*n;i++)
    {
        fscanf(fptr,"%d",&data);
        *total=*total + data;
        addElement(data);
    }
}

void readCountries(int  n, FILE * fptr)
{
    char line[MAX_LEN]="";
    for(int i=0;i<n;i++)
    {
        fgets(line,MAX_LEN,fptr);
        if(i!=7)
            line[strlen(line)-1]='\0';
        char *p;
        p=strtok(line, " ");
        addElementCountry(p);
        firstNodes[i]=lastNodes[i]=NULL;
        for(p=strtok(NULL," ");p != 0;p=strtok(NULL," "))
        {
            int cap=returnCapacity(p);
            addWaves(cap,i);
        }
    }
}

int returnCapacity(char s[])
{
    int i=0,cap=0;
    while(s[i]!='\0')
    {
        cap=cap*10+(s[i]-'0');
        i++;
    }
    return cap;
}