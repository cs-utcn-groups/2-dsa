//
// Created by acer on 4/5/2020.
//

#include "algorithms.h"

void BFS(int startNode, List *adjList, int noOfVertices) {
    startNode--;
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;

    List *queue = (List *)malloc(sizeof(List));
    queue->first = queue->last = NULL;
    enqueue(queue, startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');

    while (queue->first != NULL) {
        v = dequeue(queue);

        int nrOfNeighbors = noOfNeighborsOfVertex(adjList, v);
        int *neighbors = getAllNeighborsOfVertex(adjList, v, nrOfNeighbors);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                printf("%c ", w + 'A');
                enqueue(queue, w);
                visited[w] = VISITED;
            }
        }
    }
    printf("\nBFS ended\n\n");
}
void DFSRecursion(int v, int *visited, List *adjList) {
    int i;
    visited[v] = VISITED;
    int nrOfNeighbors = noOfNeighborsOfVertex(adjList, v);
    int *neighbors = getAllNeighborsOfVertex(adjList, v, nrOfNeighbors);
    printf("%c ", v + 'A');
    for (i = 0; i < nrOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == UNVISITED)
            DFSRecursion(w, visited, adjList);

    }
}

void recursiveDFS(int startNode, List *adjList, int noOfVertices) {
    startNode--;
    printf("DFS recursive started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));

    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;

    DFSRecursion(startNode, visited, adjList);
    printf("\nDFS recursive ended\n\n");
}