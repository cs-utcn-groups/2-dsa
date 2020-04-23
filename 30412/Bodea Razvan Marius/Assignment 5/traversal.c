//
// Created by razvi on 4/6/2020.
//
#include "traversal.h"

void BFS(FILE *fptr, int startNode, int noOfVertices, int **adjMatrix) {
    List queue;
    initList(&queue);
    fprintf(fptr, "BFS on Matrix\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;
    enqueue(startNode, &queue);
    while (queue.first != NULL) {
        int v = dequeue(&queue);
        visited[v] = VISITED;
        fprintf(fptr, "%d(%c)", v,v+'A');
        int *neighbors = getNeighbors(v, adjMatrix, noOfVertices);
        for (int i = 0; i < getNoOfNeighbors(v, adjMatrix, noOfVertices); i++)
            if (visited[neighbors[i]] == UNVISITED) {
                enqueue(neighbors[i], &queue);
                visited[neighbors[i]] = VISITED;
            }
    }
    fprintf(fptr, "\n\n");
}

void recDFS(FILE *fptr, int *visited, int v, int **adjMatrix, int noOfVertices) {
    visited[v] = VISITED;
    fprintf(fptr, "%d(%c)", v,v+'A');
    int *neighbors = getNeighbors(v, adjMatrix, noOfVertices);
    for (int i = 0; i < getNoOfNeighbors(v, adjMatrix, noOfVertices); i++)
        if (visited[neighbors[i]] == UNVISITED) {
            visited[neighbors[i]] = VISITED;
            recDFS(fptr, visited, neighbors[i], adjMatrix, noOfVertices);
        }
}

void DFS(FILE *fptr, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(fptr, "DFS on Matrix\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;
    recDFS(fptr, visited, startNode, adjMatrix, noOfVertices);
    fprintf(fptr, "\n\n");
}


void BFSonList(FILE *fptr, int startNode, int noOfVertices, List *adjList) {
    List queue;
    initList(&queue);
    fprintf(fptr, "BFS on List\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;
    enqueue(startNode, &queue);
    while (queue.first != NULL) {
        int v = dequeue(&queue);
        visited[v] = VISITED;
        fprintf(fptr, "%d(%c)", v,v+'A');
        NodeT *currentNode = adjList[v].first;
        while (currentNode != NULL) {
            if (visited[currentNode->data] == UNVISITED) {
                visited[currentNode->data] = VISITED;
                enqueue(currentNode->data, &queue);
            }
            currentNode = currentNode->next;
        }
    }
    fprintf(fptr, "\n\n");
}

void recDFSonList(FILE *fptr, int *visited, int v, List *adjList) {
    visited[v] = VISITED;
    fprintf(fptr, "%d(%c)", v,v+'A');
    NodeT *currentNode = adjList[v].first;
    while (currentNode != NULL) {
        if (visited[currentNode->data] == UNVISITED) {
            visited[currentNode->data] = VISITED;
            recDFSonList(fptr, visited, currentNode->data, adjList);
        }
        currentNode = currentNode->next;
    }
}

void DFSonList(FILE *fptr, int startNode, int noOfVertices, List *adjList) {
    fprintf(fptr, "DFS on List\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;
    recDFSonList(fptr, visited, startNode, adjList);
    fprintf(fptr, "\n\n");
}

