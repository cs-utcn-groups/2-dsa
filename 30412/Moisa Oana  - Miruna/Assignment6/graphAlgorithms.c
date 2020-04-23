//
// Created by User on 11.04.2020.
//

#include "graphAlgorithms.h"
#include "edge.h"
void initializeList()
{
    list.first=list.last=NULL;

}
void matrixToList()
{
    list.n=0;
    for(int i=0;i<nrOfVertexes;i++)
    {
        for(int j=0;j<nrOfVertexes;j++)
        {
            if(adjMatrix[i][j]!=0) {
                if (list.first==NULL) {
                    list.first=(EdgeT*)malloc(sizeof(EdgeT));
                    list.first->source=i;
                    list.first->destination=j;
                    list.first->weight=adjMatrix[i][j];
                    list.first->next=list.last;
                    list.last=list.first;
                    list.n++;
                }
                else {
                    EdgeT *currentEdge = list.first,*previousEdge=NULL;
                    while (currentEdge != NULL) {
                        int ok = 0;
                        if (adjMatrix[i][j] <= currentEdge->weight) {
                            EdgeT *newEdge = createEdge(i, j, adjMatrix[i][j]);
                            newEdge->next = currentEdge;

                            if(currentEdge==list.first)
                            {
                                list.first=newEdge;
                            } else{
                                previousEdge->next=newEdge;
                            }
                            ok = 1;
                            currentEdge=NULL;
                            list.n++;
                        } else {
                            previousEdge=currentEdge;
                            currentEdge = currentEdge->next;
                        }
                        if (ok == 0 && currentEdge==NULL) {
                            EdgeT *newEdge = createEdge(i, j, adjMatrix[i][j]);
                            newEdge->next = NULL;
                            list.last->next = newEdge;
                            list.last=newEdge;
                            list.n++;
                        }
                    }

                }
            }
        }
    }
}
void printAll()
{
    EdgeT *currentEdge=list.first;
    if(list.first==NULL)
    {
        printf("List is empty!\n");
    }
    else {
        while (currentEdge!= NULL) {
            printf( "%c->%c, %d", currentEdge->source+'A',currentEdge->destination+'A',currentEdge->weight);
           currentEdge = currentEdge->next;
           printf("\n");
        }
    }
}
void Kruskal()
{
    printf("Kruskal algorithm started:\n");
    int *visited=(int*)malloc(nrOfVertexes* sizeof(int));
    int *closesCycle=(int*)malloc(nrOfVertexes* sizeof(int));
    int nrVertexesVisited=0,cost=0;
    initializeList();
    matrixToList();
    for(int i=0;i<nrOfVertexes;i++) {
        visited[i] = UNVISITED;
        closesCycle[i] = i;
    }
    int no1,no2;
    while(nrVertexesVisited<nrOfVertexes)
    {
        EdgeT *currentEdge=list.first;
        while(currentEdge!=NULL)
        {
            no1=closesCycle[currentEdge->source];
            no2=closesCycle[currentEdge->destination];
            if(no1!=no2)
            {
                cost+=currentEdge->weight;
                printf("%c->%c : %d \n",currentEdge->source+'A',currentEdge->destination+'A',currentEdge->weight);
                for(int i=0;i<nrOfVertexes;i++)
                {
                    if(closesCycle[i]==no2)
                        closesCycle[i]=no1;
                }
                if(visited[currentEdge->source]==UNVISITED)
                {
                    visited[currentEdge->source]=VISITED;
                    nrVertexesVisited++;
                }
                if(visited[currentEdge->destination]==UNVISITED)
                {
                    visited[currentEdge->destination]=VISITED;
                    nrVertexesVisited++;
                }
            }
            currentEdge=currentEdge->next;
        }
    }
    printf("The total cost is: %d\n",cost);
    printf("Kruskal algorithm ended\n\n\n");

}
void BellmanFord(int startNode)
{
    printf("Bellman-Ford algorithm started:\n");
    initializeList();
    matrixToList();
    int *distances=(int*)malloc(nrOfVertexes* sizeof(int));
    for(int i=0;i<nrOfVertexes;i++)
    {
        distances[i]=MAX;
    }
    distances[startNode]=0;
    for(int i=0;i<nrOfVertexes;i++)
    {
        EdgeT *currentEdge=list.first;
        while(currentEdge!=NULL)
        {
            int u=currentEdge->source;
            int v=currentEdge->destination;
            int w=currentEdge->weight;
            if(distances[u]!=MAX && distances[u]+w<distances[v])
                distances[v]=distances[u]+w;
            currentEdge=currentEdge->next;
        }
    }
    EdgeT *currentEdge=list.first;
    while(currentEdge!=NULL)
    {
        int u=currentEdge->source;
        int v=currentEdge->destination;
        int w=currentEdge->weight;
        if (distances[u] != MAX && distances[u] + w< distances[v]) {
            printf("Graph contains negative weight cycle");
            return;
        }

        currentEdge=currentEdge->next;
    }
    for(int i=0;i<nrOfVertexes;i++)
    {
        printf("Shortest distance from %c to %c is %d\n",startNode+'A',i+'A',distances[i]);
    }


    printf("Bellman-Ford algorithm ended\n");
}