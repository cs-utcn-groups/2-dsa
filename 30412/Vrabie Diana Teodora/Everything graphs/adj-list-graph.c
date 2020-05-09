//
// Created by diana on 09/05/2020.
//

#include "adj-list-graph.h"

ListNode *createNewListNode(int key, int weight) {
    ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->key = key;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

AdjList *createAdjListArray(int nrOfElements) {
    AdjList *listArray = (AdjList*) malloc(nrOfElements* sizeof(AdjList));
    for (int i = 0; i < nrOfElements; ++i) {
        listArray[i].head = NULL;
    }
    return listArray;
}

Graph *createNewGraph(int nrOfVertices) {
    Graph *newGraph = (Graph*) malloc(sizeof(Graph));
    newGraph->nrOfVertices = nrOfVertices;
    newGraph->nodesArray = createAdjListArray(nrOfVertices);
    return newGraph;
}

void addEdgeToGraph(Graph *graph, int source, int destination, int weight) {
    ListNode *newNode = createNewListNode(destination, weight);
    newNode->next = graph->nodesArray[source].head;
    graph->nodesArray[source].head = newNode;
}

void printGraph(Graph *graph, struct _iobuf *buffer) {
    for (int i = 0; i < graph->nrOfVertices; ++i) {
        fprintf(buffer, "Node %d: ", i);
        ListNode *crawl = graph->nodesArray[i].head;
        while (crawl != NULL) {
            fprintf(buffer, "(-> %d [%d])", crawl->key, crawl->weight);
            crawl = crawl->next;
        }
        fprintf(buffer, "\n");
    }
}

void freeGraph(Graph **graph) {
    for (int i = 0; i < (*graph)->nrOfVertices; ++i) {
        ListNode *crawl = (*graph)->nodesArray[i].head;
        while (crawl != NULL) {
            (*graph)->nodesArray[i].head = crawl->next;
            free(crawl);
            crawl = (*graph)->nodesArray[i].head;
        }
    }
    free((*graph)->nodesArray);
    free(*graph);
}


