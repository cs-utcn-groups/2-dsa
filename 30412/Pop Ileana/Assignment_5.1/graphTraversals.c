//
// Created by ileana on 4/5/2020.
//

#include "graphTraversals.h"


void bfs(int startNode)
{
    printf("BFS started\n");
    int *visited = (int *) malloc(nbOfNodes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nbOfNodes; i++) {
        visited[i] = UNVISITED;
    }
    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');

    while (!isEmptyQueue()) {
        v = peekQueue()->label;
        dequeue();

        NodeT * aux = adjList[v];
        while(aux!=NULL)
        {
            w=aux->label;
            if(visited[w]==UNVISITED)
            {
                printf("%c ", w + 'A');
                enqueue(w);
                visited[w] = VISITED;
            }
            aux=aux->next;
        }
    }

    printf("\nBFS ended\n\n");

}

void dfs(int startNode) {
    printf("DFS started\n");
    int *visited = (int *) malloc(nbOfNodes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nbOfNodes; i++) {
        visited[i] = UNVISITED;
    }

    push(startNode);
    visited[startNode]=VISITED;
    printf("%c ", startNode + 'A');

    while (!isEmptyStack()) {
        v = peekStack()->label;

        NodeT * aux = adjList[v];
        while (aux!=NULL) {
            if (visited[aux->label] == UNVISITED)
                break;
            aux=aux->next;
        }
        if(aux!=NULL)
        {
            w = aux->label;
            if(visited[w]==UNVISITED) {
                visited[w] = VISITED;
                printf("%c ", w + 'A');
                push(w);
            }
        }
        else
            pop();
    }

    printf("\nDFS ended\n\n");
}

void dfsRec(int v, int *visited) {
    visited[v] = VISITED;

    printf("%c ", v + 'A');

    NodeT * aux = adjList[v];
    while(aux!=NULL)
    {
        int w = aux->label;
        if (visited[w] == UNVISITED) {
            dfsRec(w, visited);
        }
        aux = aux->next;
    }

}

void dfsRecurs(int startNode) {
    printf("DFS recursive started\n");
    int *visited = (int *) malloc(nbOfNodes * sizeof(int));
    int i;

    for (i = 0; i < nbOfNodes; i++) {
        visited[i] = UNVISITED;
    }
    dfsRec(startNode, visited);
    printf("\nDFS recursive ended\n\n");
}