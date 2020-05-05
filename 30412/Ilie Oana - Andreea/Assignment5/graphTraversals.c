//
// Created by andre on 06.05.2020.
//

#include "graphTraversals.h"
#include "graphRepresentation.h"

void bfs(FILE *outputFile, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(outputFile, "BFS recursive started\n");
    int *visited = initializeArray(noOfVertices, UNVISITED);

    int v, w;

    Queue queue = createQueue();
    enqueue(&queue, startNode);
    visited[startNode] = VISITED;
    fprintf(outputFile, "%c ", startNode + 'A');

    while (!isEmptyQueue(&queue)) {
        v = queue.first->data;
        dequeue(&queue);

        int nrOfNeighbors = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, v);
        int *neighbors = getAllNeighboursOfVertex(noOfVertices, adjMatrix, v);
        for (int i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                fprintf(outputFile, "%c ", w + 'A');
                enqueue(&queue, w);
                visited[w] = VISITED;
            }
        }
    }
    fprintf(outputFile, "\nBFS ended\n\n");
}

void dfs(FILE *outputFile, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(outputFile, "DFS started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }
    int v, w;
    push(startNode);
    while (!isEmptyStack()) {
        v = peekStack()->data;
        pop();
        if (visited[v] == UNVISITED) {
            visited[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, v);
            int *neighbors = getAllNeighboursOfVertex(noOfVertices, adjMatrix, v);
            for (int i = nrOfNeighbors - 1; i >= 0; i--) {
                w = neighbors[i];
                if (visited[w] == UNVISITED) {
                    push(w);
                }
            }
            fprintf(outputFile, "%c ", v + 'A');
        }
    }
    fprintf(outputFile, "\nDFS ended\n\n");
}

void dfsRec(FILE *outputFile, int v, int *visited, int noOfVertices, int **adjMatrix) {
    visited[v] = VISITED;
    int nrOfNeighbors = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, v);
    int *neighbors = getAllNeighboursOfVertex(noOfVertices, adjMatrix, v);
    fprintf(outputFile, "%c ", v + 'A');
    for (int i = 0; i < nrOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == UNVISITED) {
            dfsRec(outputFile, w, visited, noOfVertices, adjMatrix);
        }
    }
}

void dfsRecursive(FILE *outputFile, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(outputFile, "DFS recursive started\n");
    int *visited = initializeArray(noOfVertices, UNVISITED);
    dfsRec(outputFile, startNode, visited, noOfVertices, adjMatrix);
    fprintf(outputFile, "\nDFS recursive ended\n\n");
}

int *initializeArray(int noOfVertices, int value) {
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++) {
        visited[i] = value;
    }
    return visited;
}
