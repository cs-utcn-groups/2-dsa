//
// Created by Diana on 04/05/2020.
//
#include "graph_algorithms.h"
#include "graph.h"
#include "algo_helpers.h"
#include "neighbors.h"
void prim(int startNode) {
    printf("Prim's algorithm started\n");

    int noOfVerticesVisited = 0, minCost = 0;
    int *visited = (int *) malloc (noOfVertices * sizeof(int));
    for (int i=0; i<noOfVertices; i++) {
        visited[i] = UNVISITED;
    }

    edgeT *edges = (edgeT *) malloc ((noOfVertices-1) * sizeof(edgeT));

    visited[startNode] = VISITED;

    while (noOfVerticesVisited < noOfVertices-1) {
        edgeT minEdge = getMinimumEdgeForCurrentVisitedNodes(visited);
        visited[minEdge.destination] = VISITED;
        edges[noOfVerticesVisited++] = minEdge;
        minCost += minEdge.weight;
    }

    printEdges(edges, noOfVerticesVisited);
    printf("Cost of MST: %d\n",minCost);
    printf("Prim's algorithm ended\n\n");
}

void dijkstra(int startNode) {
    printf("Dijkstra's algorithm started\n");

    int *distances = (int *) malloc (noOfVertices * sizeof(int));
    int *previous = (int *) malloc (noOfVertices * sizeof(int));
    int *visited = (int *) malloc (noOfVertices * sizeof(int));
    int noOfVerticesVisited = 0;
    for(int i=0; i<noOfVertices; i++) {
        distances[i] = MAX;
        previous[i] = UNDEFINED;
        visited[i] = UNVISITED;
    }
    distances[startNode] = 0;

    while (noOfVerticesVisited < noOfVertices) {
        int u = getMinDistanceVertex(distances, visited);
        visited[u] = VISITED;

        int noOfNeighbors = getNumberOfNeighborsOfVertex(u);
        int *neighbors = getAllNeighborsOfVertex(u);
        for(int i=0; i<noOfNeighbors; i++) {
            int w = neighbors[i];
            int alt = distances[u] + adjMatrix[u][w];
            if (alt < distances[w]) {
                distances[w] = alt;
                previous[w] = u;
            }
        }
        noOfVerticesVisited++;
    }

    for (int i=0; i<noOfVertices; i++) {
        int u = i;
        if (i != startNode) {
            while (previous[u] != UNDEFINED) {
                push(u);
                u = previous[u];
            }

            printf("Path from %c to %c is: %c ",startNode + 'A', i + 'A', startNode + 'A');
            while(!isEmptyStack()) {
                printf(" -> %c ",peekStack()->key + 'A');
                pop();
            }
            printf("\n");
        }
    }

    printf("Dijkstra's algorithm ended\n\n");
}

void kruskal() {
    printf("Kruskal's algorithm started\n");

    int minCost=0;
    int noOfEdges = getNoOfEdges();
    edgeT * edges = getEdges(noOfEdges);
    sortEdges(edges, noOfEdges);

    int * belongs = (int *) malloc (noOfVertices * sizeof(int));
    for(int i=0;i<noOfVertices;i++) {
        belongs[i] = i;
    }

    edgeT *spanEdges = (edgeT *) malloc (noOfEdges * sizeof(edgeT));
    int noOfEdgesInSpanTree = 0;
    int belongsToSomeVertex;
    int belongsToSomeOtherVertex;
    for(int i=0; i < noOfEdges; i++) {
        belongsToSomeVertex = find(belongs, edges[i].source);
        belongsToSomeOtherVertex = find(belongs, edges[i].destination);
        if(belongsToSomeVertex != belongsToSomeOtherVertex) {
            spanEdges[noOfEdgesInSpanTree++] = edges[i];
            matchVertices(belongsToSomeVertex, belongsToSomeOtherVertex, belongs);
            minCost += edges[i].weight;
        } //else it makes a cycle
    }
    printEdges(spanEdges, noOfEdgesInSpanTree);
    printf("Cost of MST: %d\n",minCost);
    printf("Kruskal's algorithm ended\n\n");
}

void BellmanFord(int sourceNode) {
    printf("Bellman Ford's algorithm started\n");

    int noOfEdges = getNoOfEdges();
    int *storeDistances = (int *) malloc (noOfVertices * sizeof(int));
    edgeT *edges = getEdges(noOfEdges);
    for(int i=0; i<noOfVertices; i++) {
        storeDistances[i] = MAX;
    }
    storeDistances[sourceNode] = 0;

    for(int i=0;i<noOfVertices;i++) {
        for(int j=0; j<noOfEdges; j++) {
            int v1 = edges[j].source;
            int v2 = edges[j].destination;
            int weight = edges[j].weight;
            if(storeDistances[v1]!=MAX && storeDistances[v1] + weight <storeDistances[v2]) {
                storeDistances[v2] = storeDistances[v1] + weight;
            }
        }
    }

    for(int i=0; i<noOfEdges; i++) {
        int v1 = edges[i].source;
        int v2 = edges[i].destination;
        int weight = edges[i].weight;
        if(storeDistances[v1]!=MAX && storeDistances[v1] + weight <storeDistances[v2]) {
            printf("This graph contains a negative edge cycle!\n");
            return;
        }
    }

    printf("Vertex\t\tDistance from source vertex\n");
    for(int i=0; i<noOfVertices; i++) {
        printf("%c \t\t %d\n",i + 'A',storeDistances[i]);
    }

    printf("Bellman Ford's algorithm ended\n\n");
}