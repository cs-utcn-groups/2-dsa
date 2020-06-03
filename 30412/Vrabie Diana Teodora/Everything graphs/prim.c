//
// Created by diana on 10/05/2020.
//

#include "prim.h"

Edge getMinimumEdgeForCurrentlyVisitedNodes(Graph *graph) {
    Edge minimumEdge;
    minimumEdge.weight = 9999;

    for (int i = 0; i < graph->nrOfVertices; ++i) {
        ListNode *crawl = graph->nodesArray[i].head;
        while (crawl != NULL) {
            if (visited[i] && !visited[crawl->key] && crawl->weight > 0)
                if (crawl->weight < minimumEdge.weight) {
                    minimumEdge.source = i;
                    minimumEdge.destination = crawl->key;
                    minimumEdge.weight = crawl->weight;
                }
            crawl = crawl->next;
        }
        // also works for adjacency matrices here
    }

    return minimumEdge;
}

void prim(Graph *graph, int startNode, struct _iobuf *buffer) { // minimum spanning tree for a weighted undirected graph
    printf("\nPrim's Algorithm\n");

    int nrOfVisitedVertices = 0;
    int minCost = 0;
    fillVisited(graph->nrOfVertices);
    Edge *edges = createEdgesArray(graph->nrOfVertices - 1);

    visited[startNode] = true;

    while (nrOfVisitedVertices < graph->nrOfVertices - 1) {
        Edge minEdge = getMinimumEdgeForCurrentlyVisitedNodes(graph);
        visited[minEdge.destination] = true;
        edges[nrOfVisitedVertices] = minEdge;
        nrOfVisitedVertices++;
        minCost += minEdge.weight;
    }

    for (int i = 0; i < nrOfVisitedVertices; ++i) {
        fprintf(buffer, "%d -> %d\t", edges[i].source, edges[i].destination);
    }
    fprintf(buffer, "\n");
    fprintf(buffer, "Cost of minimum spanning tree is %d\n", minCost);
}
