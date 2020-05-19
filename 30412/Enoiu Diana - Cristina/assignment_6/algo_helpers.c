//
// Created by Diana on 05/05/2020.
//
#include "algo_helpers.h"
#include "graph.h"
edgeT getMinimumEdgeForCurrentVisitedNodes(const int *visited) {
    edgeT minimumEdge;
    minimumEdge.weight = MAX;

    for (int i=0; i<noOfVertices;i++) {
        for(int j=0; j<noOfVertices;j++) {
            if (visited[i] == VISITED && visited[j] == UNVISITED && adjMatrix[i][j]>0) {
                if (adjMatrix[i][j] < minimumEdge.weight) {
                    minimumEdge.source = i;
                    minimumEdge.destination = j;
                    minimumEdge.weight = adjMatrix[i][j];
                }
            }
        }
    }

    return minimumEdge;
}

void printEdges(edgeT *edges, int n) {
    for(int i=0; i<n; i++) {
        printf("%c -> %c\t", edges[i].source + 'A', edges[i].destination + 'A');
    }
    printf("\n");
}

int getMinDistanceVertex (const int *distances, const int *visited) {
    int min = MAX;
    int minV = 0;
    for(int i=0;i<noOfVertices;i++) {
        if(distances[i] < min && visited[i] == UNVISITED) {
            minV = i;
        }
    }
    return minV;
}

int getNoOfEdges() {
    int noOfEdges=0;
    for(int i=0; i<noOfVertices; i++) {
        for(int j=i+1; j<noOfVertices; j++) {
            if(adjMatrix[i][j] > 0) {
                noOfEdges++;
            }
        }
    }
    return noOfEdges;
}

edgeT * getEdges (int noOfEdges) {
    edgeT * edges = (edgeT*) malloc (noOfEdges * sizeof(edgeT));
    int temp = 0;
    for(int i=0; i<noOfVertices; i++) {
        for(int j=i+1; j<noOfVertices; j++) {
            if(adjMatrix[i][j] > 0) {
                edges[temp].source = i;
                edges[temp].destination = j;
                edges[temp].weight = adjMatrix[i][j];
                temp++;
            }
        }
    }
    return edges;
}
edgeT * sortEdges (edgeT * edges, int noOfEdges) {
    edgeT temp;
    for(int i=0; i<noOfEdges; i++) {
        for (int j=i+1; j<noOfEdges; j++) {
            if(edges[i].weight > edges[j].weight) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
    return edges;
}

int find(int *belongs, int vertex) {
    return(belongs[vertex]);
}

void matchVertices(int vertex1, int vertex2,int * belongs) {
    for(int i=0;i<noOfVertices;i++) {
        if(belongs[i] == vertex2) {
            belongs[i] = vertex1;
        }
    }
}
