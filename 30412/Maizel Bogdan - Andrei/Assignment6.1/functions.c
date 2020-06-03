#include "head.h"

void bellmanFord(int start, int **adjMatrix, int noOfVertices) {
    start--;
    int *dist = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; ++i) {
        if (i == start)
            dist[i] = 0;
        else
            dist[i] = MAX;
    }
    edgeT *listOfEdges = getAllDirectedEdges(adjMatrix, noOfVertices);
    int noOfEdges = getNoOfDirectedEdges(adjMatrix, noOfVertices);
    for (int i = 1; i < noOfVertices; i++) {
        for (int j = 0; j < noOfEdges; j++) {
            int u = listOfEdges[j].source;
            int v = listOfEdges[j].destination;
            int weight = listOfEdges[j].weight;
            if (dist[u] != MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < noOfEdges; i++) {
        int u = listOfEdges[i].source;
        int v = listOfEdges[i].destination;
        int weight = listOfEdges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return;
        }
    }
    printf("Distance from Source\n");
    for (int i = 0; i < noOfVertices; ++i)
        printf("%d: %d\n", i, dist[i]);
}

int getNoOfDirectedEdges(int **adjMatrix, int noOfVertices) {
    int count = 0;
    for (int i = 0; i < noOfVertices; ++i) {
        for (int j = 0; j < noOfVertices; ++j) {
            if (adjMatrix[i][j] != 0 && i != j) {
                count++;
            }
        }
    }
    return count;
}

edgeT *getAllDirectedEdges(int **adjMatrix, int noOfVertices) {
    edgeT *list = (edgeT *) malloc((((noOfVertices - 1) * noOfVertices) / 2) * sizeof(edgeT));
    int k = 0;

    for (int i = 0; i < noOfVertices; ++i) {
        for (int j = 0; j < noOfVertices; ++j) {
            if (adjMatrix[i][j] != 0 && i != j) {
                list[k].source = i;
                list[k].destination = j;
                list[k].weight = adjMatrix[i][j];
                k++;
            }
        }
    }
    return list;
}

void kruskal(int **adjMatrix, int noOfVertices) {
    int totalCost = 0;
    edgeT *listOfEdges = getAllEdgesSorted(adjMatrix, noOfVertices);
    int noOfEdges = getNoOfEdges(adjMatrix, noOfVertices);
    //printEdges(listOfEdges, noOfEdges);
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }
    int currentEdgeIndex = -1;
    while (!allVerticesVisited(visited, noOfVertices) && currentEdgeIndex < noOfEdges) {
        do {
            currentEdgeIndex++;
        } while (!validEdge(visited, listOfEdges[currentEdgeIndex]));

        edgeT currentEdge = listOfEdges[currentEdgeIndex];
        visited[currentEdge.destination] = VISITED;
        visited[currentEdge.source] = VISITED;
        totalCost += currentEdge.weight;
        printf("%d - %d: %d\n", currentEdge.source + 1, currentEdge.destination + 1, currentEdge.weight);
    }
    printf("The min cost is %d\n\n", totalCost);
}

int allVerticesVisited(int *visited, int noOfVertices) {
    for (int i = 0; i < noOfVertices; ++i) {
        if (visited[i] == UNVISITED)
            return 0;
    }
    return 1;
}

int validEdge(int *visited, edgeT edge) {
    if (visited[edge.source] == VISITED && visited[edge.destination] == VISITED) {
        return 0;
    }
    return 1;
}

int getNoOfEdges(int **adjMatrix, int noOfVertices) {
    int count = 0;
    for (int i = 0; i < noOfVertices - 1; ++i) {
        for (int j = i + 1; j < noOfVertices; ++j) {
            if (adjMatrix[i][j])
                count++;
        }
    }
    return count;
}

edgeT *getAllEdgesSorted(int **adjMatrix, int noOfVertices) {
    edgeT *list = (edgeT *) malloc((((noOfVertices - 1) * noOfVertices) / 2) * sizeof(edgeT));
    int k = 0;
    for (int i = 0; i < noOfVertices - 1; ++i) {
        for (int j = i + 1; j < noOfVertices; ++j) {
            if (adjMatrix[i][j]) {
                list[k].source = i;
                list[k].destination = j;
                list[k].weight = adjMatrix[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        for (int j = i + 1; j < k; ++j) {
            if (list[i].weight > list[j].weight) {
                edgeT aux;
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }
    return list;
}

int **readAdjMatrix(FILE *input, int *numberOfVertices) {
    fscanf(input, "%d", numberOfVertices);
    fgetc(input);
    int **matrix = (int **) malloc((*numberOfVertices) * sizeof(int *));
    for (int i = 0; i < (*numberOfVertices); i++) {
        matrix[i] = (int *) malloc((*numberOfVertices) * sizeof(int *));
        for (int j = 0; j < (*numberOfVertices); j++) {
            fscanf(input, "%d", &matrix[i][j]);
            fgetc(input);
        }
    }
    return matrix;
}
