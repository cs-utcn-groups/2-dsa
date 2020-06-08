//
// Created by acer on 4/5/2020.
//

#ifndef ASSIGNMENT__5_1__ALGORITHMS_H
#define ASSIGNMENT__5_1__ALGORITHMS_H

#include "list.h"
#include "matrix.h"

#define VISITED 1
#define UNVISITED 0

void BFS(int startNode, List *adjList, int noOfVertices);
void DFSRecursion(int v, int *visited, List *adjList);
void recursiveDFS(int startNode, List *adjList, int noOfVertices);

#endif //ASSIGNMENT__5_1__ALGORITHMS_H
