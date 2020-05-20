#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 500

bool graph[MAX][MAX],visited[MAX];
int cover[MAX];

typedef struct _edge
{
    int start,stop;
}Edge;

Edge make_edge(int x,int y){Edge e;e.start=x;e.stop=y;return e;}

int main() {
    FILE *f=fopen("input.dat","r");
    int n,x,y,nrEdges=0,count=0;
    Edge E[MAX];
    fscanf(f,"%d",&n);
    while (fscanf(f,"%d%d",&x,&y)!=EOF)
    {
        graph[x][y]=graph[y][x]=true;
        E[nrEdges++]=make_edge(x,y);
    }
    for(int i=0;i<nrEdges;++i)
    {
        int start=E[i].start,stop=E[i].stop;
        if(!visited[start]&&!visited[stop])
        {
            visited[start]=visited[stop]=true;
            cover[count++]=start;
            cover[count++]=stop;
        }

    }
    printf("Cover: ");
    for(int i=0;i<count;++i)
        printf("%d ",cover[i]);



    return 0;
}
