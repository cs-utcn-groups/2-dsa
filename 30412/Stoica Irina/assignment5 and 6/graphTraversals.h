//
// Created by Irina on 18/05/2020.
//

#ifndef ASSIGNMENT5_GRAPHTRAVERSALS_H
#define ASSIGNMENT5_GRAPHTRAVERSALS_H

#include "graph.h"

void bfs(int startNode);

void dfs(int startNode);

void bfs_list(int startNode, NodeT ** listArray);

void dfs_list(int startNode, NodeT ** listArray);

void dfsRecurs(int startNode);

void kruskal();

void bellman_Ford(int startNode);

#endif //ASSIGNMENT5_GRAPHTRAVERSALS_H
