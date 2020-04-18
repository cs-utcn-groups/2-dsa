//
// Created by bindi on 4/7/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "graph.h"
#include "graphAlgorithms.h"

void doKruskal(graph *myGraph) {
    sortEdges(myGraph->edges, myGraph->noOfEdges);
    printf("Kruskal started:\n");
    printf("The edges in the MST are:\n");
    int totalCost = 0;
    int *parents = (int *) malloc(myGraph->noOfVertices * sizeof(int));
    for (int i = 0; i < myGraph->noOfVertices; ++i) {
        parents[i] = i;
    }
    for (int i = 0; i < myGraph->noOfEdges; i++) {
        if (parents[myGraph->edges[i]->source] != parents[myGraph->edges[i]->destination]) {
            ///make sure we aren't closing a cycle

            ///unite the subgraphs
            for (int j = 0; j < myGraph->noOfVertices; j++) {
                if (parents[j] == parents[myGraph->edges[i]->destination]) {
                    parents[j] = parents[myGraph->edges[i]->source];
                }
            }
            printf("%c---%c: %d\n", myGraph->edges[i]->source + 'A', myGraph->edges[i]->destination + 'A',
                   myGraph->edges[i]->weight);
            totalCost += myGraph->edges[i]->weight;
        }
    }
    printf("Total cost:%d\n", totalCost);
    printf("Kruskal ended.\n\n");
}

void sortEdges(edge **edgeArray, int noOfEdges) {
    for (int i = 0; i < noOfEdges - 1; ++i) {
        for (int j = i + 1; j < noOfEdges; ++j) {
            if (edgeArray[i]->weight > edgeArray[j]->weight) {
                edge *temp = edgeArray[i];
                edgeArray[i] = edgeArray[j];
                edgeArray[j] = temp;
            }
        }
    }
}

void doBellmanFord(graph *myGraph, int source) {
    printf("Bellman-Ford has commenced!\n");
    int *distance = (int *) malloc(myGraph->noOfVertices * sizeof(int));
    int *predecessor = (int *) malloc(myGraph->noOfVertices * sizeof(int));
    predecessor[source] = UNDEFINED;
    for (int i = 0; i < myGraph->noOfVertices; ++i) {
        distance[i] = INFINITY;
    }
    distance[source] = 0;
    for (int i = 0; i < myGraph->noOfVertices - 1; ++i) {

        for (int j = 0; j < myGraph->noOfEdges; ++j) {
            int edgeSource = myGraph->edges[j]->source;
            int edgeDestination = myGraph->edges[j]->destination;
            int edgeWeight = myGraph->edges[j]->weight;
            ///^^^variables for extra readability
            if (distance[edgeDestination] > distance[edgeSource] + edgeWeight && distance[edgeSource] != INFINITY) {
                distance[edgeDestination] = distance[edgeSource] + edgeWeight;
                predecessor[edgeDestination] = edgeSource;
            }
        }
    }
    for (int j = 0; j < myGraph->noOfEdges; ++j) {
        int edgeSource = myGraph->edges[j]->source;
        int edgeDestination = myGraph->edges[j]->destination;
        int edgeWeight = myGraph->edges[j]->weight;
        ///^^^variables for extra readability
        if (distance[edgeDestination] > distance[edgeSource] + edgeWeight) {
            printf("Graph has negative edges!\n");
        }
    }
    printf("Distance from %c:\n", source + 'A');
    for (int i = 0; i < myGraph->noOfVertices - 1; ++i) {
        if (i != source) {
            printf("to %c:%2d ", i + 'A', distance[i]);
        }
        int k = i;
        while (predecessor[k] != UNDEFINED) {
            push(predecessor[k]);
            k = predecessor[k];
        }
        printf("(");
        while (!isEmptyStack()) {
            printf("%c--", peekStack()->data + 'A');
            pop();
        }
        printf("%c)", i + 'A');
        printf("\n");
    }
    printf("Bellman-Ford has ended!\n");
}