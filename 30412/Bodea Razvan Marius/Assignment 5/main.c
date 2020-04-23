#include <stdio.h>
#include "list.h"
#include "matrix.h"
#include "traversal.h"
#include "transform.h"

int main() {
    FILE *f = fopen("../input.dat", "r");
    if(f==NULL){
        perror("File could not be open");
        exit(EXIT_FAILURE);
    }
    FILE *fptr=fopen("../output.dat","w");
    int noOfVertices;
    fscanf(f, "%d", &noOfVertices);
    int **adjMatrix = readAdjMatrix(f, noOfVertices);
    BFS(fptr,0, noOfVertices, adjMatrix);
    DFS(fptr,0, noOfVertices, adjMatrix);
    List *adjList = createListFromMatrix(noOfVertices, adjMatrix);
    BFSonList(fptr,0, noOfVertices, adjList);
    DFSonList(fptr,0, noOfVertices, adjList);
    int **newAdjMatrix = createMatrixFromList(noOfVertices, adjList);
    BFS(fptr,0, noOfVertices, newAdjMatrix);
    DFS(fptr,0, noOfVertices, newAdjMatrix);
    fprintf(fptr,"The Matrix was: \n");
    printAdjMatrix(fptr,noOfVertices,newAdjMatrix);
    return 0;
}