//
// Created by Anca on 4/27/2020.
//

#include "graphAlgorithms.h"
#include "graphRepresentation.h"

edgeT getMinimumEdgeForCurrentlyVisitedNodes(const int *visited);

void printEdges(edgeT *edges, int n);


void prim(int startNode) {
    printf("Prim's Algorithm started\n");

    int nrVertexesVisited = 0, i, minCost = 0;
    int *visited = (int *) malloc(sizeof(int) * noOfVertices);
    for (i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }

    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (noOfVertices - 1));

    visited[startNode] = VISITED;

    while (nrVertexesVisited < noOfVertices - 1) {
        edgeT minEdge = getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination] = VISITED;
        edges[nrVertexesVisited++] = minEdge;
        minCost += minEdge.weight;
    }

    printEdges(edges, nrVertexesVisited);
    printf("Cost of MST by Prim's Algorithm: %d\n", minCost);
    printf("Prim's algorithm ended\n\n");
}

void printEdges(edgeT *edges, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c -> %c\t", edges[i].source + 'A', edges[i].destination + 'A');
    }
    printf("\n");
}

edgeT getMinimumEdgeForCurrentlyVisitedNodes(const int *visited) {
    edgeT minimumEdge;
    minimumEdge.weight = MAX;

    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (visited[i] == VISITED && visited[j] == UNVISITED && adjMatrix[i][j] > 0) {
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

int getMinDistanceVertex(const int *distances, const int *visited) {
    int min = MAX, i;
    int minV = 0;
    for (i = 0; i < noOfVertices; i++) {
        if (distances[i] < min && visited[i] == UNVISITED) {
            minV = i;
        }
    }
    return minV;
}

void dijkstra(int startNode) {
    printf("Dijkstra's Algorithm started\n");

    int *distances = (int *) malloc(noOfVertices * sizeof(int));
    int *previous = (int *) malloc(noOfVertices * sizeof(int));
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int nrOfVerticesVisited = 0, i;
    for (i = 0; i < noOfVertices; i++) {
        distances[i] = MAX;
        previous[i] = UNDEFINED;
        visited[i] = UNVISITED;
    }
    distances[startNode] = 0;

    while (nrOfVerticesVisited < noOfVertices) {
        int u = getMinDistanceVertex(distances, visited);
        visited[u] = VISITED;

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
        int *neighbors = getAllNeighborsOfVertex(u);
        for (i = 0; i < nrOfNeighbors; i++) {
            int w = neighbors[i];
            int alt = distances[u] + adjMatrix[u][w];
            if (alt < distances[w]) {
                distances[w] = alt;
                previous[w] = u;
            }
        }
        nrOfVerticesVisited++;
    }

    for (i = 0; i < noOfVertices; i++) {
        int u = i;
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

    printf("Dijkstra's Algorithm ended\n\n");
}

int getNumberOfEdges(){
    int i, j, noOfEdges=0;
    for(i=0; i < noOfVertices; i++){
        for(j=i+1; j < noOfVertices; j++){
            if(adjMatrix[i][j]>0){
                noOfEdges++;
            }
        }
    }
    return noOfEdges;
}

void createEdgesArr(edgeT *edges){
    int i, j, k=0;
    for(i=0; i < noOfVertices; i++){
        for(j=i+1; j < noOfVertices; j++){
            if(adjMatrix[i][j]>0){
                edges[k].weight = adjMatrix[i][j];
                edges[k].source = i;
                edges[k].destination = j;
                k++;
            }
        }
    }
}

void sort(edgeT *edges, int noOfEdges){
    int i, j;
    edgeT temp;
    for(i=0;i<noOfEdges;i++){
        for(j=0;j<noOfEdges-1;j++){
            if(edges[j].weight > edges[j+1].weight){
                temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

void union1(int *previous, int c1, int c2){
    for(int i=0; i<noOfVertices; i++){
        if (previous[i] == c2){
            previous[i] = c1;
        }
    }
}

void kruskal(){
    printf("Kruskal's algorithm started\n");

    int noOfEdges = getNumberOfEdges();
    edgeT *edges = (edgeT*) malloc (noOfEdges * sizeof(edgeT));
    createEdgesArr(edges);

    edgeT *mst = (edgeT*) malloc ((noOfVertices - 1) * sizeof(edgeT)); // in a mst: noOfEdges=noOfVertices-1
    int *previous = (int*) malloc (noOfVertices * sizeof(int));
    int i, cost = 0, noOfEdgesInMST = 0, c1, c2;

    for(i=0; i < noOfVertices; i++){
        previous[i] = i;
    }

    sort(edges, noOfEdges);

    for (i=0;i<noOfEdges;i++){
        c1 = previous[edges[i].source];
        c2 = previous[edges[i].destination];
        if(c1 != c2){
            mst[noOfEdgesInMST++] = edges[i];
            union1(previous, c1, c2);
        }
    }

    for(i=0;i<noOfEdgesInMST;i++){
        cost = cost + mst[i].weight;
    }

    printEdges(mst, noOfVertices - 1);
    printf("Cost of MST by Kruskal's algorithm is %d\n", cost);

    free(previous);
    free(mst);
    free(edges);

    printf("Kruskal's algorithm ended\n\n");
}

void bellmanford(int startNode){
    printf("Bellman Ford's Algorithm started\n");
    int i, j;

    int noOfEdges = getNumberOfEdges();
    edgeT *edges = (edgeT*) malloc (noOfEdges * sizeof(edgeT));
    createEdgesArr(edges);

    int *distances = (int *) malloc(noOfVertices * sizeof(int));
    int *previous = (int *) malloc(noOfVertices * sizeof(int));
    int *visited = (int *) malloc(noOfVertices * sizeof(int));

    for (i = 0; i < noOfVertices; i++) {
        distances[i] = MAX;
        previous[i] = UNDEFINED;
    }
    distances[startNode] = 0;

    for(j = 0; j < noOfVertices-1; j++){
        for (i = 0; i < noOfVertices; i++) {
            visited[i] = UNVISITED;
        }
        int nrOfVerticesVisited = 0;
        while (nrOfVerticesVisited < noOfVertices) {
            int u = getMinDistanceVertex(distances, visited);
            visited[u] = VISITED;

            int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
            int *neighbors = getAllNeighborsOfVertex(u);

            for (i = 0; i < nrOfNeighbors; i++) {
                int w = neighbors[i];
                int alt = distances[u] + adjMatrix[u][w];
                if (alt < distances[w]) {
                    distances[w] = alt;
                    previous[w] = u;
                }
            }
            nrOfVerticesVisited++;
        }
    }

    for(j = 0; j < noOfVertices; j++){
        int u = j;
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
        int *neighbors = getAllNeighborsOfVertex(u);
        for (i = 0; i < nrOfNeighbors; i++) {
            int w = neighbors[i];
            int alt = distances[u] + adjMatrix[u][w];
            if (alt < distances[w]) {
                printf("Negative weight cycle detected: %c  %c\n", u+'A', w+'A');
            }
        }
    }

    for (i = 0; i < noOfVertices; i++) {
        int k = i;
        if (i != startNode) {
            while (previous[k] != UNDEFINED) {
                push(k);
                k = previous[k];
            }

            printf("Path from %c to %c is: %c ", startNode + 'A', i + 'A', startNode + 'A');
            while (!isEmptyStack()) {
                printf(" -> %c ", peekStack()->content + 'A');
                pop();
            }
            printf("\n");
        }
    }
    printf("Bellman Ford's Algorithm ended\n\n");
}
