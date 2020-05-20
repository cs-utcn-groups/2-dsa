#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node *next;
} NodeT;

typedef struct graph {
    int nrVertices;
    NodeT **adjList;
} GraphT;

NodeT *createNode(int v) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(GraphT *graph, int source, int destination) {
    NodeT *newNode = createNode(source);
    newNode->next = graph->adjList[destination];
    graph->adjList[destination]=newNode;
}

void matrixToList(int **Adj, GraphT *graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Adj[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
}

void listToMatrix(int **Adj, GraphT *graph, int n) {
    NodeT *temp = (NodeT *) malloc(sizeof(NodeT));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Adj[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        temp = graph->adjList[i + 1];
        while (temp != NULL) {
            Adj[i + 1][temp->vertex] = 1;
            temp = temp->next;
        }
    }
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
