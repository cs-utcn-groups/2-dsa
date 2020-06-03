//
// Created by Irina on 20/05/2020.
//
#include "edge.h"

edgeT * createEdge(int s, int d, int w){
    edgeT * newEdge = (edgeT*)malloc(sizeof(edgeT));
    newEdge->destination = d;
    newEdge->source = s;
    newEdge->weight = w;
    return newEdge;
}
int getNumberOfEdges(){
    for(int i=0; i<nrOfVertexes; i++){
        for(int j=i; j<nrOfVertexes; j++){
            if(adjMatrix[i][j] > 0 && i != j){
                nrOfEdges++;
            }
        }
    }
    return nrOfEdges;
}
void getEdges(){
    int n = getNumberOfEdges();
    allEdges = (edgeT**)malloc(n * sizeof(edgeT));
    int k=0;
    for(int i=0; i<nrOfVertexes; i++){
        for(int j=i; j<nrOfVertexes; j++){
            if(adjMatrix[i][j] > 0 && i != j){
                allEdges[k] = (edgeT*)malloc(sizeof(edgeT));
                edgeT * newEdge = createEdge(i + 'A', j + 'A', adjMatrix[i][j]);
                allEdges[k] = newEdge;
                k++;
            }
        }
    }
}
void sortEdges(){
    for(int i=0; i<nrOfEdges; i++){
        for(int j=i; j<nrOfEdges; j++) {
            if(allEdges[i]->weight > allEdges[j]->weight){
                edgeT * temp = allEdges[i];
                allEdges[i] = allEdges[j];
                allEdges[j] = temp;
            }
        }
    }
}
