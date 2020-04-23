//
// Created by Anca on 4/6/2020.
//

#include "graphTraversals.h"
#include "graphRepresentation.h"

void BFS(int startNode) {
    printf("BFS using the adjacency matrix started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }

    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');

    while (!isEmptyQueue()) {
        v = peekQueue()->content;
        dequeue();

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = getAllNeighborsOfVertex(v);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                printf("%c ", w + 'A');
                enqueue(w);
                visited[w] = VISITED;
            }
        }
    }

    printf("\nBFS using the adjacency matrix ended\n\n");
}

void DFS(int startNode) {
    printf("DFS using the adjacency matrix started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }

    push(startNode);

    while (!isEmptyStack()) {
        v = peekStack()->content;
        pop();

        if (visited[v] == UNVISITED) {
            visited[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int *neighbors = getAllNeighborsOfVertex(v);
            for (i = nrOfNeighbors - 1; i >= 0; i--) {
                w = neighbors[i];
                if (visited[w] == UNVISITED) {
                    push(w);
                }
            }
            printf("%c ", v + 'A');
        }
    }

    printf("\nDFS using the adjacency matrix ended\n\n");
}


void BFSfromList(int startNode) {
    printf("BFS using the adjacency list started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }

    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');

    while (!isEmptyQueue()) {
        v = peekQueue()->content;
        dequeue();

        int nrOfNeighbors = getNumberOfNeighborsOfVertexFromList(v);
        int *neighbors = getAllNeighborsOfVertexFromList(v);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                printf("%c ", w + 'A');
                enqueue(w);
                visited[w] = VISITED;
            }
        }
    }

    printf("\nBFS using the adjacency list ended\n\n");
}

void DFSfromList(int startNode) {
    printf("DFS using the adjacency list started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }

    push(startNode);

    while (!isEmptyStack()) {
        v = peekStack()->content;
        pop();

        if (visited[v] == UNVISITED) {
            visited[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertexFromList(v);
            int *neighbors = getAllNeighborsOfVertexFromList(v);
            for (i = nrOfNeighbors - 1; i >= 0; i--) {
                w = neighbors[i];
                if (visited[w] == UNVISITED) {
                    push(w);
                }
            }
            printf("%c ", v + 'A');
        }
    }

    printf("\nDFS using the adjacency list ended\n\n");
}
