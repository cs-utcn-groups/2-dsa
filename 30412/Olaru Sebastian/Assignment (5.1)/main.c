#include "algorithms.h"

int main() {
    FILE *fin;
    fin = fopen("input.dat", "r");

    int noOfVertices;
    int **adjMatrix = inputAdjMatrix(fin, &noOfVertices);
    List *adjList = getListFromMatrix(adjMatrix, noOfVertices);

    printf("\n\nThe adjacency list from given adjacency matrix:\n");
    printAdjList(adjList, noOfVertices);

    printf("\n\nThe given matrix from the computed adjacency list:\n");
    adjMatrix = getMatrixFromList(adjList, noOfVertices);
    printAdjMatrix(adjMatrix, noOfVertices);

    printf("\n\nBFS on the resulted adjacency list:\n");
    BFS(1, adjList, noOfVertices);
    recursiveDFS(1, adjList, noOfVertices);


    return 0;
}