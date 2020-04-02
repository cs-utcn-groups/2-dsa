#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NR_NODES 105
#define startingNode 0

int nrNodes;
int stackSize;

void push(int * stack, int value)
{
    stack[stackSize]=value;
    stackSize++;
}

void pop(int * stack)
{
    free(stack[stackSize-1]);
    stackSize--;
}


void readInput(FILE * f,bool ** adjMat,int * stack,bool * visited)
{
    for(int i=0; i<nrNodes; i++)
    {
        for(int j=0; j<nrNodes; j++)
        {
            fscanf(f,"%d",&adjMat[i][j]);
        }
    }
    /// start with node 0
    push(stack,startingNode);
    dfs(adjMat,stack,visited);
}

void dfs(bool ** adjMat,int * stack,bool * visited)
{
    while(stackSize>0)
    {
        int currentNode=stack[stackSize-1];

        if(visited[currentNode]==false)
        {
            printf("%d ",currentNode);
        }

        visited[currentNode]=true;
        bool foundSmthg=false;

        for(int i=0; i<nrNodes; i++)
        {
            if(i!=currentNode && adjMat[currentNode][i] && visited[i]==false)
            {
                foundSmthg=true;
                push(stack,i);
                break;
            }
        }

        if(foundSmthg==false)
        {
            pop(stack);
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

    int * stack=(int *) malloc(sizeof(int) * nrNodes);
    bool * visited=(bool *) calloc(nrNodes,sizeof(bool));

    readInput(f,adjacentMatrix,stack,visited);

    return 0;
}
