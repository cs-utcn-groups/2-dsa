//
// Created by q on 4/14/2020.
//

#ifndef ASSIGNMENT6_VERTEXCOVER_H
#define ASSIGNMENT6_VERTEXCOVER_H

#include "graphAlgorithms.h"
#include "verticesList.h"

// vertex cover algorithm
void vertexCover(int N, int ** A);
// vertex cover algorithm optimization
void vertexCoverOpt(int N, int ** A);
// return the degree of the node (nr of incident edges to that node)
int getDegreeOfNode(int N, int ** A, int node);
// return node with maximum degree
int getMaxDegree(int N, int ** A, int * visited);
// get the node with next highest degree, adjacent to the given node
int getNextMaxDegree(int N, int ** A, int * visited, int node);
// check if all edges in the graph were covered
int areAllEdgesCovered(int N, int ** A, int * visited);

#endif //ASSIGNMENT6_VERTEXCOVER_H
