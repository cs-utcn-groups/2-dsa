//
// Created by Bori on 4/2/2020.
//

#ifndef ASSIGNMENT5_GRAPHS_MATRIXGRAPH_H
#define ASSIGNMENT5_GRAPHS_MATRIXGRAPH_H

#include <stdio.h>

typedef struct {
    int noNodes;
    int **edges;
} mGraph;

mGraph createMGraph_fromFile(FILE *inFile);

mGraph createMGaph_fromAdjList();

void printAdjMatrix(mGraph *myGraph, FILE *outFile);

void dfs(mGraph *myGraph, FILE *outFile, FILE *inFile);

void bfs(mGraph *myGraph, FILE *outFile, FILE *inFile);

#endif //ASSIGNMENT5_GRAPHS_MATRIXGRAPH_H
