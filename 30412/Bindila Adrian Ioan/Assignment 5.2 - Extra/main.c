#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define INPUT "../input.txt"
int maxLength = 0;
int *longestSimplePath;
int *currentPath;

void findLongestSimplePath(graph *myGraph);

void traverseFrom(vertex *startVertex, int length);

int main() {
    FILE *input = fopen(INPUT, "r");///read from an adjacency matrix for simplicity
    graph *myGraph = createGraph(input);
    findLongestSimplePath(myGraph);
    return 0;
}


void findLongestSimplePath(graph *myGraph) {
    longestSimplePath = (int *) malloc(myGraph->noOfVertices * sizeof(int));
    currentPath = (int *) malloc(myGraph->noOfVertices * sizeof(int));

    for (int i = 0; i < myGraph->noOfVertices; ++i) {
        traverseFrom(myGraph->vertices[i], 0);
    }
    printf("The longest simple path has the length %d:\n", maxLength);
    for (int i = 0; i < maxLength; ++i) {
        printf("%c ", longestSimplePath[i] + 'A');
    }
}

void traverseFrom(vertex *startVertex, int length) {
    startVertex->visited = VISITED;
    currentPath[length] = startVertex->id;
    for (int i = 0; i < startVertex->noOfNeighbors; ++i) {
        if (startVertex->neighbors[i]->visited == UNVISITED) {
            traverseFrom(startVertex->neighbors[i], length + 1);
        }
    }
    if (length > maxLength) {
        maxLength = length;
        for (int i = 0; i < length; ++i) {
            longestSimplePath[i] = currentPath[i];
        }
    }
    ///going back
    startVertex->visited = UNVISITED;
}