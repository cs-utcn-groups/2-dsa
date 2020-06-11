//
// Created by Tudor Tise on 11/06/2020.
//

#include "bellmanFord.h"

int findNegativeCycles(const int *dist, int noOfEdges, edgeT *edges) {
    for (int i = 0; i < noOfEdges; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int alt = edges[i].weight + dist[u];
        if (alt < dist[v]) {
            return 1;
        }
    }
    return 0;
}

int findNoOfEdges(int noOfVertices) {
    int noOfEdges = 0, i, j;
    for (i = 0; i < noOfVertices; i++) {
        for (j = 0; j < noOfVertices; j++) {
            if (adjMatrix[i][j] != 0) {
                noOfEdges++;
            }
        }
    }
    return noOfEdges;
}

void BellmanFord(int startNode) {
    printf("BellmanFord algorithm start\n");

    int noOfEdges = findNoOfEdges(nrOfVertexes);
    edgeT *edges = getEdges(nrOfVertexes,noOfEdges);

    int *prev = initArray(nrOfVertexes,UNDEFINED);
    int *dist = initArray(nrOfVertexes,MAX);

    for (int i = 0; i < nrOfVertexes; i++) {
        dist[i] = MAX;
    }

    dist[startNode] = 0;
    for (int i = 0; i < nrOfVertexes; i++) {
        for (int j = 0; j < noOfEdges; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int alt = dist[u] + edges[j].weight;
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
            }
        }
    }

    if (findNegativeCycles(dist, noOfEdges, edges)) {
        printf("negative Cycle");
        return;
    } else {
        for (int i = 0; i < nrOfVertexes; i++) {
            int u = i;
            if (i != startNode) {
                while (prev[u] != UNDEFINED) {
                    push(u);
                    u = prev[u];
                }
                printf("Path %c to %c is: %c", startNode + 'A', i + 'A', startNode + 'A');
                while (!isEmptyStack()) {
                    printf(" -> %c", peekStack()->content + 'A');
                    pop();
                }
                printf(", cost %d\n", dist[i]);
            }
        }
    }
    printf("BellmanFord finish");
}