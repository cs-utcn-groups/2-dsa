//
// Created by ileana on 3/7/2020.
//

#include "header.h"
#include <string.h>

#define MAX_LEN 150
int convertString(char * str);
int getNoOfTimePeriods(char * str);

void readTimePeriods(int ** array, int *n, FILE * fptr)
{
    *n=0;
    char * line,* copy;
    line = (char *)malloc(MAX_LEN* sizeof(char));
    copy = (char *)malloc(MAX_LEN* sizeof(char));
    fgets(line,MAX_LEN,fptr);

    strcpy(copy,line);
    *n=getNoOfTimePeriods(copy);
    *array = (int*)malloc((*n)* sizeof(int));
    char * p;
    int i=0;
    for(p=strtok(line," \n");p!=0;p=strtok(NULL," \n"))
    {
        (*array)[i]=convertString(p);
        i++;
    }
    free(line);
    free(copy);
}

void readCustomers(FILE * fptr)
{
    char * name=(char*)malloc(MAX_LEN* sizeof(char));
    int rubles,seconds;
    while(!feof(fptr))
    {
        fscanf(fptr,"%s",name);
        fscanf(fptr,"%d %d",&rubles,&seconds);
        addLast(rubles,seconds);
    }
}

int convertString(char * str)
{
    int n=0,i=0;
    while(str[i]!='\0')
    {
        n=n*10+(str[i]-'0');
            i++;
    }
    return n;
}
int getNoOfTimePeriods(char * str)
{
    char * p;
    int n=0;
    for(p=strtok(str," ");p!=0;p=strtok(NULL," "))
        n++;
    return n;
}