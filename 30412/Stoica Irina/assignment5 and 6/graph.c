//
// Created by Irina on 21/05/2020.
//

#include "edge.h"
#include "graph.h"

Graph * createGraph(){
    Graph * newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->nrOfVertexes = nrOfVertexes;
    newGraph->nrOfEdges = nrOfEdges;
    newGraph->edges = (edgeT**)malloc(sizeof(edgeT*));
    for(int i=0; i<nrOfEdges; i++){
        newGraph->edges[i] = (edgeT*)malloc(sizeof(edgeT));
        newGraph->edges[i] = allEdges[i];
    }
    return newGraph;
}