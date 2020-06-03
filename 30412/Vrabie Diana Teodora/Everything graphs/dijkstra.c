//
// Created by diana on 11/05/2020.
//

#include "dijkstra.h"

int getMinDistanceVertex(Graph *graph, int *distances) {
    int min = 9999;
    int minVertex = 0;
    for (int i = 0; i < graph->nrOfVertices; ++i) {
        if (distances[i] < min && !visited[i]) {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(Graph *graph, int startNode, struct _iobuf *buffer) { // Shortest path algorithm
    fprintf(buffer, "\nDijkstra's Algorithm:\n");

    int *distances = (int *) malloc(graph->nrOfVertices * sizeof(int));
    int *previous = (int *) malloc(graph->nrOfVertices * sizeof(int));

    int nrOfVisitedVertices = 0;

    for (int i = 0; i < graph->nrOfVertices; ++i) {
        distances[i] = 9999; // max val
        previous[i] = -1; // undefined
    }

    fillVisited(graph->nrOfVertices);
    distances[startNode] = 0;

    while (nrOfVisitedVertices < graph->nrOfVertices) {
        int u = getMinDistanceVertex(graph, distances);
        visited[u] = true;

        ListNode *crawl = graph->nodesArray[u].head;
        while (crawl != NULL) {
            int currentDistance = distances[u] + crawl->weight;
            if (currentDistance < distances[crawl->key]) {
                distances[crawl->key] = currentDistance;
                previous[crawl->key] = u;
            }
            crawl = crawl->next;
        }

        nrOfVisitedVertices++;
    }

    Stack *stack = initializeStack();

    for (int j = 0; j < graph->nrOfVertices; ++j) {
        int u = j;
        if (j != startNode) {
            while (previous[u] != -1) {
                push(u, stack);
                u = previous[u];
            }

            fprintf(buffer, "Shortest path from node %d to node %d is: %d", startNode, j, startNode);
            while (!isStackEmpty(stack)) {
                fprintf(buffer, " -> %d ", pop(stack)->value);
            }
            fprintf(buffer, "\n");
        }
    }
}
