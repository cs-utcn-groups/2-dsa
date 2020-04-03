//
// Created by q on 4/3/2020.
//

#ifndef ASSIGNMENT5_LONGESTPATH_H
#define ASSIGNMENT5_LONGESTPATH_H

#include "stack.h"
#include "list.h"
#include "traversGraph.h"

// function to find the longest simple path between two nodes
void findLongestPath(int N, ListT * AL, int s, int d);
// recursive function to find the longest path
void findRec(ListT * AL, int s, int d, int * visited, ListT * path, ListT * longestPath);
// function to copy the contents of a list to another
void copyList(ListT * src, ListT * dest);

#endif //ASSIGNMENT5_LONGESTPATH_H
