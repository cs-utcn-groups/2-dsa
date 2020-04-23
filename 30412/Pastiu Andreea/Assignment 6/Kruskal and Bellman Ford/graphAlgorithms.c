//
// Created by Alex on 4/7/2020.
//

#include <limits.h>
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

edgeT** createEdgeArray(int *vertexCount)
{
    edgeT **result;
    result = (edgeT**) malloc(nrOfVertexes*nrOfVertexes * sizeof(edgeT*));
    (*vertexCount) = 0;
    for(int i = 0; i < nrOfVertexes; i++)
    {
        for(int j = i; j < nrOfVertexes; j++)
        {
            if(adjMatrix[i][j] != 0)
            {
                edgeT *vertex = (edgeT *) malloc(sizeof(edgeT));
                vertex->source = i;
                vertex->destination = j;
                vertex->weight = adjMatrix[i][j];
                result[(*vertexCount)++] = vertex;
            }
        }
    }
    return result;
}

edgeT** createEdgeArrayBF(int *vertexCount)
{
    edgeT **result;
    result = (edgeT**) malloc(nrOfVertexes*nrOfVertexes * sizeof(edgeT*));
    (*vertexCount) = 0;
    for(int i = 0; i < nrOfVertexes; i++)
    {
        for(int j = 0; j < nrOfVertexes; j++)
        {
            if(adjMatrix[i][j] != 0)
            {
                edgeT *vertex = (edgeT *) malloc(sizeof(edgeT));
                vertex->source = i;
                vertex->destination = j;
                vertex->weight = adjMatrix[i][j];
                result[(*vertexCount)++] = vertex;
            }
        }
    }
    return result;
}
int compareWeights(const void* a, const void* b)
{
    edgeT* a1 = (edgeT*)a;
    edgeT* b1 = (edgeT*)b;
    return a1->weight > b1->weight;
}

edgeT** sortWeights(edgeT **initialEdges, int initialEdgesNo)
{
    int done=0;
    while(done != 1)
    {
        done = 1;
        for (int i=0; i<initialEdgesNo - 1; i++)
        {
            if (initialEdges[i]->weight > initialEdges[i+1]->weight)
            {
                edgeT *temp = initialEdges[i];
                initialEdges[i] = initialEdges[i+1];
                initialEdges[i+1] = temp;
                done = 0;
            }
        }
    }
    return initialEdges;
}
int find(subsetT **subset, int i)
{
    if (subset[i]->parent == -1)
        return i;
    return find(subset, subset[i]->parent);
}

void Union(subsetT **subset, int x, int y)
{
    int xset = find(subset, x);
    int yset = find(subset, y);
    if(xset!=yset){
        subset[xset]->parent = yset;
    }
}

void kruskalMST()
{
    edgeT **result;
    result = (edgeT**) malloc(nrOfVertexes * sizeof(edgeT*));
    int e = 0;
    int i = 0;
    int initialEdgesNo;
    edgeT** initialEdges = createEdgeArray(&initialEdgesNo);

    initialEdges = sortWeights(initialEdges, initialEdgesNo);

    subsetT **subsets = (subsetT**) malloc( nrOfVertexes * sizeof(subsetT*) );

    for (int v = 0; v < nrOfVertexes; v++)
    {
        subsets[v] = (subsetT*) malloc((sizeof(subsetT*)));
        subsets[v]->parent = -1;
    }

    while (e < nrOfVertexes - 1 && i < initialEdgesNo)
    {
        edgeT *next_edge = initialEdges[i++];

        int x = find(subsets, next_edge->source);
        int y = find(subsets, next_edge->destination);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edges selected by Kruskal algorithm\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d weighted %d\n", result[i]->source, result[i]->destination, result[i]->weight);
}

void bellmanFord(int startVertex)
{
    int initialEdgesNo;
    edgeT **initialEdges = createEdgeArrayBF(&initialEdgesNo);
    int *distanceArr = (int *) malloc(nrOfVertexes * sizeof(int));

    for (int i = 0; i < nrOfVertexes; i++)
    {
        distanceArr[i] = INT_MAX;
    }
    distanceArr[startVertex] = 0;

    for (int i = 0; i < nrOfVertexes; i++)
    {
        for (int j = 0; j < initialEdgesNo; j++)
        {
            int u = initialEdges[j]->source;
            int v = initialEdges[j]->destination;
            int weight = initialEdges[j]->weight;
            if (distanceArr[u] != INT_MAX && distanceArr[u] + weight < distanceArr[v])
                distanceArr[v] = distanceArr[u] + weight;
        }
    }

    printf("Distance from source to every vertex: \n");
    for (int i = 0; i < nrOfVertexes; i++)
        printf("Vertex %d distance %d\n", i, distanceArr[i]);
}