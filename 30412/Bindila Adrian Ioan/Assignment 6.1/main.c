#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "graphAlgorithms.h"


#define INPUT "../input.txt"

int main() {
    FILE *input = fopen(INPUT, "r");
    graph *myGraph = readGraph(input);
    doKruskal(myGraph);
    doBellmanFord(myGraph, 'G' - 'A');
    fclose(input);
    return 0;
}
