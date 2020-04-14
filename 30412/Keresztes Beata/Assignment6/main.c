#include <stdio.h>
#include "representGraph.h"
#include "graphAlgorithms.h"
#include "vertexCover.h"

#define  ERR_OPEN_FILE "Error opening file"
#define INPUT_FILE_NAME "../inGraph.txt"
#define INPUT_FILE_D_NAME "../inDigraph.txt"

FILE * openFile(char * name, char * mode);

int main() {
    FILE * inFile = openFile(INPUT_FILE_NAME, "r");
    int N; // number of nodes
    int ** A = readMatrix(inFile, &N);
    printMatrix(N, A);
    // Kruskal's algorithm
    kruskal(N,A);
    // vertex cover approximation
    vertexCover(N,A);
    // optimized vertex cover approximation
    vertexCoverOpt(N,A);
    freeMatrix(N,A);
    fclose(inFile);
     inFile = openFile(INPUT_FILE_D_NAME, "r");
    A = readMatrix(inFile, &N);
    printMatrix(N, A);
    // Bellman-Ford's algorithm
    bellmanFord(N,A,5);
    freeMatrix(N,A);
    fclose(inFile);
    return 0;
}

FILE * openFile(char * name, char * mode) {
    // function to open file
    FILE * fp = fopen(name, mode);
    if(fp == NULL) {
        perror(ERR_OPEN_FILE);
        exit(EXIT_FAILURE);
    }
    return fp;
}