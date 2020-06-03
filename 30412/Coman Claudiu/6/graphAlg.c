#include <limits.h>
#include "graphAlg.h"
#include "graphRep.h"
#define MAX 999999
#define UNDEFINED -1

edgeT getMinimumEdgeForCurrentlyVisitedNodes( const int *visited);

void printEdges(edgeT *edges, int n);

void prim(int startNode)
{
    printf("Prim's Algorithm started\n");

    int nrVetexesVisited = 0, i ,minCost = 0;
    int *visited = (int *)malloc(nrOfVertexes * sizeof(int));

    for (i = 0 ; i<nrOfVertexes ; i++)
        visited[i] = UNVISITED;

    edgeT *edges = (edgeT *)malloc((nrOfVertexes - 1) * sizeof(edgeT));

    visited[startNode] = VISITED;

    while(nrVetexesVisited < nrOfVertexes)
    {
        edgeT minEdge = getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination] = VISITED;
        edges[nrVetexesVisited ++ ] = minEdge;
        minCost += minEdge.weight;
    }

    printEdges(edges, nrVetexesVisited);
    printf("Cost of MST by prim : %d \n", minCost);
    printf("Prim's ended \n \n");

}

void printEdges(edgeT *edges, int n)
{
    int i;
    for( i = 0; i < n ; i++)
        printf("%c -> %c \t",edges[i].source + 'A', edges[i].destination + 'A');

    printf("\n");
}

edgeT getMinimumEdgeForCurrentlyVisitedNodes(const int *visited) {
    edgeT minimumEdge;
    minimumEdge.weight = 99999999;

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
    int min = 999999999, i;
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

void print(int *dist, int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

edgeT *getEdges()
{
    int c=0;
    edgeT *edges = (edgeT *)malloc((nrOfVertexes * nrOfVertexes) * sizeof(edgeT));

    for( int i = 0 ; i< nrOfVertexes ; i++)
        for(int j = 0 ; j< nrOfVertexes ; j++)
            if(adjMatrix[i][j] > 0)
            {
                edges[c].source = i;
                edges[c].destination = j ;
                edges[c].weight = adjMatrix[i][j];
                c++;
            }
    return edges;
}

void bellamn(int startNode)
{
    int *dist = (int *)malloc(nrOfVertexes * sizeof(int));
    int nrOfEdges = getNumberOfEdges();
    edgeT *edges = getEdges();
    for(int i = 0 ; i< nrOfVertexes ; i++)
        dist[i] = INT_MAX;
    dist[startNode] = 0;

    for(int  i = 0 ; i < nrOfVertexes ; i++)
        for(int j = 0 ; j < nrOfEdges ; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    print(dist, nrOfVertexes);
}

int getNumberOfEdges() {
    int c=0;
    for(int i = 0 ; i < nrOfVertexes ;i++)
        for(int j = 0 ; j < nrOfVertexes ; j++)
            if(adjMatrix[i][j] > 0)
                c++;
    return c;
}

int myComp(const void* a, const void* b)
{
    struct edge* a1 = (struct edge*)a;
    struct edge* b1 = (struct edge*)b;
    return a1->weight > b1->weight;
}


void kruskal()
{
    printf("Kruskal's Algorithm started\n");
    edgeT *edges = getEdges();
    int c = getNumberOfEdges();

    qsort(edges, c-1, sizeof(edges[0]), myComp);
    for(int i = 0 ; i <c ;i++)
        printf("%c, %c, %d \n",edges[i].source + 'A', edges[i].destination + 'A', edges[i].weight);

}