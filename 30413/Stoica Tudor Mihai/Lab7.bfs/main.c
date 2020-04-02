#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NR_NODES 105
#define startingNode 0

int nrNodes;
int queueFirst=0,queueLast=-1;

bool queueEmpty()
{
    return (queueFirst>queueLast);
}

void push(int * queue, int value)
{
    queue[++queueLast]=value;
}

int pop(int * queue)
{
    int value=queue[queueFirst];

    queueFirst++;

    return value;
}


void readInput(FILE * f,bool ** adjMat,int * queue,bool * visited)
{
    for(int i=0; i<nrNodes; i++)
    {
        for(int j=0; j<nrNodes; j++)
        {
            fscanf(f,"%d",&adjMat[i][j]);
        }
    }
    /// start with node 0
    push(queue,startingNode);
    bfs(adjMat,queue,visited);
}

void printQueue(int * queue)
{
    for(int i=queueFirst; i<=queueLast; i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void bfs(bool ** adjMat,int * queue,bool * visited)
{
    while(queueFirst<=queueLast)
    {

        int currentNode=pop(queue);

        if(!visited[currentNode])
        {
            printf("%d ",currentNode);
            visited[currentNode]=true;

            for(int i=0; i<nrNodes; i++)
            {
                if(i!=currentNode && adjMat[currentNode][i] && visited[i]==false)
                {
                    push(queue,i);
                }
            }
        }
    }
}

int main()
{

    FILE *f=fopen("in.txt","r");
    fscanf(f,"%d",&nrNodes);
    bool ** adjacentMatrix=(bool **) malloc(sizeof(bool*) * nrNodes);

    for(int i=0; i<nrNodes; i++)
    {
        adjacentMatrix[i]=(bool *) malloc(sizeof(bool) * nrNodes);
    }

    int * queue=(int *) malloc(sizeof(int) * nrNodes);
    bool * visited=(bool *) calloc(nrNodes,sizeof(bool));

    readInput(f,adjacentMatrix,queue,visited);

    return 0;
}
