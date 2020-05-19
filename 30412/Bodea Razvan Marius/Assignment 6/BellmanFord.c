/*
 Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph.
 The graph may contain negative weight edges.
 1) Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.
 2) Do following for each edge u-v
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
………………….dist[v] = dist[u] + weight of edge uv
 3)……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”
 */
#include "BellmanFord.h"

int checkIfNegativeCycles(const int *dist, int noOfEdges, edgeT *edges) {
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

int getNoOfEdges(int noOfVertices) {
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

void BellmanFord(int startNode, FILE *fout) {
    fprintf(fout,"BellmanFord algorithm started:\n");
    int noOfEdges = getNoOfEdges(nrOfVertexes);
    edgeT *edges = getEdges(nrOfVertexes,noOfEdges);
    int *prev = initializeArray(nrOfVertexes,UNDEFINED);    //UNDEFINED
    int *dist = initializeArray(nrOfVertexes,MAX);
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
    if (checkIfNegativeCycles(dist, noOfEdges, edges)) {
        fprintf(fout, "There is a negative Cycle");
        return;
    } else {
        for (int i = 0; i < nrOfVertexes; i++) {
            int u = i;
            if (i != startNode) {
                while (prev[u] != UNDEFINED) {
                    push(u);
                    u = prev[u];
                }
                fprintf(fout, "Path from %c to %c is: %c", startNode + 'A', i + 'A', startNode + 'A');
                while (!isEmptyStack()) {
                    fprintf(fout, " -> %c", peekStack()->content + 'A');
                    pop();
                }
                fprintf(fout, ", cost %d\n", dist[i]);
            }
        }
    }
    fprintf(fout,"BellmanFord algorithm ended");
}