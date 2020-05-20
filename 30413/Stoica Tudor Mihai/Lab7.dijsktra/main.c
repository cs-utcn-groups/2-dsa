#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STARTING_NODE 0
#define oo 1<<30
#define MAX_NR_VERTEXES 105

typedef struct vertex
{
    int distance;
    int neighbour;
    struct node * next;
} vertex;

int nrNodes;
vertex * nodeFirst[MAX_NR_VERTEXES];
vertex * nodeLast[MAX_NR_VERTEXES];
bool visited[MAX_NR_VERTEXES];
int distance[MAX_NR_VERTEXES];
int queue[MAX_NR_VERTEXES];
int queueFirst=0,queueLast=-1;

void initVertexArrayAndDistance()
{
    for(int i=0; i<MAX_NR_VERTEXES; i++)
    {
        nodeFirst[i]=NULL;
        nodeLast[i]=NULL;
        distance[i]=oo;
    }
}

void addEdge(int node1Index, int node2Index, int distance)
{
    if(nodeFirst[node1Index]==NULL)
    {
        nodeFirst[node1Index]=(vertex *) malloc(sizeof(vertex));
        nodeFirst[node1Index]->neighbour=node2Index;
        nodeFirst[node1Index]->distance=distance;
        nodeLast[node1Index]=nodeFirst[node1Index];
    }

    else
    {
        vertex * element=(vertex *) malloc(sizeof(vertex));
        element->next = NULL;
        element->distance = distance;
        element->neighbour=node2Index;
        nodeLast[node1Index]->next = element;
        nodeLast[node1Index] = element;
    }

    if(nodeFirst[node2Index]==NULL)
    {
        nodeFirst[node2Index]=(vertex *) malloc(sizeof(vertex));
        nodeFirst[node2Index]->neighbour=node1Index;
        nodeFirst[node2Index]->distance=distance;
        nodeLast[node2Index]=nodeFirst[node2Index];
    }

    else
    {
        vertex * element=(vertex *) malloc(sizeof(vertex));
        element->next = NULL;
        element->distance = distance;
        element->neighbour=node1Index;
        nodeLast[node2Index]->next = element;
        nodeLast[node2Index] = element;
    }
}

void read(FILE * f)
{
    fscanf(f,"%d",&nrNodes);
    initVertexArrayAndDistance();

    int node1Index,node2Index,distance;

    while(fscanf(f,"%d %d %d",&node1Index,&node2Index,&distance)==3)
    {
        addEdge(node1Index,node2Index,distance);
    }

    dijsktra(STARTING_NODE);
}

void sortQueue()
{
    for(int i=queueFirst; i<queueLast; i++)
    {
        for(int j=i+1; j<=queueLast; j++)
        {
            if(distance[queue[i]]>distance[queue[j]])
            {
                int aux=queue[i];
                queue[i]=queue[j];
                queue[j]=aux;
            }
        }
    }
}

void push(int node)
{
    queue[++queueLast]=node;
    sortQueue();
}

int pop()
{
    int value=queue[queueFirst];

    queueFirst++;

    return value;
}

void dijsktra(int node)
{
    push(node);
    distance[node]=0;

    while(queueFirst<=queueLast)
    {
        int currentNode=pop(queue);

        if(!visited[currentNode])
        {
            visited[currentNode]=true;

            vertex * element=nodeFirst[currentNode];

            while(element!=NULL)
            {
                if(distance[element->neighbour]>distance[currentNode]+element->distance)
                {
                    distance[element->neighbour]=distance[currentNode]+element->distance;
                }

                if(!visited[element->neighbour])
                {
                    push(element->neighbour);
                }

                element=element->next;
            }
        }
    }
}

int main()
{
    FILE *f=fopen("in.txt","r");
    read(f);

    for(int i=0; i<nrNodes; i++)
    {
        printf("%c : %d\n",i+'A',distance[i]);
    }

    return 0;
}
