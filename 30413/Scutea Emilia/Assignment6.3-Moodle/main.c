#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define INFTY 1000
#define UNVISITED 0
#define VISITED 1
#define UNDEFINED 0
typedef struct node
{
    int content;
    struct node * next;
} NodeT;
NodeT * stack;
int ** cost;
int nrOfVertixes;

void push(int key)
{
    NodeT * p=(NodeT*)malloc(sizeof(NodeT));
    p->next=stack;
    p->content=key;
    stack=p;
}
void pop()
{
    if (stack != NULL)
        stack = stack->next;
}
NodeT * peekStack()
{
    return stack;
}
int isEmptyStack()
{
    return stack==NULL;
}
void readFile(FILE * f)
{
    int n,i,j;
    fscanf(f,"%d",&n);
    nrOfVertixes=n;
    cost=(int**)malloc(sizeof(int*)*nrOfVertixes);
    for(i=0; i<nrOfVertixes; i++)
        *(cost+i)=(int*)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            fscanf(f,"%d",&cost[i][j]);
    fclose(f);
}

int getMinDistanceVertex(int * distances,int * visited)
{
    int minim=INFTY,i,minV=0;
    for(i=0; i<nrOfVertixes; i++)
        if(distances[i]<minim && visited[i]==UNVISITED)
        {
            minim=distances[i];
            minV=i;
        }
    return minV;
}
int getNrOfNeighbours(int node)
{
    if(node<nrOfVertixes)
    {
        int count=0;
        for(int i=0; i<nrOfVertixes; i++)
            if(cost[node][i]>0 && i!=node)
                count++;
        return count;
    }
    else
        return 0;

}
int * getNeighbours(int node)
{
    if(node<nrOfVertixes)
    {
        int nrOfNeighbours=getNrOfNeighbours(node);
        int * neighbours=(int*)malloc(sizeof(int)*nrOfNeighbours);
        int j=0;
        for(int i=0; i<nrOfVertixes; i++)
            if(cost[node][i]>0 && i!=node)
            {
                neighbours[j]=i;
                j++;
            }
        return neighbours;
    }
    else
        return NULL;
}

void Dijkstra(int startNode)
{
    printf("Dijkstra algorithm:\n");
    int * distances=(int*)malloc(sizeof(int)*nrOfVertixes);
    int * visited=(int*)malloc(sizeof(int)*nrOfVertixes);
    int * previous=(int*)malloc(sizeof(int)*nrOfVertixes);
    int nrOfVisitedVertex=0,i;
    for(i=0; i<nrOfVertixes; i++)
    {
        distances[i]=INFTY;
        previous[i]=UNDEFINED;
        visited[i]=UNVISITED;
    }
    distances[startNode]=0;
    while(nrOfVisitedVertex<nrOfVertixes)
    {
        int u=getMinDistanceVertex(distances,visited);
        visited[u]=VISITED;
        int nrOfNeighbours=getNrOfNeighbours(u);
        int * neighbours=getNeighbours(u);
        for(i=0; i<nrOfNeighbours; i++)
        {
            int w=neighbours[i];
            int dist=distances[u]+cost[u][w];
            if(dist<distances[w])
            {
                distances[w]=dist;
                previous[w]=u;
            }
        }
        nrOfVisitedVertex++;
    }
    for(i=0; i<nrOfVertixes; i++)
    {
        int u=i;
        if(i!=startNode)
        {
            while(previous[u]!=UNDEFINED)
            {
                push(u);
                u=previous[u];
            }
            printf("Path from %c to %c is %c",startNode+'A',i+'A',startNode+'A');
            while(!isEmptyStack())
            {
                printf("-> %c",peekStack()->content+'A');
                pop();

            }
            printf("\n");
        }
    }
}
int main()
{
    FILE * f=fopen("input.dat","r");
    readFile(f);
    Dijkstra(0);
}
