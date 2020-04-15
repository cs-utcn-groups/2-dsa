#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STARTING_VERTEX 0
#define oo 1<<30

typedef struct edgeStruct
{
    int vertex0;
    int vertex1;
    int value;
} edgeStruct;

int nrVertices;

void read(FILE * in);
void prim(edgeStruct * edge,int nrEdges);

void read(FILE * in)
{
    fscanf(in,"%d",&nrVertices);
    edgeStruct * edge=(edgeStruct *) malloc(sizeof(edgeStruct) * (nrVertices *(nrVertices-1)/2));

    int nrEdges=0;

    while(fscanf(in,"%d %d %d",&edge[nrEdges].vertex0,&edge[nrEdges].vertex1,&edge[nrEdges].value)==3)
    {
        nrEdges++;
    }

    prim(edge,nrEdges);
}

void prim(edgeStruct * edge,int nrEdges)
{
    bool * visited=(bool *) calloc(nrVertices,sizeof(bool));
    int * indexArrayOfTreesVertices=(int *) malloc(sizeof(int) * (nrVertices-1));
    int cnt=0;

    visited[STARTING_VERTEX]=true;

    for(int j=0; j<nrVertices-1; j++)
    {
        int mini=oo;
        int index;

        for(int i=0; i<nrEdges; i++)
        {
            if((visited[edge[i].vertex0] && !visited [edge[i].vertex1]) || (!visited[edge[i].vertex0] && visited [edge[i].vertex1]))
            {
                if(edge[i].value<mini)
                {
                    mini=edge[i].value;
                    index=i;
                }
            }
        }
        indexArrayOfTreesVertices[cnt++]=index;
        visited[edge[index].vertex0]=visited[edge[index].vertex1]=true;
    }

    for(int i=0; i<nrVertices-1; i++)
    {
        int index=indexArrayOfTreesVertices[i];
        printf("%d -> %d value %d\n",edge[index].vertex0,edge[index].vertex1,edge[index].value);
    }
}

int main()
{
    FILE * inFile=fopen("inFile.txt","r");
    read(inFile);

    return 0;
}
