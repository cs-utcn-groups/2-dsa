//
// Created by bindi on 4/2/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "graphTraversal.h"
#include "list.h"

int getNoOfNeighbors(int vertex) {
    int noOfNeighbors = 0;
    for (int j = 0; j < noOfVertices; ++j) {
        if (adjMatrix[vertex][j] != 0) {
            noOfNeighbors++;
        }
    }
    return noOfNeighbors;
}

int *getNeighbors(int vertex) {
    int noOfNeighbors = getNoOfNeighbors(vertex);
    int *neighbors = (int *) malloc(noOfNeighbors * sizeof(int));
    int k = 0;
    for (int j = 0; j < noOfVertices; ++j) {
        if (adjMatrix[vertex][j] != 0) {
            neighbors[k++] = j;
        }
    }
    return neighbors;
}

void checkBFS(int startNode) {
    printf("BFS traversal: ");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; ++i) {
        visited[i] = UNVISITED;
    }
    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');
    while (!isEmptyQueue()) {
        int currentVertex = peekQueue()->data;
        dequeue();

        int noOfNeighbors = getNoOfNeighbors(currentVertex);
        int *neighbors = getNeighbors(currentVertex);
        for (int i = 0; i < noOfNeighbors; ++i) {
            int currentNeighbor = neighbors[i];
            if (visited[currentNeighbor] == UNVISITED) {
                printf("%c ", currentNeighbor + 'A');
                enqueue(currentNeighbor);
                visited[currentNeighbor] = VISITED;
            }
        }
    }
    printf("\nEnd of BFS.\n\n");
}

void checkDFS(int startNode) {
    printf("DFS traversal: ");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; ++i) {
        visited[i] = UNVISITED;
    }
    push(startNode);

    while (!isEmptyStack()) {
        int currentVertex = peekStack()->data;
        pop();

        if (visited[currentVertex] == UNVISITED) {
            visited[currentVertex] = VISITED;
            int noOfNeighbors = getNoOfNeighbors(currentVertex);
            int *neighbors = getNeighbors(currentVertex);
            for (int i = noOfNeighbors - 1; i >= 0; i--) {
                int currentNeighbor = neighbors[i];
                if (visited[currentNeighbor] == UNVISITED) {
                    push(currentNeighbor);
                }
            }
            printf("%c ", currentVertex + 'A');
        }
    }
    printf("\nEnd of DFS.\n\n");
}