//
// Created by Diana on 4/11/2020.
//

#include <stdio.h>
#include "stdlib.h"
#include "head.h"
#include "queue.h"

#define UNVISITED 0
#define VISITED 1
void bfsList(int startNode){
    printf("BFS list started\n");
    int *visited = (int *) malloc(nrOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertices; i++) {
        visited[i] = UNVISITED;
    }

    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode+ 'A');

    while (!isEmptyQueue()) {
        v = peekQueue()->vertex;
        currVertex[v] = firstVertex[v];
        dequeue();

        while(currVertex[v] != NULL)
        {
            w = currVertex[v]->vertex;
            if(visited[w] == UNVISITED)
            {
                printf("%c ", w +'A');
                enqueue(w);
                visited[w] = VISITED;
            }
            currVertex[v] = currVertex[v]->next;
        }
        currVertex[v] = firstVertex[v];
    }

    printf("\nBFS list ended\n\n");
}
void dfsRecList(int v, int *visited) {
    visited[v] = VISITED;
    printf("%c ", v + 'A');
    while(currVertex[v] != NULL)
    {
        int w = currVertex[v]->vertex;
        if (visited[w] == UNVISITED) {
            dfsRecList(w, visited);
        }
        currVertex[v] = currVertex[v]->next;
    }
}
void dfsRecursList(int startNode) {
    printf("DFS recursive started\n");
    int *visited = (int *) malloc(nrOfVertices * sizeof(int));
    int i;

    for (i = 0; i < nrOfVertices; i++) {
        visited[i] = UNVISITED;
    }
    dfsRecList(startNode, visited);
    printf("\nDFS recursive ended\n\n");
}