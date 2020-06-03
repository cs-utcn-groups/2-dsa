//
// Created by Irina on 20/05/2020.
//

#ifndef ASSIGNMENT5_LIST_OPERATIONS_H
#define ASSIGNMENT5_LIST_OPERATIONS_H
#include "graph.h"

void listToMatrix(NodeT ** listArray);

NodeT ** matrixToList(NodeT ** listArray);

void printList(NodeT ** listArray);

void printMatrix();

int getNumberOfNeighborsOfVertexList(int v, NodeT ** listArray);

int *getAllNeighborsOfVertexList(int v, NodeT ** listArray);

#endif //ASSIGNMENT5_LIST_OPERATIONS_H
