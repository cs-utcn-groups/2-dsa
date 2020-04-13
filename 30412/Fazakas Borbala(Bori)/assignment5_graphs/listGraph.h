//
// Created by Bori on 4/3/2020.
//

#ifndef ASSIGNMENT5_GRAPHS_LISTGRAPH_H
#define ASSIGNMENT5_GRAPHS_LISTGRAPH_H

#include <stdio.h>
#include "list.h"
#include "matrixGraph.h"
#include "edge.h"

typedef struct {
    int noNodes;
    list *lists;
} lGraph;

lGraph createLGaph_fromAdjMatrix(mGraph *MGraph);

mGraph createMGaph_fromAdjList();

void printAdjLists(lGraph *myGraph, FILE *outFile);

void l_dfs(lGraph *myGraph, FILE *outFile, FILE *inFile);

void l_bfs(lGraph *myGraph, FILE *outFile, FILE *inFile);

list findLongestPath(lGraph *myGraph, int source, int dest);

void primsAlgorithm(lGraph *myGraph); //prints out the chosen edges

void dijkstraAlgorithm(lGraph *myGraph);

void BellmanFordAlgorithm(lGraph* myGraph);

#endif //ASSIGNMENT5_GRAPHS_LISTGRAPH_H
