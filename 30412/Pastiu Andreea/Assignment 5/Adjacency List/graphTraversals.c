//
// Created by Andreea on 4/7/2020.
//
#include "graphTraversals.h"
#define UNVISITED 0
#define VISITED 1

void bfs(int startNode, int nrOfVertexes, int **adjMatrix) {
    printf("BFS matrix started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }

    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%d ", startNode);

    while (!isEmptyQueue()) {
        v = peekQueue()->content;
        dequeue();

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v, nrOfVertexes, adjMatrix);
        int *neighbors = getAllNeighborsOfVertex(v, nrOfVertexes, adjMatrix);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                printf("%d ", w);
                enqueue(w);
                visited[w] = VISITED;
            }
        }
    }

    printf("\nBFS matrix ended\n\n");
}

void bfsList(int startNode, int nrOfVertexes, nodeT **adjList) {
    printf("BFS list started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }

    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%d ", startNode);

    while (!isEmptyQueue()) {
        v = peekQueue()->content;
        dequeue();

        while(adjList[v] != NULL)
        {
            w = adjList[v]->key;
            if(visited[w] == UNVISITED)
            {
                printf("%d ", w);
                enqueue(w);
                visited[w] = VISITED;
            }
            adjList[v] = adjList[v]->next;
        }
    }

    printf("\nBFS list ended\n\n");
}

void dfsRec(int v, int *visited, int nrOfVertexes, int **adjMatrix) {
    int i;
    visited[v] = VISITED;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(v, nrOfVertexes, adjMatrix);
    int *neighbors = getAllNeighborsOfVertex(v, nrOfVertexes, adjMatrix);
    printf("%d ", v);
    for (i = 0; i < nrOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == UNVISITED) {
            dfsRec(w, visited, nrOfVertexes, adjMatrix);
        }
    }
}

void dfsRecList(int v, int *visited, nodeT **adjList) {
    int i;
    visited[v] = VISITED;
    printf("%d ", v);
    while(adjList[v] != NULL)
    {
        int w = adjList[v]->key;
        if (visited[w] == UNVISITED) {
            dfsRecList(w, visited, adjList);
        }
        adjList[v] = adjList[v]->next;
    }
}

void dfsRecurs(int startNode, int nrOfVertexes, int **adjMatrix) {
    printf("DFS recursive matrix started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    dfsRec(startNode, visited, nrOfVertexes, adjMatrix);
    printf("\nDFS recursive matrix ended\n\n");
}

void dfsRecursList(int startNode, int nrOfVertexes, nodeT **adjList) {
    printf("DFS recursive list started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    dfsRecList(startNode, visited, adjList);
    printf("\nDFS recursive list ended\n\n");
}

int getNumberOfNeighborsOfVertex(int v, int nrOfVertexes, int **adjMatrix) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = 0;
        int i;
        for (i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    } else {
        return 0;
    }
}

int *getAllNeighborsOfVertex(int v, int nrOfVertexes, int **adjMatrix) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v, nrOfVertexes, adjMatrix);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int i, j = 0;
        for (i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                neighbors[j] = i;
                j++;
            }
        }
        return neighbors;
    } else {
        return NULL;
    }
}