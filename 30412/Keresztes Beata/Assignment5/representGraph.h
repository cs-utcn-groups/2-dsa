//
// Created by q on 4/1/2020.
//

#ifndef ASSIGNMENT5_REPRESENTGRAPH_H
#define ASSIGNMENT5_REPRESENTGRAPH_H

#include "list.h"
#include "matrix.h"

// function to convert adjacency matrix into adjacency array of lists
ListT * convertMatrixToList(int N, int ** A);
// function to convert adjacency list back into adjacency array
int ** convertListToMatrix(int N, ListT * AL);
#endif //ASSIGNMENT5_REPRESENTGRAPH_H
