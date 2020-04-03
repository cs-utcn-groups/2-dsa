#include <stdio.h>
#include "representGraph.h"
#include "traversGraph.h"
#include "longestPath.h"

#define  ERR_OPEN_FILE "Error opening file"
#define INPUT_FILE_NAME "../in.txt"

FILE * openFile(char * name, char * mode);

int main() {
    FILE * inFile = openFile(INPUT_FILE_NAME, "r");
    int N; // number of nodes
    int ** A = readMatrix(inFile, &N);
    printMatrix(N, A);
    // matrix -> list
    ListT * AL = convertMatrixToList(N, A);
    printAdjList(N,AL);
    // dfs traversal
    DFSRec(N,AL,2);
    // bfs traversal
    BFS(N,AL,2);
    // longest path
    findLongestPath(N,AL,2,1);
    // list -> matrix
    A = convertListToMatrix(N,AL);
    printMatrix(N,A);
    freeMatrix(N,A);
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