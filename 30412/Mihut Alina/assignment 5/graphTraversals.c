//
// Created by Alina Mihut on 4/6/20.
//
#include "graphTraversals.h"



void BFS(int startNode, List *l) {
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
        v = peekQueue()->vertex;
        dequeue();

        //int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        //int *neighbors = getAllNeighborsOfVertex(v);
        int nrOfNeighbors=0;
        int *neighbors=(int*) malloc (nrOfVertexes*sizeof(int));
        NodeT *temp=l[v].first;
        i=0;
        while(temp)
        {
            neighbors[i]=temp->vertex;
            nrOfNeighbors++;
            temp=temp->next;
            i++;

        }
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

void DFS (int startNode, List *l) {
    printf("DFS started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }

    push(startNode);

    while (!isEmptyStack()) {
        v = peekStack()->vertex;
        pop();

        if (visited[v] == UNVISITED) {
            visited[v] = VISITED;
            int nrOfNeighbors=0;
            int *neighbors=(int*) malloc (nrOfVertexes*sizeof(int));
            NodeT *temp=l[v].first;
            i=0;
            while(temp)
            {
                neighbors[i]=temp->vertex;
                nrOfNeighbors++;
                temp=temp->next;
                i++;

            }
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

void DFSRec(int v, int *visited, List *l) {
    int i;
    visited[v] = VISITED;
    int nrOfNeighbors=0;
    int *neighbors=(int*) malloc (nrOfVertexes*sizeof(int));
    NodeT *temp=l[v].first;
    i=0;
    while(temp)
    {
        neighbors[i]=temp->vertex;
        nrOfNeighbors++;
        temp=temp->next;
        i++;

    }
    printf("%c ", v + 'A');
    for (i = 0; i < nrOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == UNVISITED) {
            DFSRec(w, visited, l);
        }
    }
}

void DFSRecurs(int startNode, List *l) {
    printf("DFS recursive started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i;

    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    DFSRec(startNode, visited, l);
    printf("\nDFS recursive ended\n\n");
}