//
// Created by diana on 10/05/2020.
//

#include "bellman-ford.h"

void bellmanFord(Graph *graph, int src) {
    int nrOfVertices = graph->nrOfVertices;
    int nrOfEdges = 7;  // nr of edges
    int dist[nrOfVertices];

    for (int i = 0; i < nrOfVertices; i++)
        dist[i] = 9999;
    dist[src] = 0;

    for (int i = 1; i <= nrOfVertices - 1; i++) {
        for (int j = 0; j < nrOfEdges; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (dist[u] != 9999 && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < nrOfEdges; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (dist[u] != 9999 && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply return
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < nrOfVertices; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}