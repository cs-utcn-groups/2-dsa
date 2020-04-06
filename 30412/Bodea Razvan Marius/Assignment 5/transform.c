//
// Created by razvi on 4/5/2020.
//
#include "transform.h"

List *createListFromMatrix(int noOfVertices, int **adjMatrix) {
    List *adjList = (List *) malloc(noOfVertices * sizeof(List));
    for (int i = 0; i < noOfVertices; i++)
        initList(&adjList[i]);
    for (int i = 0; i < noOfVertices; i++)
        for (int j = 0; j < noOfVertices; j++)
            if (adjMatrix[i][j] > 0)
                enqueue(j, &adjList[i]);
    return adjList;
}

int **createMatrixFromList(int noOfVertices, List *adjList) {
    int **newAdjMatrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i < noOfVertices; i++)
        newAdjMatrix[i] = (int *) malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i < noOfVertices; i++)
        for (int j = 0; j < noOfVertices; j++)
            if (isInList(j, adjList[i]))
                newAdjMatrix[i][j] = 1;
            else newAdjMatrix[i][j] = 0;
    return newAdjMatrix;
}

int isInList(int data, List adjList) {
    NodeT *currentNode = adjList.first;
    while (currentNode != NULL) {
        if (data == currentNode->data)
            return 1;
        currentNode = currentNode->next;
    }
    return 0;
}

