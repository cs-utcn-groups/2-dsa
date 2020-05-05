//
// Created by andre on 06.05.2020.
//

#ifndef ASSIGNMENT5_LONGESTPATH_H
#define ASSIGNMENT5_LONGESTPATH_H

#include "graphTraversals.h"
#include "list.h"

void longestPath(FILE *outputFile, ListT *adjList, int noOfVertices, int startNode, int destinationNode);

void longestPathRec(ListT *adjList, ListT *longestPath, ListT *currentPath, int startNode, int destinationNode,
                    int *visited);



#endif //ASSIGNMENT5_LONGESTPATH_H
