#include <stdio.h>
#include <stdlib.h>
#define UNVISITED 0
#define VISITED 1

typedef struct node
{
    int key;
    struct node * next;
} NodeT;
NodeT * queue,* stack;
int ** adjMatrix;
int nrOfVertexes;

void readFromAdjMatrix(FILE *f)
{
    int n;
    fscanf(f,"%d",&n);
    nrOfVertexes=n;
    int i,j;
    adjMatrix=(int**)malloc(sizeof(int*)*n);
    for (i=0; i<n; i++)
    {
        *(adjMatrix+i)=(int*)malloc(sizeof(int)*n);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            fscanf(f,"%d",&adjMatrix[i][j]);
    fclose(f);
}

void printAdjMatrix()
{
    int i, j;
    printf("The matrix is:\n");
    printf("    ");
    for(i=0; i<nrOfVertexes; i++)
    {
        printf("%c   ",'A'+i);
    }
    printf("\n");
    for (i = 0; i < nrOfVertexes; i++)
    {
        printf("%c ",'A'+i);
        for (j=0; j<nrOfVertexes; j++)
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}
NodeT * createNode(int key)
{
    NodeT * p=(NodeT*)malloc(sizeof(NodeT));
    p->key=key;
    p->next=NULL;
    return p;
}
void enqueue(int key)
{
    if(queue==NULL)
        queue=createNode(key);
    else
    {
        NodeT * aux=queue;
        while(aux->next!=NULL)
            aux=aux->next;
        aux->next=createNode(key);
    }
}

void dequeue()
{
    if(queue!=NULL)
        queue=queue->next;
}
NodeT * peekQueue()
{
    return queue;
}
int isEmptyQueue()
{
    return queue==NULL;
}
int numberOfNeighbours(int node)
{
    if(node<nrOfVertexes)
    {
        int count=0;
        for(int i=0; i<nrOfVertexes; i++)
            if(adjMatrix[node][i]>0 && i!=node)
                count++;
        return count;
    }
    else
        return 0;

}
int * getNeighbours(int node)
{
    if(node<nrOfVertexes)
    {
        int nrOfNeighbours=numberOfNeighbours(node);
        int * neighbours=(int*)malloc(sizeof(int)*nrOfNeighbours);
        int j=0;
        for(int i=0; i<nrOfVertexes; i++)
            if(adjMatrix[node][i]>0 && i!=node)
            {
                neighbours[j]=i;
                j++;
            }
        return neighbours;
    }
    else
        return NULL;
}
void BFS(int startNode)
{
    printf("BFS Traversal from start node %c is:\n",'A'+startNode);
    int v,w,i;
    int * visited=(int*)malloc(sizeof(int)*nrOfVertexes);
    for(i=0; i<nrOfVertexes; i++)
        visited[i]=UNVISITED;

    enqueue(startNode);
    visited[startNode]=VISITED;
    printf("%c ",'A'+startNode);

    while(!isEmptyQueue())
    {
        v=peekQueue()->key;
        dequeue();
        int nrOfNeighbours=numberOfNeighbours(v);
        int * neighbours=getNeighbours(v);
        for(i=0; i<nrOfNeighbours; i++)
        {
            w=neighbours[i];
            if(visited[w]==UNVISITED)
            {
                printf("%c ",'A'+w);
                enqueue(w);
                visited[w]=VISITED;
            }
        }
    }
    printf("\n");
}
void push(int key)
{
    NodeT * p=(NodeT*)malloc(sizeof(NodeT));
    p->next=stack;
    p->key=key;
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
void DFS(int startNode)
{
    printf("DFS Traversal from start node %c is:\n",'A'+startNode);
    int v,w,i;
    int * visited=(int*)malloc(sizeof(int)*nrOfVertexes);
    for(i=0; i<nrOfVertexes; i++)
        visited[i]=UNVISITED;

    push(startNode);
    while(!isEmptyStack())
    {
        v=peekStack()->key;
        pop();
        if(visited[v]==UNVISITED)
        {
            visited[v]=VISITED;
            int nrOfNeighbours=numberOfNeighbours(v);
            int * neighbours=getNeighbours(v);
            for(i=nrOfNeighbours-1;i>=0;i--)
            {
                w=neighbours[i];
                if(visited[w]==UNVISITED)
                    push(w);
            }
            printf("%c ",'A'+v);
        }

    }
    printf("\n");
}
int main()
{
    FILE * f=fopen("input.dat","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    int key;
    printf("Insert the start node for the BFS Traversal:\n");
    scanf("%d",&key);
    BFS(key);
    printf("Insert the start node for the DFS Traversal:\n");
    scanf("%d",&key);
    DFS(key);
    return 0;
}
