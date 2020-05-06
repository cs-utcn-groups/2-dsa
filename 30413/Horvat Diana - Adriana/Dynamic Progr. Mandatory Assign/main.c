#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_LENGTH 2000

char **initializeString(int n)
{
    char **string=(char **)malloc(sizeof(char *)*n);
    for(int i=0; i<n; i++)
        string[i]=(char *)malloc(sizeof(char)*MAX_LENGTH);
    return string;
}

void readStrings(FILE *f,char **stringA,char **stringB,int nrOfTests)
{
    for(int i=0; i<nrOfTests; i++)
    {
        fscanf(f,"%s",stringA[i]);
        fscanf(f,"%s",stringB[i]);
    }

}

int verifyLength(char *str1,char *str2)
{
    return abs(strcmp(str1,str2));
}

int verifyLetters(char *str1,char *str2)
{
    int nr=0;

    if(strlen(str1)>strlen(str2))
    {
        for(int i=0;i<strlen(str2);i++)
        {
            if(str1[i]!=str2[i]) nr++;
        }
    }
    else
    {
        for(int i=0;i<strlen(str1);i++)
        {
            if(str1[i]!=str2[i]) nr++;
        }
    }

    return nr;
}

void minNrOfOperations(char **stringA,char **stringB,int nrOfTests)
{
    int nrOfOperations;
    for(int i=0; i<nrOfTests; i++)
    {
        nrOfOperations=verifyLength(stringA[i],stringB[i])+verifyLetters(stringA[i],stringB[i]);
        printf("The min nr of operations for set %d of strings is: %d",i+1,nrOfOperations);
    }
}

int main()
{
    FILE *f=fopen("input.in","r");

    int nrOfTests;
    fscanf(f,"%d",&nrOfTests);

    char **stringA=initializeString(nrOfTests);
    char **stringB=initializeString(nrOfTests);
    readStrings(f,stringA,stringB,nrOfTests);
    minNrOfOperations(stringA,stringB,nrOfTests);

    return 0;
}
