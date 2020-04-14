//
// Created by Alina Mihut on 4/12/20.
//
#include "graphAlgorithms.h"


void kruskalAlgorithm()
{
    printf ("\n Kruskal's Algorithm starts \n");
    int *component,i,j,c1,c2;
    component=(int*) malloc (MAXN * sizeof(int));
    eList=createEdge();
    spanningTree=createEdge();
    eList->n=0;

    for(i=1;i<nrOfVertexes;i++)
        for(j=0;j<nrOfVertexes;j++)
        {
            if(adjMatrix[i][j]!=0)
            {
                eList->data[eList->n].source=i;
                eList->data[eList->n].destination=j;
                eList->data[eList->n].weight=adjMatrix[i][j];
                eList->n++;
            }
        }
    sortEdges();
    for(i=0;i<nrOfVertexes;i++)
        component[i]=i;

    spanningTree->n=0;

    for(i=0;i<eList->n;i++)
    {
        c1= findVertexInConnectedComponent(component, eList->data[i].source);
        c2= findVertexInConnectedComponent(component, eList->data[i].destination);

        if(c1!=c2)
        {
            spanningTree->data[spanningTree->n]=eList->data[i];
            spanningTree->n=spanningTree->n+1;
            UNION(component, c1, c2);
        }
    }
    printSpanningTree();
    printf ("\n Kruskal's algorithm ended \n");
}


void bellmanFord (int startNode)
{
    printf("\n Bellman Ford algorithm started \n");

    int u,v,w;
    int nrOfEdges;
    int *distances=(int*)malloc(nrOfVertexes* sizeof(int));
    int *previous= (int*)malloc(nrOfVertexes* sizeof(int));

    eList->n = 0;
    for (int i = 1; i < nrOfVertexes; i++)
        for (int j = 0; j < nrOfVertexes; j++) {
            if (adjMatrix[i][j] != 0 && i != j) {
                eList->data[eList->n].source = i;
                eList->data[eList->n].destination = j;
                eList->data[eList->n].weight = adjMatrix[i][j];
                eList->n++;
            }
        }
    nrOfEdges = eList->n;

    for(int i=0;i<nrOfVertexes;i++)
    {

        distances[i]=INFINITY;
        previous[i]=UNDEFINED;
    }
    distances[startNode]=0;
    for(int i=0;i<nrOfVertexes-1;i++) {
        for(int j=0;j<nrOfEdges;j++) {

            u = eList->data[j].source;
            v = eList->data[j].destination;
            w = eList->data[j].weight;

            if(distances[u]!=INFINITY && distances[v]>distances[u] + w) {
                distances[v] = distances[u]+w;
                previous[v] = u;
            }
        }
    }

    for(int i = 0; i < nrOfEdges; i++) {
        u = eList->data[i].source;
        v = eList->data[i].destination;
        w = eList->data[i].weight;
        if(distances[u] != INFINITY && distances[v] > distances[u] + w) {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }
    for (int i = 0; i < nrOfVertexes; i++) {
        u = i;
        if (i != startNode) {
            while (previous[u] != UNDEFINED) {
                push(u);
                u = previous[u];
            }

            printf("Path from %c to %c is: %c ", startNode + 'A', i + 'A', startNode + 'A');
            while (!isEmptyStack()) {
                printf(" -> %c ", peekStack()->content + 'A');
                pop();
            }
            printf("\n");
        }
    }
    printf("\n Bellman Ford algorithm ended \n");
}
