#include "head.h"

int *initializeArray()
{
    int *array=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return array;
}

int **initializeMatrix()
{
    int **matrix=(int **)malloc(sizeof(int *)*MAX_LENGTH);
    for(int i=0;i<MAX_LENGTH;i++)
        matrix[i]=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return matrix;
}

void initializeAdjMatrix(int **matrix, int *n)
{
    for(int i=0;i<*n;i++)
        for(int j=0;j<*n;j++)
        matrix[i][j]=0;
}

char **initializeBuffer()
{
    char **buffer=(char **)malloc(sizeof(char *)*MAX_LENGTH);
    for(int i=0;i<MAX_LENGTH;i++)
        buffer[i]=(char *)malloc(sizeof(char)*MAX_LENGTH);
    return buffer;
}

void constructGraph(int *nodesGraph, int *nodesSubGraph, int **adjMatrix, int *nrOfNodesGraph, int *nrOfNodesSubGraph,FILE *f)
{
    int i=0,v,w,mx=-1;
    while(fscanf(f,"%d",&nodesGraph[i]))
    {
        if(nodesGraph[i]>mx) mx=nodesGraph[i];
        i++;
    }
    *nrOfNodesGraph=mx;

    char **buffer=initializeBuffer();
    initializeAdjMatrix(adjMatrix,nrOfNodesGraph);
    char *string=(char *)malloc(sizeof(char)*MAX_LENGTH);
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);

    fgets(string,MAX_LENGTH,f);
    string[strlen(string)-1]='\0';
    token=strtok(string," ");
    i=0;
    strcpy(buffer[i],token);
    while(token!=NULL)
    {
        i++;
        token=strtok(NULL," ");
        if(token!=NULL)
            strcpy(buffer[i],token);
    }

    i=0;
    while(sscanf(buffer[i],"(%d,%d)",&v,&w))
    {
       adjMatrix[v-1][w-1]=1;
       i++;
    }

    i=0;
    fgets(string,MAX_LENGTH,f);
    string[strlen(string)-1]='\0';
    token=strtok(string," ");
    nodesSubGraph[i]=atoi(token);
    while(token!=NULL)
    {
        i++;
        token=strtok(NULL," ");
        if(token!=NULL) nodesSubGraph[i]=atoi(token);
    }
    *nrOfNodesSubGraph=i;
}

void constructSubGraph(int *nodesSubGraph, int **adjMatrix, int *nrOfNodesSubGraph, FILE *g)
{
    int m,n;
    for(int i=0;i<*nrOfNodesSubGraph;i++)
        for(int j=0;j<*nrOfNodesSubGraph;j++)
    {
        n=nodesSubGraph[i];
        m=nodesSubGraph[j];
        if(adjMatrix[n-1][m-1]==1) fprintf(g,"(%d,%d) ",n,m);
    }
}
