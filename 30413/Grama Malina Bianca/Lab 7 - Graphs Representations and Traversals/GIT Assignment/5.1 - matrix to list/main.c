#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
    int dest;
    struct AdjListNode *next;
};

struct AdjList {
    struct AdjListNode *head;
};

struct Graph {
    int V;
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest) {
    struct AdjListNode *newNode =
            (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V) {
    struct Graph *graph =
            (struct Graph *) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList *) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph(struct Graph *graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf(" -> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void readAndPrint(FILE *f)
{
    int nrOfVertices = 5;

    int **adjMatrix = (int **) malloc(sizeof(int *) * nrOfVertices);
    for (int i = 0; i < nrOfVertices; i++) {
        adjMatrix[i] = (int *) malloc(sizeof(int) * nrOfVertices);
    }

    struct Graph *graph = createGraph(nrOfVertices);
    for (int i = 0; i < nrOfVertices; i++) {
        for (int j = 0; j < nrOfVertices; j++) {
            fscanf(f, "%d ", &adjMatrix[i][j]);
            if (adjMatrix[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }

    printGraph(graph);
}

int main() {
    FILE *f;
    f = fopen("input.txt", "r");
    readAndPrint(f);
    fclose(f);
    return 0;
}

