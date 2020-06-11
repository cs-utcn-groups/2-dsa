#include <stdio.h>
#include "graphRepresentation.h"
#include "graphTraversals.h"


typedef struct listAdj{
    NodeT *first;
    NodeT *last;
}List;

void initList(List *list) {
    list->first = NULL;
    list->last = NULL;
}

void enqueueL(int data, List *list) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->content = data;
    newNode->next = NULL;

    if (list->first == NULL) {
        list->first = newNode;
        list->last = list->first;
        list->last->next = NULL;
    } else
        list->last->next = newNode;
    list->last = newNode;
}

List *createListFromMatrix(int noOfVertices, int **adjMatrix){

    List *adjList = (List *) malloc(noOfVertices * sizeof(List));

    for (int i = 0; i < noOfVertices; i++)
        initList(&adjList[i]);

    for (int i = 0; i < noOfVertices; i++)
        for (int j = 0; j < noOfVertices; j++)
            if (adjMatrix[i][j] > 0)
                enqueueL(j, &adjList[i]);

    return adjList;
}

int **createMatrix(int noOfVertices, List *adjList) {
    int **newAdjMatrix = (int **) malloc(noOfVertices * sizeof(int *));

    for (int i = 0; i < noOfVertices; i++)
        newAdjMatrix[i] = (int *) malloc(noOfVertices * sizeof(int *));

    for (int i = 0; i < noOfVertices; i++){
        for (int j = 0; j < noOfVertices; j++){
            newAdjMatrix[i][j] = 0;
            while (adjList[i].first != NULL) {
                if (j == adjList[i].first->content)
                    newAdjMatrix[i][j] = 1;
                adjList[i].first = adjList[i].first->next;
            }
        }
    }
    return newAdjMatrix;
}


int main() {
    FILE *f = fopen("../matrix.txt", "r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs('G' - 'A');
    dfs('G' - 'A');

    List *adjList = createListFromMatrix(7, adjMatrix);
    //print the adj list
    for (int i = 0; i < 7; i++){
        printf("For %c the adjaceny list is:",'A'+i);
        while (adjList[i].first != NULL){
            printf("%d,",adjList[i].first->content);
            adjList[i].first =  adjList[i].first->next;
        }
        printf("\n");
    }

    int **newAdjMatrix = createMatrix(7, adjList);

    return 0;
}