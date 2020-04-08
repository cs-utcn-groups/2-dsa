#include "head.h"

int **initializeMatrix()
{
    int **matrix=(int **)malloc(sizeof(int *)*MAX_LENGTH);
    for(int i=1; i<=MAX_LENGTH; i++)
        matrix[i]=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return matrix;
}

int *initializeArray()
{
    int *array=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return array;
}

char **initializeBuffer()
{
    char **buffer=(char **)malloc(sizeof(char *)*MAX_LENGTH);
    for(int i=0; i<MAX_LENGTH; i++)
        buffer[i]=(char *)malloc(sizeof(char)*MAX_LENGTH);
    return buffer;
}

void initializeCostValues(int **cost, int *n)
{
    for(int i=1; i<=*n; i++)
        for(int j=1; j<=*n; j++)
        {
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=infinity;
        }
}

void initializeAdjMatrix(int **matrix, int *n)
{
    for(int i=1; i<=*n; i++)
        for(int j=1; j<=*n; j++)
            matrix[i][j]=0;
}

void constructGraph(FILE *f, int **cost, int *nrOfNodes, int *nodesGraph)
{
    char **buffer=initializeBuffer();
    char *string=(char *)malloc(sizeof(char)*MAX_LENGTH);
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);
    int i=1,mx=-1;
    while(fscanf(f,"%d",&nodesGraph[i]))
    {
        if(nodesGraph[i]>mx)
            mx=nodesGraph[i];
        i++;
    }
    *nrOfNodes=mx;
    initializeCostValues(cost,nrOfNodes);
    int v,w,c;

    i=0;
    fgets(string,MAX_LENGTH,f);
    string[strlen(string)-1]='\0';
    token=strtok(string," ");
    strcpy(buffer[i],token);
    while(token!=NULL)
    {
        i++;
        token=strtok(NULL," ");
        if(token!=NULL)
            strcpy(buffer[i],token);
    }

    i=0;
    while(sscanf(buffer[i],"(%d,%d,%d)",&v,&w,&c))
    {
        cost[v][w]=c;
        cost[w][v]=c;
        i++;
    }
}

int findMax(int *dist, int *nrOfNodes, int *visited)
{
    int distMax=infinity, node=infinity;
    for(int i=1; i<=*nrOfNodes; i++)
        if(dist[i]>distMax && visited[i]==0)
        {
            distMax=dist[i];
            node=i;
        }
    return node;
}

void longestPath(int a, int b, int *nrOfNodes, int **cost, FILE *g)
{
    int *visited=(int *)malloc(sizeof(int)*MAX_LENGTH);
    int *prevNode=(int *)malloc(sizeof(int)*MAX_LENGTH);
    int *dist=(int *)malloc(sizeof(int)*MAX_LENGTH);
    int sumLength=0;

    for(int i=1; i<=*nrOfNodes; i++)
    {
        visited[i]=0;
        dist[i]=cost[a][i];
        if(dist[i]>infinity)
            prevNode[i]=a;
        else
            prevNode[i]=-1;
    }

    visited[a]=1;
    dist[a]=0;
    prevNode[a]=0;

    fprintf(g,"Longest Path: %d ",a);

    if(a==b)
        fprintf(g,"\nLength: 0");
    else
    {
        int node=-1;
        for(int step=1; step<*nrOfNodes; step++)
        {
            if(node==b)
            {
                fprintf(g,"\nLength: %d",dist[b]);
                break;
            }
            node=findMax(dist,nrOfNodes,visited);
            if(node==infinity)
                return;

            if(step==1)
                prevNode[node]=a;

            visited[node]=1;
            dist[node]=dist[prevNode[node]]+cost[prevNode[node]][node];

            for(int i=1; i<=*nrOfNodes; i++)
                if(visited[i]==0 && dist[node]+cost[node][i]>dist[i])
                {
                    dist[i]=dist[node]+cost[node][i];
                    prevNode[i]=node;
                }
            fprintf(g,"%d ",node);
        }
    }

}

int findNode(int *nrOfNodes,int *nodesGraph, int node)
{
    for(int i=1; i<=*nrOfNodes; i++)
        if(nodesGraph[i]==node)
            return 1;
    return 0;
}

int getNode(int *nrOfNodes, char *string, int *nodesGraph)
{
    bool ok=false;
    int node;
    scanf("%d",&node);

    while(ok==false)
    {
        if(findNode(nrOfNodes,nodesGraph,node)==1)
        {
            ok=true;
            return node;
        }
        else
        {
            printf("This %s node doesn't belong to the graph. Enter another %s node: ",string,string);
            scanf("%d",&node);
        }
    }
}

