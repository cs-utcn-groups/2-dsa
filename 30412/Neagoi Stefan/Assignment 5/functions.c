//
// Created by Stefan on 07/04/2020.
//
#include "header.h"

void readAdjMatrix(FILE *f) {
    int n;
    fscanf(f, "%d", &n);
    noOfVertices = n;
    int i, j;
    adjMatrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        *(adjMatrix + i) = (int *) malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    fclose(f);
}


void printAdjMatrix() {
    int i, j;
    printf("    ");
    for (i = 0; i < noOfVertices; i++)
        printf("%c   ", 'A' + i);
    printf("\n");
    for (i = 0; i < noOfVertices; i++){
        printf("%c ", 'A' + i);
            for(j = 0; j < noOfVertices; j++)
                printf("%3d ", adjMatrix[i][j]);
            printf("\n");
    }
}

NodeT *createNewNode(int dest, int length) {
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->length = length;
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

GraphT *createNewGraph(int V) {
    GraphT* graph = (GraphT*) malloc(sizeof(GraphT));
    graph->noVertices = noOfVertices;
    graph->noEdges = getNoEdges();
    graph->array = (AdjListT*) malloc(V * sizeof(AdjListT));
    graph->edge = (NodeT*)malloc(getNoEdges() * sizeof(NodeT));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(GraphT* graph, int src, int dest, int length) {

    graph->edge[edgeIndex].source = src;
    graph->edge[edgeIndex].dest = dest;
    graph->edge[edgeIndex].length = adjMatrix[src][dest];

    NodeT* newNode = createNewNode(dest, length);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;




    newNode = createNewNode(src, length);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;

    edgeIndex++;
}

void printGraph(GraphT* graph) {
    int v;
    for (v = 0; v < graph->noVertices; ++v)
    {
        NodeT* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %c\n head ", 'A' + v);
        while (pCrawl)
        {
            printf("-> %c (%d) ", 'A' + pCrawl->dest, pCrawl->length);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

GraphT* getGraphFromMatrix() {
    int i, j;
    GraphT* graph = createNewGraph(noOfVertices);
    for (i = 0; i < noOfVertices; i++)
        for(j = 0; j < noOfVertices; j++)
            if(adjMatrix[i][j] != 0)
                addEdge(graph, i, j, adjMatrix[i][j]);
    return graph;
}

int findSubset(SubsetT subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = findSubset(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(SubsetT subsets[], int x, int y) {
    int xRoot = findSubset(subsets, x);
    int yRoot = findSubset(subsets, y);

    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;

        // If ranks are same, then make one as root and
        // increment its rank by one
    else
    {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

int getNoEdges() {
    int i = 0;
    int j = 0;
    int noEdges = 0;
    for(i = 0; i < noOfVertices; i++){
        j = 0;
        while(j < i) {
            if (adjMatrix[i][j] != 0)
                noEdges++;
            j++;
        }
    }
    return noEdges;
}

int compareEdges(const void* a, const void* b) {
    NodeT* a1 = (NodeT*)a;
    NodeT* b1 = (NodeT*)b;
    return a1->length > b1->length;
}

void sortEdges(GraphT* graph) {
    for (int i = 0; i < graph->noEdges; i++)
        for(int j = 0; j < graph->noEdges; j++)
            if (graph->edge[j].length > graph->edge[i].length ) {
                NodeT temp = graph->edge[i];
                graph->edge[i] = graph->edge[j];
                graph->edge[j] = temp;
            }
}

void printEdges(GraphT *graph) {
    for (int i = 0; i < graph->noEdges; i++)
        printf ("%d ", graph->edge[i].length);
}

void KruskalMST (GraphT *graph) {
    int V = graph->noVertices;
    NodeT result[V];
    int e = 0;
    for (int i = 0; i < graph->noEdges; i++)
        for(int j = 0; j < graph->noEdges; j++)
            if (graph->edge[j].length > graph->edge[i].length ) {
                NodeT temp = graph->edge[i];
                graph->edge[i] = graph->edge[j];
                graph->edge[j] = temp;
            }
    SubsetT *subsets = (SubsetT*) malloc( V * sizeof(SubsetT) );
    sortEdges(graph);
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int i = 0;
    while (e < V - 1 && i < graph->noEdges) {

        NodeT next_edge = graph->edge[i++];
        int x = findSubset(subsets, next_edge.source);
        int y = findSubset(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("(Kruskal) The edges in the constructed MST:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].source, result[i].dest,
               result[i].length);
    return;
}

void printArr(int dist[], int n) {
    printf("(Bellman Ford) Shortest distance from source:\n");
    for (int i = 0; i < n; ++i)
        if(dist[i] != INT_MAX)
        printf("%d \t\t %d\n", i, dist[i]);
        else
        printf("%d \t\t %s\n", i, "infinite");
}

void BellmanFord(GraphT* graph, int src) {
    int V = graph->noVertices;
    int E = graph->noEdges;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].length;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].length;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return;
        }
    }

    printArr(dist, V);

    return;
}

