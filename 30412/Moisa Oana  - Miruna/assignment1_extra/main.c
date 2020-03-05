#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE 200
#define MAX_NAME 50
#define MAX_VALUE 0
#define MIN_VALUE 1000
#define DATA_PATH_IN "../input.dat"
#define DATA_PATH_OUT "../output.dat"

typedef struct node{
    int data;
    struct node *next;

}NodeT;

typedef struct {
    int count;
    NodeT *first;
    NodeT *last;
} ListT;
ListT sentinel;
void printAll(ListT x);
void freeMemory(int nrCountries, char **line, int *sumCountry, char*maxCountry, char* minCountry);
void listSentinels();
void listCountries(char**line,int nrCountries,char countryNames[50][50],ListT country[]);
FILE *out;
FILE * in;
int main() {
    in=fopen(DATA_PATH_IN,"r");
    out=fopen(DATA_PATH_OUT,"w");
    if(in==NULL)
    {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }
    fscanf(in, "%d",&sentinel.count);
    fgetc(in);
    listSentinels();
    NodeT *currentNodeSentinel=sentinel.first;
    int sumS=0;
    while(currentNodeSentinel!=NULL)
    {
        sumS+=currentNodeSentinel->data;
        currentNodeSentinel=currentNodeSentinel->next;
    }
    int nrCountries;
    char **line;
    char countryNames[50][50];
    fscanf(in, "%d", &nrCountries);
    fgetc(in);
    ListT country[nrCountries];
    line=(char**)malloc(nrCountries* sizeof(char*));
    listCountries(line,nrCountries,countryNames,country);
    int *sumCountry;
    sumCountry=(int*)malloc(nrCountries* sizeof(int));
    for(int i=0;i<nrCountries;i++)
    {
        NodeT *currentNode=country[i].first;
        int sumC=0;
        while(currentNode!=NULL)
        {
            sumC+=currentNode->data;
            sumCountry[i]=sumC;
            currentNode=currentNode->next;
        }
    }
    int minSum=MIN_VALUE,maxSum=MAX_VALUE;
    char *maxCountry, *minCountry;
    maxCountry=(char*)malloc(MAX_NAME* sizeof(char));
    minCountry=(char*)malloc(MAX_NAME* sizeof(char));
    for(int i=0;i<nrCountries;i++)
    {
        if(sumCountry[i]<minSum) {
            minSum = sumCountry[i];
            strcpy(minCountry,countryNames[i]);
        }
        if(sumCountry[i]>maxSum) {
            maxSum = sumCountry[i];
            strcpy(maxCountry,countryNames[i]);
        }

    }
    fprintf(out,"The weakest country was: %s\n",minCountry);
    fprintf(out,"The strongest country was: %s\n",maxCountry);
    int ok=0;
    for(int i=0;i<nrCountries;i++)
    {
        if(sumCountry[i]>=sumS) {
            fprintf(out, "Country %s could have defeated all the sentinels!", countryNames[i]);
            ok = 1;
        }
    }
    if(ok==0)
        fprintf(out,"No country could have defeated all the sentinels.\n");
    int j=0;
    int suma=sumS;
    while(suma>0)
    {
        if(j==nrCountries) {
            j = 0;
        }
        if(country[j].first!=NULL) {
            suma = suma - country[j].first->data;
            country[j].first = country[j].first->next;
        }
        if(suma<=0)
        {
            fprintf(out, "The tyrant was killed!\n");
            fprintf(out, "The last hit was done by:%s\n", countryNames[j]);

        }
        j++;
    }
    int count=0,rest=0;
    int sumaMaxima=maxSum;
    while(maxSum>0)
    {
        if(sentinel.first->data<maxSum)
        {
            maxSum=maxSum-sentinel.first->data;
            count++;

        }
        else
        {
            rest=sentinel.first->data-maxSum;
            maxSum=0;
        }
        sentinel.first=sentinel.first->next;

    }
    if(sumaMaxima<sumS) {
        fprintf(out,
                "%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d .",
                maxCountry, count, rest, count + 1);
    }
    freeMemory(nrCountries, line, sumCountry, maxCountry, minCountry);
    fclose(in);
    fclose(out);
    return 0;

}
void printAll(ListT x)
{
    NodeT *currentNode;
    if(x.first==NULL)
    {
        fprintf(out, "The list is empty!\n");

    }
    else {
        currentNode = x.first;
        while (currentNode != NULL) {
            fprintf(out,"%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        fprintf(out,"\n");
    }


}
void freeMemory(int nrCountries, char **line, int *sumCountry, char*maxCountry, char* minCountry)
{
    for(int i=0;i<nrCountries;i++)
    {
        free(line[i]);
    }
    free(line);
    free(sumCountry);
    free(maxCountry);
    free(minCountry);
}
void listSentinels()
{
    int nr;
    for(int i=0;i<sentinel.count;i++)
    {
        fscanf(in, "%d",&nr);
        fgetc(in);
        if(sentinel.first==NULL)
        {
            sentinel.first=(NodeT*)malloc(sizeof(NodeT));
            sentinel.first->data=nr;
            sentinel.first->next=sentinel.last;
            sentinel.last=sentinel.first;
        }
        else
        {
            NodeT *newNode;
            newNode=(NodeT*)malloc(sizeof(NodeT));
            sentinel.last->next=newNode;
            newNode->next=NULL;
            newNode->data=nr;
            sentinel.last=newNode;
        }
    }
}
void listCountries(char**line,int nrCountries,char countryNames[50][50],ListT country[])
{

    for(int i=0;i<nrCountries;i++) {
        line[i]=(char*)malloc(MAX_LINE* sizeof(char));
        fgets(line[i],MAX_LINE,in);
        char *p;
        int j=0;
        country[i].first=NULL;
        country[i].last=NULL;
        for (p = strtok(line[i], " "); p != 0; p = strtok(NULL, " "))
        {
            if(j==0)
            {
                strcpy(countryNames[i],p);
            }

            else
            {

                if(country[i].first==NULL)
                {
                    country[i].first=(NodeT*)malloc(sizeof(NodeT));
                    country[i].first->data=atoi(p);
                    country[i].first->next=country[i].last;
                    country[i].last=country[i].first;
                }
                else
                {
                    NodeT *newNode;
                    newNode=(NodeT*)malloc(sizeof(NodeT));
                    country[i].last->next=newNode;
                    newNode->next=NULL;
                    newNode->data=atoi(p);
                    country[i].last=newNode;
                }
            }
            j++;

        }

    }
}

