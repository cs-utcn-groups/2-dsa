//
// Created by bindi on 4/7/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

graph *readGraph(FILE *input) {
    graph *myGraph = (graph *) malloc(sizeof(graph));
    int noOfVertices;
    fscanf(input, "%d", &noOfVertices);
    myGraph->noOfVertices = noOfVertices;
    myGraph->edges = (edge **) malloc(noOfVertices * (noOfVertices - 1) * sizeof(edge *));
    int noOfEdges = 0;
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            int weight = 0;
            fscanf(input, "%d", &weight);
            if (weight != 0) {

                myGraph->edges[noOfEdges] = (edge *) malloc(sizeof(edge));
                myGraph->edges[noOfEdges]->source = i;
                myGraph->edges[noOfEdges]->destination = j;
                myGraph->edges[noOfEdges]->weight = weight;
                noOfEdges++;
            }
        }
    }
    myGraph->noOfEdges = noOfEdges;
    return myGraph;
}
