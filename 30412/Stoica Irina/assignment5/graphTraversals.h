//
// Created by Irina on 18/05/2020.
//

#ifndef ASSIGNMENT5_GRAPHTRAVERSALS_H
#define ASSIGNMENT5_GRAPHTRAVERSALS_H

#include "graph.h"

void bfs(int startNode);

void dfs(int startNode);

void dfsRecurs(int startNode);

void listToMatrix(NodeT ** listArray);

void bfs_list(int startNode, NodeT ** listArray);

void dfs_list(int startNode, NodeT ** listArray);

#endif //ASSIGNMENT5_GRAPHTRAVERSALS_H
