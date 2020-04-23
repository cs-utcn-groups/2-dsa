//
// Created by bindi on 4/6/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "vertex.h"

graph *createGraph(FILE *input) {
    graph *newGraph = (graph *) malloc(sizeof(graph));
    fscanf(input, "%d", &newGraph->noOfVertices);
    newGraph->vertices = (vertex **) malloc(newGraph->noOfVertices * sizeof(vertex *));
    for (int i = 0; i < newGraph->noOfVertices; ++i) {
        ///each vertex has an id and a vector of pointers to its neighbors
        newGraph->vertices[i] = (vertex *) malloc(sizeof(vertex));
        newGraph->vertices[i]->id = i;
        newGraph->vertices[i]->neighbors = (vertex **) malloc(newGraph->noOfVertices * sizeof(vertex *));
    }
    for (int i = 0; i < newGraph->noOfVertices; ++i) {
        int noOfNeighbours = 0;
        for (int j = 0; j < newGraph->noOfVertices; ++j) {
            newGraph->vertices[i]->neighbors[j] = (vertex *) malloc(sizeof(vertex));
            int distance = 0;
            fscanf(input, "%d", &distance);

            if (distance != 0) {
                newGraph->vertices[i]->neighbors[noOfNeighbours] = newGraph->vertices[j];
                noOfNeighbours++;
            }
        }
        newGraph->vertices[i]->noOfNeighbors = noOfNeighbours;
        newGraph->vertices[i]->visited = UNVISITED;
    }
    return newGraph;
}