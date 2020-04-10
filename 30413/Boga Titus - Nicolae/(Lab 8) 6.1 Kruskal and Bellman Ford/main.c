#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50
typedef struct _edge{
    int source, end, weight;
}Edge;

void swap(Edge *a,Edge * b)
{
    Edge aux=*a;
    *a=*b;
    *b=aux;
}


void sort(Edge *E, int n)
{
    bool pres=true;
    while (pres)
    {
        pres=false;
        for(int i=0;i<n-1;++i)
            if(E[i].weight>E[i+1].weight)
            {
                swap(&E[i],&E[i+1]);
                pres=true;
            }
    }
}

void initBool(bool *vector,int n)
{
    for(int i=0;i<=n;++i)
        vector[i]=false;
}

void DFS(int x,bool visited[MAX],int n,bool  graph[MAX][MAX],int from ,bool * sol)
{
    visited[x]=true;
    for(int i=1;i<=n&&((*sol)==false);++i)
    {
       if(i==x||i==from)
           continue;
       if(graph[x][i]&&visited[i])
       {
           *sol=true;
           return;
       }
       else if(graph[x][i]&&!visited[i])
       {
           DFS(i,visited,n,graph,x,sol);
       }
    }

}

bool checkLoops(bool graph[MAX][MAX],int n)///true if we find a loop
{
    bool visited[MAX],sol=false;
    initBool(visited,n);
    for(int i=1;i<=n;++i,sol=false)
        if(!visited[i])
        {
            DFS(i,visited,n,graph,0,&sol);
            if(sol)
                return true;
        }
    return false;
}

void Kruskal(Edge *E, int n, int nrEdges)
{
    printf("Kruskal:\n");
    int cn=n;
    sort(E,nrEdges);
    bool graph[MAX][MAX];///minimum spanning tree
    for(int i=0;i<=n;++i)
        initBool(graph[i],n);
    for(int i=0;i<nrEdges&&cn;++i)
    {
        int u=E[i].source;
        int v=E[i].end;
        graph[E[i].source][E[i].end]=graph[E[i].end][E[i].source]=true;
        if(!checkLoops(graph,n))
        {

            printf("Edge #%d: %d %d %d\n",n-cn+1,E[i].source,E[i].end,E[i].weight);
            --cn;
        }
        else
            graph[E[i].source][E[i].end]=graph[E[i].end][E[i].source]=false;

    }



}

void BellmanFord(Edge *E,int n, int nrEdges,int start)
{
    int dist[MAX];
    for(int i=0;i<=n;++i)
        dist[i]=INT_MAX;
    dist[start]=0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<nrEdges;++j)
        {
            int source=E[j].source,end=E[j].end,weight=E[j].weight;
            if(dist[source]!=INT_MAX&& dist[end]>dist[source]+weight)
                dist[end]=dist[source]+weight;
        }
    /// We may add an extra iteration to check whether there is a negative cycle or not
    for(int i=1;i<=n;++i)
        printf("%d ",dist[i]);


}

int main() {
    int n,nrEdges=0;
    FILE *f=fopen("input.dat","r");
    Edge *E=(Edge*)malloc(sizeof(Edge)*MAX);
    fscanf(f,"%d",&n);
    while (fscanf(f,"%d%d%d",&E[nrEdges].source,&E[nrEdges].end,&E[nrEdges].weight)!=EOF)++nrEdges;
    Kruskal(E,n,nrEdges);
    printf("\n");
    printf("Give start point for Bellman Ford:");
    int start;
    scanf("%d",&start);
    BellmanFord(E,n,nrEdges,start);

    return 0;
}
