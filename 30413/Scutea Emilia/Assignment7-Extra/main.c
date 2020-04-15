#include <stdio.h>
#include <stdlib.h>
int ** adjMat;
int nrOfVertixes;
typedef struct edge
{
    int source,destination;
} Edge;
Edge * edge;
int nrOfEdges;

void readAdjMat(FILE * f)
{
    int n,i,j;
    fscanf(f,"%d",&n);
    nrOfVertixes=n;
    adjMat=(int**)malloc(sizeof(int*)*nrOfVertixes);
    for(i=0; i<n; i++)
    {
        adjMat[i]=(int*)malloc(sizeof(int)*nrOfVertixes);
        for(j=0; j<n; j++)
            fscanf(f,"%d",&adjMat[i][j]);
    }
}
void printAdjMat()
{
    printf("The adjacency matrix is:\n");
    for(int i=0; i<nrOfVertixes; i++)
        printf("   %c",i+'A');
    printf("\n");
    for(int i=0; i<nrOfVertixes; i++)
    {
        printf("%c ",i+'A');
        for(int j=0; j<nrOfVertixes; j++)
            printf(" %2.2d ",adjMat[i][j]);
        printf("\n");
    }
}

Edge * getArrayOfEdges()
{
    printf("Initial edges: ");
    int i,j,k=0;
    nrOfEdges=nrOfVertixes*(nrOfVertixes-1)/2;
    Edge * edge =(Edge*)malloc(sizeof(Edge)*nrOfEdges);
    for(i=0; i<nrOfVertixes; i++)
        for(j=0; j<nrOfVertixes; j++)
            if(i<j && adjMat[i][j]==1)
            {
                edge[k].source=i;
                edge[k].destination=j;
                printf("%d %d;",edge[k].source,edge[k].destination);
                k++;
            }
    nrOfEdges=k;
    printf("\n");
    return edge;
}
void printEdges()
{
    printf("\nRemained edges: ");
    for(int i=0; i<nrOfEdges; i++)
        printf("%d %d;",edge[i].source,edge[i].destination);
    printf("\n");
}

void VertexCover()
{
    edge=getArrayOfEdges();
    printf("Minimum vertex cover: ");
    while(nrOfEdges!=0)
    {
        ///picks an edge at random
        int i=2;
        int u=edge[i].source;
        int v=edge[i].destination;
        printf("%d %d ",u,v);
        for(int j=0; j<nrOfEdges; j++)
        {
            ///deletes all vertices incident either in u or v
            if((edge[j].source==u || edge[j].destination==u) || (edge[j].source==v || edge[j].destination==v))
            {
                for(int i=j; i<nrOfEdges-1; i++)
                    edge[i]=edge[i+1];
                nrOfEdges--;
                j--;
            }
        }
    }
}
int main()
{
    FILE * f=fopen("input.dat","r");
    readAdjMat(f);
    printAdjMat();
    VertexCover();
}
