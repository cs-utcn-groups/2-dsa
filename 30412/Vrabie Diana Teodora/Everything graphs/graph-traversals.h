//
// Created by diana on 09/05/2020.
//

#ifndef EVERYTHING_GRAPHS_GRAPH_TRAVERSALS_H
#define EVERYTHING_GRAPHS_GRAPH_TRAVERSALS_H

#include "queue.h"
#include "stack.h"
#include "adj-matrix.h"
#include "adj-list-graph.h"

bool *visited;

// recursive DFS for adjacency matrix representation
void matrixDFS(AdjMatrix *adjMatrix, int startVertex, struct _iobuf *buffer);

// recursive DFS for adjacency list representation
void listDFS(Graph *graph, int startVertex, struct _iobuf *buffer);

// iterative DFS for adjacency list representation
void iterativeListDFS(Graph *graph, int startVertex, struct _iobuf *buffer);

// BFS for adjacency matrix representation
void iterativeMatrixBFS (AdjMatrix *adjMatrix, int startVertex, struct _iobuf *buffer);

// iterative BFS for adjacency list representation
void iterativeListBFS(Graph *graph, int startVertex, struct _iobuf *buffer);


#endif //EVERYTHING_GRAPHS_GRAPH_TRAVERSALS_H
