//
// Created by diana on 09/05/2020.
//

#include "graph-traversals.h"

void fillVisited(int nrOfElements) {
    visited = (bool *) malloc(nrOfElements * sizeof(bool));
    for (int i = 0; i < nrOfElements; ++i) {
        visited[i] = false;
    }
}

void doMatrixDFS(AdjMatrix *adjMatrix, int startVertex, struct _iobuf *buffer) {
    fprintf(buffer, "%d ", startVertex);
    visited[startVertex] = true;
    for (int i = 0; i < adjMatrix->nrOfVertices; ++i) {
        if (adjMatrix->matrix[startVertex][i] != 0 && (!visited[i])) {
            doMatrixDFS(adjMatrix, i, buffer);
        }
    }
}

void matrixDFS(AdjMatrix *adjMatrix, int startVertex, struct _iobuf *buffer) {
    fprintf(buffer, "DFS on adjacency matrix:\n");
    fillVisited(adjMatrix->nrOfVertices);
    doMatrixDFS(adjMatrix, startVertex, buffer);
}