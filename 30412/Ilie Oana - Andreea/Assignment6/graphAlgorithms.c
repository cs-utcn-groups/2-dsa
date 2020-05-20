//
// Created by andre on 06.05.2020.
//

#include "graphAlgorithms.h"

void prim(FILE *output, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(output, "\nPrim's algorithm started\n");
    int noOfVerticesVisited = 0, minCost = 0;
    int *visited = initializeArray(noOfVertices, UNVISITED);
    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (noOfVertices - 1));
    visited[startNode] = VISITED;
    while (noOfVerticesVisited < noOfVertices - 1) {
        edgeT minEdge = getMinEdgeForCurrentlyVisitedNodes(visited, noOfVertices, adjMatrix);
        visited[minEdge.destination] = VISITED;
        edges[noOfVerticesVisited++] = minEdge;
        minCost += minEdge.weight;
    }
    printEdges(output, edges, noOfVerticesVisited);
    fprintf(output, "Cost of MST by Prim's algorithm: %d\n", minCost);
    fprintf(output, "Prim's algorithm ended \n\n");
}

edgeT getMinEdgeForCurrentlyVisitedNodes(const int *visited, int noOfVertices, int **adjMatrix) {
    edgeT minEdge;
    minEdge.weight = MAX_LIMIT;
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (visited[i] == VISITED && visited[j] == UNVISITED && adjMatrix[i][j] > 0) {
                if (adjMatrix[i][j] < minEdge.weight) {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMatrix[i][j];
                }
            }
        }
    }
    return minEdge;
}

void printEdges(FILE *output, edgeT *edges, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(output, "%c -> %c\t", edges[i].source + 'A', edges[i].destination + 'A');
    }
    fprintf(output, "\n");
}

void dijkstra(FILE *output, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(output, "Dijkstra's Algorithm started\n");
    int *distances = initializeArray(noOfVertices, MAX_LIMIT);
    int *previous = initializeArray(noOfVertices, UNDEFINED);
    int *visited = initializeArray(noOfVertices, UNVISITED);
    int nrOfVerticesVisited = 0, i;
    distances[startNode] = 0;
    while (nrOfVerticesVisited < noOfVertices) {
        int u = getMinDistanceVertex(noOfVertices, distances, visited);
        visited[u] = VISITED;
        int noOfNeighbours = getNumberOfNeighboursOfVertex(noOfVertices, adjMatrix, u);
        int *neighbours = getAllNeighboursOfVertex(noOfVertices, adjMatrix, u);
        for (i = 0; i < noOfNeighbours; i++) {
            int w = neighbours[i];
            int alt = distances[u] + adjMatrix[u][w];
            if (alt < distances[w]) {
                distances[w] = alt;
                previous[w] = u;
            }
        }
        nrOfVerticesVisited++;
    }
    printShortestPath(output, noOfVertices, startNode, previous, distances);
    fprintf(output, "Dijkstra's Algorithm ended\n");
}

int getMinDistanceVertex(int noOfVertices, const int *distances, const int *visited) {
    int min = MAX_LIMIT, i;
    int minV = 0;
    for (i = 0; i < noOfVertices; i++) {
        if (distances[i] <= min && visited[i] == UNVISITED) {
            min = distances[i];
            minV = i;
        }
    }
    return minV;
}


void kruskal(FILE *output, int noOfVertices, int **adjMatrix) {
    fprintf(output, "\nKruskal's algorithm started:\n");
    int **adjMat = getCopyOfAdjacencyMatrix(noOfVertices, adjMatrix);
    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (noOfVertices - 1));
    int *parent = initializeParentArray(noOfVertices);
    int minCost = 0, noOfEdges = 0;

    while (noOfEdges < noOfVertices - 1) {
        edgeT minEdge = getMinimumEdgeForAdjMatrix(noOfVertices, adjMat, parent);
        edges[noOfEdges++] = minEdge;
        unite(parent, minEdge.source, minEdge.destination);
        minCost += minEdge.weight;
    }
    printEdges(output, edges, noOfEdges);
    fprintf(output, "The cost of MST is: %d", minCost);
    fprintf(output, "\nKruskal's algorithm ended\n\n");
}

int *initializeParentArray(int noOfVertices) {
    int *parent = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++) {
        parent[i] = i;
    }
    return parent;
}

edgeT getMinimumEdgeForAdjMatrix(int noOfVertices, int **adjMat, int *parent) {
    edgeT minEdge;
    minEdge.weight = MAX_LIMIT;

    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (adjMat[i][j] < minEdge.weight && adjMat[i][j] != 0 && getParent(parent, i) != getParent(parent, j)) {
                minEdge.weight = adjMat[i][j];
                minEdge.source = i;
                minEdge.destination = j;
            }
        }
    }
    adjMat[minEdge.source][minEdge.destination] = 0;
    adjMat[minEdge.destination][minEdge.source] = 0;
    return minEdge;
}

int **getCopyOfAdjacencyMatrix(int noOfVertices, int **adjMatrix) {
    int i, j;
    int **copyAdjMatrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (i = 0; i < noOfVertices; i++) {
        *(copyAdjMatrix + i) = (int *) malloc(noOfVertices * sizeof(int));
        for (j = 0; j < noOfVertices; j++) {
            copyAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
    return copyAdjMatrix;
}

int getParent(const int *parent, int vertex) {
    while (parent[vertex] != vertex) {
        vertex = parent[vertex];
    }
    return vertex;
}

void unite(int *parent, int i, int j) {
    i = getParent(parent, i);
    j = getParent(parent, j);
    if (i != j) {
        parent[i] = j;
    }
}


void bellmanFord(FILE *output, int startNode, int noOfVertices, int **adjMatrix) {
    fprintf(output, "Bellman-Ford algorithm started: \n");
    int *distances = initializeArray(noOfVertices, MAX_LIMIT);
    int *previous = initializeArray(noOfVertices, UNDEFINED);
    distances[startNode] = 0;
    int noOfEdges = getNoOfEdges(noOfVertices, adjMatrix);
    edgeT *edges = getEdges(noOfVertices, adjMatrix, noOfEdges);

    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfEdges; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int alt = distances[u] + edges[j].weight;
            if (alt < distances[v]) {
                distances[v] = alt;
                previous[v] = u;
            }
        }
    }

    if (checkNegativeCycles(distances, noOfEdges, edges) == 1) {
        fprintf(output, "The graph contains a negative weight cycle.\n");
    } else {
        printShortestPath(output, noOfVertices, startNode, previous, distances);
    }
    fprintf(output, "Bellman-Ford algorithm ended. \n");
}

void printShortestPath(FILE *output, int noOfVertices, int startNode, const int *previous, const int *distances) {
    for (int i = 0; i < noOfVertices; i++) {
        int u = i;
        if (i != startNode) {
            while (previous[u] != UNDEFINED) {
                push(u);
                u = previous[u];
            }
            fprintf(output, "Path from %c to %c is: %c", startNode + 'A', i + 'A', startNode + 'A');
            while (!isEmptyStack()) {
                fprintf(output, " -> %c", peekStack()->data + 'A');
                pop();
            }
            fprintf(output, ", with the cost %d.\n", distances[i]);
        }
    }
}

int getNoOfEdges(int noOfVertices, int **adjMatrix) {
    int noOfEdges = 0, i, j;
    for (i = 0; i < noOfVertices; i++) {
        for (j = 0; j < noOfVertices; j++) {
            if (adjMatrix[i][j] != 0) {
                noOfEdges++;
            }
        }
    }
    return noOfEdges;
}

edgeT *getEdges(int noOfVertices, int **adjMatrix, int noOfEdges) {
    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * noOfEdges);
    int index = 0;
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++) {
            if (adjMatrix[i][j] != 0) {
                edges[index].source = i;
                edges[index].destination = j;
                edges[index].weight = adjMatrix[i][j];
                index++;
            }
        }
    }
    return edges;
}

int checkNegativeCycles(const int *distances, int noOfEdges, edgeT *edges) {
    for (int i = 0; i < noOfEdges; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int alt = edges[i].weight + distances[u];
        if (alt < distances[v]) {
            return 1;
        }
    }
    return 0;
}

int *initializeArray(int noOfVertices, int value) {
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++) {
        visited[i] = value;
    }
    return visited;
}

