//
// Created by razvi on 5/2/2020.
//

#ifndef CODE_HERE_BELLMANFORD_H
#include "graphRepresentation.h"
#include "edge.h"
#include "graph.h"
#include "stack.h"
#include "node.h"

int checkIfNegativeCycles(const int *distance, int noOfEdges, edgeT *edges);
void BellmanFord(int startNode,FILE *fout);
int getNoOfEdges(int noOfVertices);
#define CODE_HERE_BELLMANFORD_H

#endif //CODE_HERE_BELLMANFORD_H
