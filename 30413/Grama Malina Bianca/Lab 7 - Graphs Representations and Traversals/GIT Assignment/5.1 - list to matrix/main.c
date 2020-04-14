#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxStrLen 20

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
    struct AdjListNode *newNode = (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V) {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
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

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

int **formAdjMatrix(struct Graph *graph) {

    int **adjMatrix = (int **) malloc(sizeof(int *) * graph->V);
    for (int i = 0; i < graph->V; i++) {
        adjMatrix[i] = (int *) malloc(sizeof(int) * graph->V);
    }

    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode *pCrawl = graph->array[v].head;
        while (pCrawl) {
            adjMatrix[v][pCrawl->dest] = 1;
            pCrawl = pCrawl->next;
        }
    }
    return adjMatrix;
}

void printMatrix (int nrOfVertices, int **matrix)
{
    for (int i = 0; i < nrOfVertices; i++) {
        for (int j = 0; j < nrOfVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void readAndPrint(FILE *f)
{
    int nrOfVertices = 5;
    struct Graph *graph = createGraph(nrOfVertices);

    char *buffer = (char *) malloc(sizeof(char) * maxStrLen);
    while (fgets(buffer, maxStrLen, f) != NULL) {
        char *pch = strtok(buffer + 2, " ");
        int source = atoi(&buffer[0]);
        while (pch != NULL) {
            int destination = atoi(pch);
            addEdge(graph, source, destination);
            pch = strtok(NULL, " ");
        }
    }

    int **matrix = formAdjMatrix(graph);
    printMatrix(nrOfVertices,matrix);
}

int main() {
    FILE *f;
    f = fopen("input.txt", "r");
    readAndPrint(f);
    fclose(f);
    return 0;
}

