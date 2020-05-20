#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 500


typedef struct _List
{
    int Data;
    struct _List *Next;
}List;

List ** graph=NULL;
int n;
bool graphM[MAX][MAX],visited[MAX];
List *queue=NULL;

void pushQ(int x)
{
    if(queue==NULL)
    {
        queue=(List*)malloc(sizeof(List));
        queue->Data=x;
        queue->Next=NULL;
    } else
    {
        List * newEl=(List*)malloc(sizeof(List));
        List *p=queue;
        while (p->Next)
            p=p->Next;
        newEl->Next=NULL;
        newEl->Data=x;
        p->Next=newEl;
    }
}

void popQ()
{
    if(queue==NULL)
        return;
    List *p=queue;
    queue=queue->Next;
    free(p);
}

int front()
{
    if(queue==NULL)
        return INT_MAX;
    return queue->Data;
}

void push(int Node, int p)
{
    if(graph[Node]==NULL)
    {
        graph[Node]=(List*)malloc(sizeof(List));
        graph[Node]->Data=p;
        graph[Node]->Next=NULL;
    } else
    {
        List * aux=graph[Node];
        while(aux->Next)
            aux=aux->Next;
        List * new=(List*)malloc(sizeof(List));
        new->Next=NULL;
        new->Data=p;
        aux->Next=new;

    }
}

void ListToMatrix()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            graphM[i][j]=false;

    for(int i=1;i<=n;++i)
    {
        List *p=graph[i];
        while(p)
        {
            graphM[i][p->Data]=true;
            p=p->Next;
        }
    }
}


void MatrixToList()
{
    free(graph);
    graph=(List**)malloc(sizeof(List*)*(MAX));
    for(int i=0;i<MAX;++i)
        graph[i]=NULL;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(graphM[i][j])
                push(i,j),push(j,i);
}

void matrixDFS(int x)
{
    printf("%d ",x);
    visited[x]=true;
    for(int i=1;i<=n;++i)
        if(graphM[x][i]&&!visited[i])
            matrixDFS(i);
}

void listDFS(int x)
{
    printf("%d ",x);
    visited[x]=true;
    for(List *it=graph[x];it!=NULL;it=it->Next)
        if(!visited[it->Data])
            listDFS(it->Data);
}

void refreshVisited()
{
    for(int i=1;i<=n;++i)
        visited[i]=false;
}

bool empty()
{
    if(queue==NULL)
        return true;
    return false;
}

void listBFS(int x)
{
    free(queue);
    visited[x]=true;
    queue=NULL;
    pushQ(x);
    while(!empty())
    {
        int u=front();
        printf("%d ",u);
        for(List *it=graph[u];it!=NULL;it=it->Next)
            if(!visited[it->Data])
                visited[it->Data]=true,pushQ(it->Data);
        popQ();
    }
}

void matrixBFS(int x)
{
    free(queue);
    visited[x]=true;
    queue=NULL;
    pushQ(x);
    while(!empty())
    {
        int u=front();
        printf("%d ",u);
        for(int i=1;i<=n;++i)
            if(!visited[i]&&graphM[u][i])
                visited[i]=true,pushQ(i);
        popQ();
    }

}

int main() {int x,y;
    FILE *f=fopen("input.dat","r");
    graph=(List**)malloc(sizeof(List*)*MAX);
    refreshVisited();
    for(int i=0;i<MAX;++i)
        graph[i]=NULL;
    fscanf(f,"%d",&n);
    while(fscanf(f,"%d %d",&x,&y)!=EOF)
        push(x,y),push(y,x);
    ListToMatrix();
    MatrixToList();
    printf("DFS matrix: ");
    matrixDFS(1);
    refreshVisited();
    printf("\n");
    printf("DFS List: ");
    listDFS(1);
    refreshVisited();
    printf("\n");
    printf("BFS matrix: ");
    matrixBFS(1);
    refreshVisited();
    printf("\n");
    printf("BFS List: ");
    listBFS(1);
    return 0;
}
