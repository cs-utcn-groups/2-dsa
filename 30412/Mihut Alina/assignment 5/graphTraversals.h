//
// Created by Alina Mihut on 4/6/20.
//

#ifndef ASSIGNMENT_5_GRAPHTRAVERSALS_H
//#include <stdio.h>
#include "graph.h"
#include "queue.h"
#include "stack.h"
#include "graphRepresentation.h"
#include "list.h"
void BFS(int startNode, List *l);
void DFS(int startNode, List *l);
void DFSRec(int v, int *visited,List *l);
void DFSRecurs(int startNode, List *l);

#define ASSIGNMENT_5_GRAPHTRAVERSALS_H

#endif //ASSIGNMENT_5_GRAPHTRAVERSALS_H
