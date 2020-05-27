//
// Created by acer on 4/5/2020.
//

#include "matrix.h"

int **inputAdjMatrix(FILE *input, int *noOfVertices) {
    fscanf(input, "%d", noOfVertices);
    fgetc(input);
    int **matrix = (int **)malloc((*noOfVertices) * sizeof(int*));
    for(int i=0; i<(*noOfVertices); i++){
        matrix[i] = (int *)malloc((*noOfVertices) * sizeof(int*));
        for(int j=0; j<(*noOfVertices); j++){
            fscanf(input,"%d", &matrix[i][j]);
            fgetc(input);
        }
    }
    return matrix;
}

void printAdjMatrix(int **adjMatrix, int noOfVertices) {
    for(int i=0; i < noOfVertices; i++){
        for (int j = 0; j < noOfVertices ; ++j) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}


int **getMatrixFromList(List *pList, int noOfVertices) {
    int **matrix = (int **)malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i <noOfVertices ; ++i) {
        matrix[i] = (int *)malloc(noOfVertices * sizeof(int));
        Node *currentNode = pList[i].first;
        while(currentNode){
            matrix[i][currentNode->data - 1] = 1;
            currentNode = currentNode->next;
        }
    }
    for (int i = 0; i <noOfVertices ; ++i) {
        for (int j = 0; j <noOfVertices ; ++j) {
            if(matrix[i][j] != 1)
                matrix[i][j] = 0;
        }

    }
    return matrix;
}

int noOfNeighborsOfVertex(List *pList, int indexNode) {
    int count = 0;
    Node *currentNeighbor = pList[indexNode].first;
    while(currentNeighbor){
        count++;
        currentNeighbor = currentNeighbor->next;
    }
    return count;
}

int *getAllNeighborsOfVertex(List *pList, int indexNode, int noOfNeighbors) {
    int *neighbors = (int *)malloc(noOfNeighbors * sizeof(int));
    int i = 0;
    Node *currentNeighbor = pList[indexNode].first;
    while(currentNeighbor){
        neighbors[i] = currentNeighbor->data - 1;
        i++;
        currentNeighbor = currentNeighbor->next;
    }
    return neighbors;
}

