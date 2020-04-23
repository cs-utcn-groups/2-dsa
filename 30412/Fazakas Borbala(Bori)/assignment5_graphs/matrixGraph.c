//
// Created by Bori on 4/2/2020.
//

#include "matrixGraph.h"
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

static void allocateMatrix(mGraph *myGraph) {
    myGraph->edges = (int **) malloc(sizeof(int *) * (myGraph->noNodes + 1));
    for (int i = 1; i <= myGraph->noNodes; i++) {
        myGraph->edges[i] = (int *) malloc(sizeof(int) * (myGraph->noNodes + 1));
    }
}


mGraph createMGraph_fromFile(FILE *inFile) {
    mGraph newGraph;
    fscanf(inFile, "%d", &newGraph.noNodes);
    allocateMatrix(&newGraph);
    for (int i = 1; i <= newGraph.noNodes; i++) {
        for (int j = 1; j <= newGraph.noNodes; j++) {
            fscanf(inFile, "%d", &newGraph.edges[i][j]);
        }
    }
    return newGraph;
}

void printAdjMatrix(mGraph *myGraph, FILE *outFile) {
    fprintf(outFile, "The adjacency matrix of the graph is: \n");
    for (int i = 1; i <= myGraph->noNodes; i++) {
        for (int j = 1; j <= myGraph->noNodes; j++) {
            fprintf(outFile, "%3d ", myGraph->edges[i][j]);
        }
        fprintf(outFile, "\n");
    }
}

static void dfs_helper(mGraph *myGraph, int node, FILE *outFile, bool *visited) {
    fprintf(outFile, "%d ", node);
    visited[node] = true;
    for (int i = 1; i <= myGraph->noNodes; i++) {
        if (!visited[i] && myGraph->edges[node][i] > 0) {
            dfs_helper(myGraph, i, outFile, visited);
        }
    }
}

bool *getVisitedArray(mGraph *myGraph) {
    bool *visited = (bool *) malloc(sizeof(bool) * (myGraph->noNodes + 1));
    for (int i = 1; i < myGraph->noNodes; i++) {
        visited[i] = false;
    }
    return visited;
}

void dfs(mGraph *myGraph, FILE *outFile, FILE *inFile) {
    fprintf(outFile, "Which is the root of the dfs tree?");
    int root;
    fscanf(inFile, "%d", &root);
    fprintf(outFile, "DFS of the graph is: \n");
    bool *visited = getVisitedArray(myGraph);
    dfs_helper(myGraph, root, outFile, visited);
    fprintf(outFile, "\n");
}

void bfs(mGraph *myGraph, FILE *outFile, FILE *inFile) {
    fprintf(outFile, "Which is the root of the bfs tree?");
    int root;
    fscanf(inFile, "%d", &root);
    fprintf(outFile, "BFS of the graph is: \n");
    bool *visited = getVisitedArray(myGraph);
    Queue bfsQueue = createQueue();
    enqueue(&bfsQueue, root);
    visited[root] = true;
    int frontNode;
    while (!isEmpty(&bfsQueue)) {
        frontNode = dequeue(&bfsQueue);
        fprintf(outFile, "%d ", frontNode);
        for (int i = 1; i <= myGraph->noNodes; i++) {
            if (!visited[i] && myGraph->edges[frontNode][i] > 0) {
                enqueue(&bfsQueue, i);
                visited[i] = true;
            }
        }
    }
    fprintf(outFile, "\n");
}
