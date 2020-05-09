//
// Created by diana on 08/05/2020.
//

#include "graph.h"

int **createEmptyMatrix(int size) {
    int **newMatrix = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; ++i) {
        newMatrix[i] = (int *) malloc(size * sizeof(int));
    }
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            newMatrix[i][j] = 0;
        }
    }
    return newMatrix;
}

void readAdjMatrix(FILE *inputFile, int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            fscanf(inputFile, "%d", &matrix[i][j]);
        }
    }
}

Node *newListNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Graph *createEmptyGraph(int nrOfVertices) {
    Graph *newGraph = (Graph *) malloc(sizeof(Graph));
    newGraph->nrOfVertices = nrOfVertices;

    newGraph->vertexArray = (List *) malloc(nrOfVertices * sizeof(List));

    for (int i = 0; i < nrOfVertices; ++i) {
        newGraph->vertexArray[i].first = NULL;
    }

    return newGraph;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->nrOfVertices; ++i) {
        Node *node = graph->vertexArray[i].first;
        printf("Node %d: ", i);
        while (node != NULL) {
            printf("(%d) ", node->value);
            node = node->next;
        }
        printf("\n");
    }
}

void addEdge(Graph *graph, int head, int tail) {
    Node *newNode = newListNode(tail);
    // add new node to front of list for node head
    newNode->next = graph->vertexArray[head].first;
    graph->vertexArray[head].first = newNode;
}

Graph *createAdjListFromMatrix(int **matrix, int size) {
    Graph *newGraph = createEmptyGraph(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] != 0) {
                addEdge(newGraph, i, j);
            }
        }
    }
    return newGraph;
}

List *getLongestPath(Graph *graph) {
    return NULL;
}
