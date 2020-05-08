//
// Created by diana on 08/05/2020.
//

#include "adj_list.h"

ListNode *newListNode(int value) {
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
} // create new listNode with given value

Graph *createEmptyGraph(int nrOfVertices) {
    Graph *newGraph = (Graph *) malloc(sizeof(Graph));
    newGraph->nrOfVertices = nrOfVertices;

    newGraph->vertexArray = (AdjList *) malloc(nrOfVertices * sizeof(AdjList));

    for (int i = 0; i < nrOfVertices; ++i) {
        newGraph->vertexArray[i].first = NULL;
    }

    return newGraph;
} // create a new empty Graph with given nrOfVertices

void addEdge(Graph *graph, int head, int tail) {
    ListNode *newNode = newListNode(tail);
    // add new node to front of list for node head
    newNode->next = graph->vertexArray[head].first;
    graph->vertexArray[head].first = newNode;

    /* since we make the transformation by traversing a whole matrix,
     * we don't need to add the new node in the list for both the
     * head and the tail; adding it only to the head will suffice
     */
} // add an edge to graph

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->nrOfVertices; ++i) {
        ListNode *node = graph->vertexArray[i].first;
        printf("Node %d: ", i);
        while (node != NULL) {
            printf("(%d) ", node->value);
            node = node->next;
        }
        printf("\n");
    }
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



