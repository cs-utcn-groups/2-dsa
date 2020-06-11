//
// Created by Alex on 4/7/2020.
//

#include "graphAlgorithms.h"
#include "graphRepresentation.h"

edgeT getMinimumEdgeForCurrentlyVisitedNodes(const int *visited);

void printEdges(edgeT *edges, int n);

void prim(int startNode) {
    printf("Prim's Algorithm started\n");

    int nrVertexesVisited = 0, i, minCost = 0;
    int *visited = (int *) malloc(sizeof(int) * nrOfVertexes);
    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }

    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (nrOfVertexes - 1));

    visited[startNode] = VISITED;

    while (nrVertexesVisited < nrOfVertexes - 1) {
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

    for (int i = 0; i < nrOfVertexes; i++) {
        for (int j = 0; j < nrOfVertexes; j++) {
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
    for (i = 0; i < nrOfVertexes; i++) {
        if (distances[i] < min && visited[i] == UNVISITED) {
            minV = i;
        }
    }
    return minV;
}

void dijkstra(int startNode) {
    printf("Dijkstra's Algorithm started\n");

    int *distances = (int *) malloc(nrOfVertexes * sizeof(int));
    int *previous = (int *) malloc(nrOfVertexes * sizeof(int));
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int nrOfVertexesVisited = 0, i;
    for (i = 0; i < nrOfVertexes; i++) {
        distances[i] = MAX;
        previous[i] = UNDEFINED;
        visited[i] = UNVISITED;
    }
    distances[startNode] = 0;

    while (nrOfVertexesVisited < nrOfVertexes) {
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
        nrOfVertexesVisited++;
    }

    for (i = 0; i < nrOfVertexes; i++) {
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


    printf("Dijkstra's Algorithm ended\n");
}
