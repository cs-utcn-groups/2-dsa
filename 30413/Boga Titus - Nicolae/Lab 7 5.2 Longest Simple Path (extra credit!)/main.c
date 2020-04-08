#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5000

typedef struct _List
{
    int Data;
    struct _List *Next;
}List;

List ** graph=NULL;
int n,dim;
int start, stop;
bool visited[MAX];
int path[MAX];
List *stack=NULL;

void pushS(int x)
{
    if(stack==NULL)
    {
        stack=(List*)malloc(sizeof(List));
        stack->Data=x;
        stack->Next=NULL;
    } else
    {
        List * newEl=(List*)malloc(sizeof(List));
        newEl->Data=x;
        newEl->Next=stack;
        stack=newEl;
    }
}

void popS()
{
    if(stack==NULL)
        return;
    List *p=stack;
    stack=stack->Next;
    free(p);
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

int count()
{
    int count=0;
    List *p=stack;
    while(p)
        ++count,p=p->Next;
    return count;
}

void DFS(int x)
{
    pushS(x);
    if(x==stop)
    {
        if(count()>dim)
        {
            dim=count();
            List*p=stack;
            for(int i=dim-1;i>=0;--i,p=p->Next)
                path[i]=p->Data;
        }
        return;
    }
    for(List *it=graph[x];it!=NULL;it=it->Next)
        if(!visited[it->Data])
            visited[it->Data]=true,DFS(it->Data),visited[it->Data]=false;
    popS();
}

int * longestPath(int x,int y)
{
    start=x,stop=y;
    free(stack);
    stack=NULL;
    dim=0;
    visited[x]=true;
    DFS(x);
    visited[x]=false;
    return path;
}

int main() {
    int x,y;
    FILE *f=fopen("input.dat","r");
    graph=(List**)malloc(sizeof(List*)*MAX);
    for(int i=0;i<MAX;++i)
        graph[i]=NULL;
    fscanf(f,"%d",&n);
    while(fscanf(f,"%d %d",&x,&y)!=EOF)
        push(x,y),push(y,x);
    printf("Enter the two nodes:");
    scanf("%d%d",&x,&y);
    int *way=longestPath(x,y);
    for(int i=0;i<dim;++i)
        printf("%d ",way[i]);
    return 0;
}
