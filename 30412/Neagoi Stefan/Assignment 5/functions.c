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
    graph->noVertices = V;
    graph->array = (AdjListT*) malloc(V * sizeof(AdjListT));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(GraphT* graph, int src, int data, int length) {

    NodeT* newNode = createNewNode(data, length);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNewNode(src, length);
    newNode->next = graph->array[data].head;
    graph->array[data].head = newNode;
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


