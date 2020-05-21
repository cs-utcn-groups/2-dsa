//
// Created by Irina on 18/05/2020.
//
#include "graphTraversals.h"
#include "graphRepresentation.h"
#include "list operations.h"
#define VERY_LARGE_NUMBER 1000000

void bfs(int startNode) {
    printf("BFS started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
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

    printf("\nBFS ended\n\n");
}

void dfs(int startNode) {
    printf("DFS started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
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

    printf("\nDFS ended\n\n");
}

void dfsRec(int v, int *visited) {
    int i;
    visited[v] = VISITED;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
    int *neighbors = getAllNeighborsOfVertex(v);
    printf("%c ", v + 'A');
    for (i = 0; i < nrOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == UNVISITED) {
            dfsRec(w, visited);
        }
    }
}

void dfsRecurs(int startNode) {
    printf("DFS recursive started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    dfsRec(startNode, visited);
    printf("\nDFS recursive ended\n\n");
}

void bfs_list(int startNode, NodeT ** listArray){
    printf("BFS for the lists started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int v, w;
    for (int i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');
    while (!isEmptyQueue()) {
        v = peekQueue()->content;
        dequeue();

        int nrOfNeighbors = getNumberOfNeighborsOfVertexList(v, listArray);
        int *neighbors = getAllNeighborsOfVertexList(v, listArray);
        for (int i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                printf("%c ", w + 'A');
                enqueue(w);
                visited[w] = VISITED;
            }
        }
    }

    printf("\nBFS for the lists ended\n\n");
}

void dfs_list(int startNode, NodeT ** listArray) {
    printf("DFS for the lists started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }

    push(startNode);

    while (!isEmptyStack()) {
        v = peekStack()->content;
        pop();

        if (visited[v] == UNVISITED) {
            visited[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertexList(v, listArray);
            int *neighbors = getAllNeighborsOfVertexList(v, listArray);
            for (i = nrOfNeighbors - 1; i >= 0; i--) {
                w = neighbors[i];
                if (visited[w] == UNVISITED) {
                    push(w);
                }
            }
            printf("%c ", v + 'A');
        }
    }
    printf("\nDFS for the lists ended\n\n");
}

void kruskal(){
    int minimumGraphWeight = 0;
    printf("Kruskal started:\n");
    int *visited = (int*)malloc(nrOfVertexes * sizeof(int));
    for(int i=0; i<nrOfVertexes; i++){
        visited[i] = UNVISITED;
    }
    edgeT ** addedEdges = (edgeT**)malloc(nrOfVertexes-1 * sizeof(edgeT*));
    edgeT * minimumEdgeThatClosesGraph = (edgeT*)malloc(sizeof(edgeT));
    int last = 0;
    for(int i=0; i<nrOfEdges; i++){
        addedEdges[i] = (edgeT*)malloc(sizeof(edgeT));
    }
    addedEdges[0] = allEdges[0];
    int s = addedEdges[0]->source - 'A';
    int d = addedEdges[0]->destination - 'A';
    visited[s] = visited[d] = VISITED;
    int k=1;
    int nrOfAddedEdges = 1;
    for(int i=1; i<nrOfEdges; i++){
        s = allEdges[i]->source - 'A';
        d = allEdges[i]->destination - 'A';
        if(visited[s] == UNVISITED || visited[d] == UNVISITED){
            addedEdges[k] = allEdges[i];
            visited[s] = visited[d] = VISITED;
            k++;
            nrOfAddedEdges++;
        }
        else if(last == 0){
            minimumEdgeThatClosesGraph = allEdges[i];
            last++;
        }
    }
    addedEdges[k] = minimumEdgeThatClosesGraph;
    for(int i=0; i<nrOfVertexes-1; i++){
        printf("%c - %c    %d\n", addedEdges[i]->source, addedEdges[i]-> destination, addedEdges[i]->weight);
        minimumGraphWeight = minimumGraphWeight + addedEdges[i]->weight;
    }
    printf("Minimum weight of the graph: %d\nKruskal ended\n\n", minimumGraphWeight);
}

void bellman_Ford(int startNode){
    printf("Bellman Ford started\n");
    Graph * graph = createGraph();
    int * distance = (int*)malloc(nrOfVertexes*(sizeof(int)));
    for(int i=0; i<nrOfVertexes; i++){
        distance[i] = VERY_LARGE_NUMBER;
    }
    distance[startNode] = 0;
    for(int i=0; i<nrOfVertexes; i++) {
        for (int j = 0; j < nrOfEdges; j++) {
            if (graph->edges[j]->source - 'A' == i) {
                int dest = graph->edges[j]->destination - 'A';
                int src = graph->edges[j]->source - 'A';
                int weight = graph->edges[j]->weight;
                //printf("%c %c  %d\n", src + 'A', dest + 'A', weight);
                if (weight + distance[src] < distance[dest]) {
                    distance[dest] = distance[src] + weight;
                }
            }
        }
    }
    for(int i=0; i<nrOfVertexes; i++) {
        printf("%c - %d\n", i + 'A', distance[i]);
    }
    printf("Bellman Ford finished\n");
}
