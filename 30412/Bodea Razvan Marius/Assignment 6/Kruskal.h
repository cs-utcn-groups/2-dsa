//
// Created by razvi on 4/7/2020.
//

#ifndef CODE_HERE_KRUSKAL_H

#include "graphRepresentation.h"
#include "edge.h"
#include "graph.h"
#include "stack.h"
#include "node.h"

edgeT getMinimumEdgeForAdjacencyMatrix(int **adjMat,int *parent);
int **getCopyOfAdjecencyMatrix();
int getParent(const int *parent, int i);
void uni(int *parent, int i, int j);
void kruskal(FILE *fout);
void order(int nr_muchii,edgeT *m);
int *initializeParentArray(int noOfVertices);

#define CODE_HERE_KRUSKAL_H

#endif //CODE_HERE_KRUSKAL_H
