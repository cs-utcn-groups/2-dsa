#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct edge {

    int node1, node2, cost;

}edgeT;

typedef struct Graph {

    int nrOfVert, nrOfEdges;

    edgeT* edge;

}GraphT;

GraphT* createGraph(int V, int E) {

    GraphT* graph = (GraphT*)malloc(sizeof(GraphT));
    graph->nrOfEdges = E;
    graph->nrOfVert = V;
    graph->edge = (edgeT*)malloc(sizeof(edgeT) * E);
    return graph;

}

void read(int E, GraphT* graph, FILE* in) {

    for(int i = 0; i < E; i++)
        fscanf(in, "%d %d %d", &graph->edge[i].node1, &graph->edge[i].node2, &graph->edge[i].cost);

}

void bellmanFord(GraphT* graph, int startNode) {

    int V = graph->nrOfVert;
    int E = graph->nrOfEdges;
    int* dist = (int*)malloc(4  * V);

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[startNode] = 0;

    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < E; j++) {

            int source = graph->edge[j].node1;
            int dest = graph->edge[j].node2;
            int cost = graph->edge[j].cost;

            if(dist[source] != INT_MAX && (dist[source] + cost < dist[dest]))
                dist[dest] = cost + dist[source];

        }
    }

    for(int i = 0; i < V; ++i)
        printf("%d ", dist[i]);
}

int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "r");
    int V, E;
    fscanf(in, "%d %d", &V, &E);

    GraphT* graph = createGraph(V, E);
    read(E, graph, in);
    bellmanFord(graph, 0);
    return 0;
}
