//
// Created by ileana on 4/14/2020.
//

#include "edge.h"

int getNrOfEdges()
{
    int nrEdges = 0;
    for(int i=0; i<nrOfVertexes;i++)
        for(int j=i+1;j<nrOfVertexes;j++)
            if(adjMatrix[i][j]!=0)
                nrEdges++;
    return nrEdges;
}

edgeT * getEdges()
{
    int nrEdges = getNrOfEdges();
    edgeT * edges = (edgeT*)malloc(nrEdges*sizeof(edgeT));
    nrEdges=0;
    for(int i = 0;i < nrOfVertexes; i++)
        for(int j = i+1; j < nrOfVertexes; j++)
            if(adjMatrix[i][j]!=0)
            {
                edgeT newEdge;
                newEdge.source=i;
                newEdge.destination=j;
                edges[nrEdges++]=newEdge;
            }
    return edges;
}

void deleteIncidentEdges(edgeT * edges, int node, int * nrEdges)
{
    for(int i=0; i<*nrEdges;i++)
        if(edges[i].source == node || edges[i].destination == node)
        {
            for(int j=i;j<*nrEdges-1;j++)
                edges[j]=edges[j+1];
            *nrEdges = (*nrEdges)-1;
            i--;
        }
}