//
// Created by Irina on 20/05/2020.
//
#include "list operations.h"

NodeT ** matrixToList(NodeT ** listArray){
    for(int i=0; i<nrOfVertexes; i++){
        listArray[i] = (NodeT*)malloc(nrOfVertexes * sizeof(NodeT));
        for(int j=0; j<nrOfVertexes; j++){
            listArray[i]->next = NULL;
            listArray[i]->content = 'A' + i;
        }
    }
    for(int i=0; i<nrOfVertexes; i++) {
        for(int j=0; j<nrOfVertexes; j++) {
            if (adjMatrix[i][j] != 0 && i != j) {
                NodeT *newNode = createNode('A' + j);
                if (listArray[i]->next == NULL) {
                    listArray[i]->next = newNode;
                } else {
                    NodeT * currentNode = listArray[i];
                    listArray[i] = currentNode;
                    while(currentNode->next != NULL){
                        currentNode = currentNode->next;
                    }
                    currentNode->next = newNode;
                }
            }
        }
    }
    return listArray;
}
void listToMatrix(NodeT ** listArray){
    int k;
    int n = nrOfVertexes;
    adjMatrixFromList = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adjMatrixFromList[i] = (int *) malloc(n * sizeof(int));
        for(int j=0; j<n; j++){
            adjMatrixFromList[i][j] = 0;
        }
    }
    for (int i=0; i<nrOfVertexes; i++){
        NodeT * currentNode = listArray[i]->next;
        while (currentNode != NULL) {
            k = (currentNode->content - 'A');
            adjMatrixFromList[i][k] = 1;
            currentNode = currentNode->next;
        }
    }
}
void printList(NodeT ** listArray){
    for(int i=0; i<nrOfVertexes; i++) {
        NodeT * node = listArray[i];
        while (node != NULL) {
            printf("%c ", node->content);
            node = node->next;
        }
        printf("\n");
    }
    printf("\n");
}
void printMatrix(){
    for (int i=0; i<nrOfVertexes; i++){
        for (int j=0; j<nrOfVertexes; j++){
            printf("%d ", adjMatrixFromList[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int getNumberOfNeighborsOfVertexList(int v, NodeT ** listArray) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = 0;
        NodeT * currentNode = listArray[v]->next;
        while(currentNode != NULL){
            nrOfNeighbors++;
            currentNode = currentNode->next;
        }
        return nrOfNeighbors;
    } else {
        return 0;
    }
}
int * getAllNeighborsOfVertexList(int v, NodeT ** listArray) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertexList(v,listArray);
        int *neighbors = (int*)malloc(nrOfNeighbors * sizeof(int));
        int j = 0;
        NodeT * currentNode = listArray[v]->next;
        while (currentNode != NULL){
            neighbors[j] = currentNode->content - 'A';
            j++;
            currentNode = currentNode->next;
        }
        return neighbors;
    } else {
        return NULL;
    }
}