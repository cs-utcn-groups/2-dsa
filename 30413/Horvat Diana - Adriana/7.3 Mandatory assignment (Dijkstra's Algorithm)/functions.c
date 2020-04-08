#include "head.h"

int **initializeMatrix()
{
    int **matrix=(int **)malloc(sizeof(int *)*MAX_LENGTH);
    for(int i=1; i<=MAX_LENGTH; i++)
        matrix[i]=(int *)malloc(sizeof(int)*MAX_LENGTH);
    return matrix;
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


void constructGraph(FILE *f, int **cost, int *nrOfNodes)
{
    char **buffer=initializeBuffer();
    char *string=(char *)malloc(sizeof(char)*MAX_LENGTH);
    char *token=(char *)malloc(sizeof(char)*MAX_LENGTH);
    fgets(string,MAX_LENGTH,f);
    string[strlen(string)-1]='\0';
    *nrOfNodes=atoi(string);
    initializeCostValues(cost,nrOfNodes);
    int i=0,v,w,c;

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
        i++;
    }
}

int findNode(int node, int *n)
{
    if(node>=1 && node<=*n)
        return 1;
    else
        return 0;
}

int getSource(int *n)
{
    int source;
    bool ok=false;
    printf("Enter the source node for Dijkstra's algorithm: ");
    scanf("%d",&source);
    while(ok==false)
    {
        if(findNode(source,n)==1)
        {
            ok=true;
            return source;
        }
        else
        {
            printf("Enter another node, the previous one doesn't belong to the graph: ");
            scanf("%d",&source);
        }

    }

}

int findMin(int *dist, int *nrOfNodes, int *visited)
{
    int distMin=infinity, node=infinity;
    for(int i=1; i<=*nrOfNodes; i++)
        if(dist[i]<distMin && visited[i]==0)
        {
            distMin=dist[i];
            node=i;
        }
    return node;
}

void dijkstra(int *nrOfNodes, int source, int **cost, int *dist)
{
    int *visited=(int *)malloc(sizeof(int)*MAX_LENGTH);
    int *prevNode=(int *)malloc(sizeof(int)*MAX_LENGTH);

    for(int i=1; i<=*nrOfNodes; i++)
    {
        visited[i]=0;
        dist[i]=cost[source][i];
        if(dist[i]<infinity)
            prevNode[i]=source;
        else
            prevNode[i]=-1;
    }

    visited[source]=1;
    dist[source]=0;
    prevNode[source]=0;

    int node;
    for(int step=1; step<*nrOfNodes; step++)
    {
        node=findMin(dist,nrOfNodes,visited);
        if(node==infinity)
            return;

        if(step==1) prevNode[node]=source;
        visited[node]=1;
        dist[node]=dist[prevNode[node]]+cost[prevNode[node]][node];
        for(int i=1;i<=*nrOfNodes;i++)
            if(visited[i]==0 && dist[node]+cost[node][i]<dist[i])
        {
            dist[i]=dist[node]+cost[node][i];
            prevNode[i]=node;
        }
    }
}

void printDistances(int *nrOfNodes, int source, int *dist, FILE *g)
{
    for(int i=1;i<=*nrOfNodes;i++)
    {
        fprintf(g,"The distance from the source node %d to the destination node %d is: %d\n",source,i,dist[i]);
    }
}

