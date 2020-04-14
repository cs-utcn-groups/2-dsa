#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define nrOfNodes 7
#define maxNrOfEdges 7*(7-1)
#define maxLengthOfLine 10

typedef struct edge {
    int source;
    int destination;
    int cost;

} Edge;

int readEdges(FILE *f, Edge *ed) {
    char *buffer = (char *) malloc(sizeof(char) * maxLengthOfLine);
    int nrOfEdges = 0;
    while (fgets(buffer, maxLengthOfLine, f) != NULL) {
        ed[nrOfEdges].source = atoi(&buffer[0]);
        ed[nrOfEdges].destination = atoi(&buffer[2]);
        ed[nrOfEdges].cost = atoi(buffer + 4);
        nrOfEdges++;
    }
    return nrOfEdges;
}

int **formAdjMatrix(Edge *ed, int nr) {
    int **mat = (int **) malloc(sizeof(int *) * (nrOfNodes + 1));
    for (int i = 0; i < (nrOfNodes + 1); i++) {
        mat[i] = (int *) malloc(sizeof(int) * (nrOfNodes + 1));
    }
    for (int i = 0; i < (nrOfNodes + 1); i++) {
        for (int j = 0; j < (nrOfNodes + 1); j++) {
            mat[i][j] = 0;
        }
    }
    for (int i = 0; i < nr; i++) {
        mat[ed[i].source][ed[i].destination] = ed[i].cost;
    }
    return mat;
}

int minDistance(const int *dist, const bool *sptSet) {
    int min = INT_MAX, minIndex = 0;

    for (int v = 1; v <= nrOfNodes; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printSolution(int *dist, int **mat) {
    int visited[nrOfNodes + 1];
    int minCost = 0;
    for (int i = 1; i <= nrOfNodes; i++) {
        minCost = minCost + dist[i];
    }
    printf("%d,", minCost);
    int copy[nrOfNodes + 1];
    for (int i = 1; i <= nrOfNodes; i++) {
        copy[i] = dist[i];
    }
    int aux;
    for (int i = 1; i < nrOfNodes; i++) {
        for (int j = i + 1; j <= nrOfNodes; j++) {
            if (copy[i] > copy[j]) {
                aux = copy[i];
                copy[i] = copy[j];
                copy[j] = aux;
            }
        }
    }

    for (int i = 1; i <= nrOfNodes; i++) {
        visited[i] = 0;
    }

    int orderedNodes[nrOfNodes + 1];
    for (int i = 1; i <= nrOfNodes; i++) {
        for (int j = 1; j <= nrOfNodes; j++) {
            if (copy[i] == dist[j] && visited[j] == 0) {
                orderedNodes[i] = j;
                visited[j] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= nrOfNodes; i++) {
        printf(" %d", orderedNodes[i]);
    }
}

void Dijkstra(int **mat, int src) {
    int dist[nrOfNodes + 1];
    bool sptSet[nrOfNodes + 1];

    for (int i = 1; i <= nrOfNodes; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < nrOfNodes - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 1; v <= nrOfNodes; v++) {
            if (!sptSet[v] && mat[u][v] && dist[u] != INT_MAX && dist[u] + mat[u][v] < dist[v]) {
                dist[v] = dist[u] + mat[u][v];
            }
        }
    }

    printSolution(dist, mat);
}

int main() {
    FILE *f;
    f = fopen("input.txt", "r");
    Edge *ed = (Edge *) malloc(sizeof(Edge) * maxNrOfEdges);
    int nrOfEdges = readEdges(f, ed);
    int **adjMatrix = formAdjMatrix(ed, nrOfEdges);

    Dijkstra(adjMatrix, 1);


    fclose(f);
    return 0;
}