//
// Created by Diana on 04/05/2020.
//

#include "graph.h"

 void bfs(int startNode) {
    printf("BFS started\n");

    int *visited = (int *) malloc (noOfVertices * sizeof(int));
    for(int i=0;i<noOfVertices;i++) {
        visited[i] = UNVISITED;
    }

    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');

    int v;
    while(!isEmptyQueue()) {
        v = peekQueue()->key;
        dequeue();

        int noOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = getAllNeighborsOfVertex(v);
        for(int i=0;i<noOfNeighbors;i++) {
            if(visited[neighbors[i]] == UNVISITED) {
                printf("%c ",neighbors[i] + 'A');
                visited[neighbors[i]] = VISITED;
                enqueue(neighbors[i]);
            }
        }
    }

    printf("\nBFS ended\n\n");
}

void dfs (int startNode) {
    printf("DFS started\n");
    int * visited = (int *) malloc (noOfVertices * sizeof(int));
    for(int i=0;i<noOfVertices;i++) {
        visited[i] = UNVISITED;
    }

    push(startNode);

    int v,w;
    while (!isEmptyStack()) {
        v = peekStack()->key;
        pop();

        if(visited[v] == UNVISITED) {
            visited[v] = VISITED;
            int noOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int * neighbors = getAllNeighborsOfVertex(v);
            for(int i=noOfNeighbors-1;i>=0;i--) {
                w = neighbors[i];
                if (visited[w] == UNVISITED) {
                    push(w);
                }
            }
            printf("%c ",v + 'A');
        }
    }
    printf("\nDFS ended\n\n");
}

void dfsRec(int v, int * visited) {
    visited[v] = VISITED;
    int noOfNeighbors = getNumberOfNeighborsOfVertex(v);
    int * neighbors = getAllNeighborsOfVertex(v);
    printf("%c ",v + 'A');
    for (int i=0; i<noOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == UNVISITED) {
            dfsRec(w, visited);
        }
    }

}
void dfsRecursive(int startNode) {
    printf("DFS recursive started\n");
    int * visited = (int *) malloc (noOfVertices * sizeof(int));
    for(int i=0; i<noOfVertices;i++) {
        visited[i] = UNVISITED;
    }
    dfsRec(startNode,visited);
    printf("\nDFS recursive ended\n\n");
}