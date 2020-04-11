//
// Created by Diana on 4/7/2020.
//

#include <stdio.h>
#include "stdlib.h"
#include "head.h"

void readGraph() {
    int n;
    fscanf(inp,"%d",&n);
    nrOfVertices = n;
    adjMatrix = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) {
        adjMatrix[i] = (int *)malloc(nrOfVertices * sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(inp,"%d",&adjMatrix[i][j]);
        }
    }
}
void transformGraphToList() {
    firstVertex = (NodeL**)malloc(nrOfVertices * sizeof(NodeL*));
    currVertex = (NodeL**)malloc(nrOfVertices * sizeof(NodeL*));
    for(int i=0;i<nrOfVertices;i++) {
        firstVertex[i] = NULL;
        firstVertex[i] = (NodeL*)malloc(sizeof(NodeL));
        firstVertex[i]->vertex = i;
        firstVertex[i]->distance = 0;
        firstVertex[i]->next = NULL;
        currVertex[i] = firstVertex[i];
        for(int j=0;j<nrOfVertices;j++) {
            if(adjMatrix[i][j] != 0) {       //found edge
                NodeL * newVertex = (NodeL*)malloc(sizeof(NodeL));
                currVertex[i]->next = newVertex;
                newVertex->vertex = j;
                newVertex->distance = adjMatrix[i][j];
                newVertex->next = NULL;
                currVertex[i] = newVertex;
            }
        }
    }
}
void printLists() {
    for(int i=0;i<nrOfVertices;i++) {
        currVertex[i] = firstVertex[i];
        printf("%c: ", 'A' + currVertex[i]->vertex);
        while(currVertex[i]->next != NULL) {
            currVertex[i] = currVertex[i]->next;
            printf("(%c,%d) ", 'A' + currVertex[i]->vertex, currVertex[i]->distance);
        }
        printf("\n");
    }
}