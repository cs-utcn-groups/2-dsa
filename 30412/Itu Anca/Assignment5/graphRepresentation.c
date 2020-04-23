//
// Created by Anca on 4/6/2020.
//

#include <stdlib.h>
#include "graphRepresentation.h"

void readFromAdjMatrix(FILE *f){
    fscanf(f, "%d", &noOfVertices);
    int i, j;
    adjMatrix = (int**) malloc (noOfVertices * sizeof(int*));
    for(i=0;i<noOfVertices;i++){
        *(adjMatrix + i) = (int*) malloc (noOfVertices * sizeof(int));
    }
    for(i=0;i<noOfVertices;i++){
        for(j=0;j<noOfVertices;j++){
            fscanf(f, "%d", &adjMatrix[i][j]);
        }
    }
    fclose(f);
}


int getNumberOfNeighborsOfVertex(int v){
    if(v < noOfVertices){
        int i;
        int noOfNeighbors = 0;
        for(i=0;i<noOfVertices;i++){
            if(adjMatrix[v][i]>0 && v!=i){
                noOfNeighbors++;
            }
        }
        return noOfNeighbors;
    }
    else{
        return 0;
    }
}

int *getAllNeighborsOfVertex(int v){
    if(v < noOfVertices){
        int noOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int i, j = 0;
        int *neighbors = (int*) malloc ( noOfNeighbors * sizeof(int));
        for(i=0;i<noOfVertices;i++){
            if(adjMatrix[v][i] > 0 && v != i){
                neighbors[j] = i;
                j++;
            }
        }
        return neighbors;
    }
    else{
        return NULL;
    }
}

void createListFromMatrix(){
    int i, j;
    adjList = (NodeL**) malloc (noOfVertices * sizeof(NodeL*));
    for(i=0;i<noOfVertices;i++){
        adjList[i] = NULL;
    }

    for(i=0; i<noOfVertices; i++){
        for(j=0; j<noOfVertices; j++){
            if(adjMatrix[i][j]>0 && i!=j){
                NodeL * newNode = createNodeL(j,adjMatrix[i][j]);
                newNode->next = adjList[i];
                adjList[i] = newNode;
            }
        }
    }
}

void createMatrixFromList(){
    int i, j;
    adjMatrix = (int**) malloc (noOfVertices * sizeof(int*));
    for(i=0;i<noOfVertices;i++){
        *(adjMatrix + i) = (int*) malloc (noOfVertices * sizeof(int));
    }

    for(i=0; i<noOfVertices; i++){
        j=noOfVertices-1;
        NodeL *temp = adjList[i];
        while(temp != NULL){
            if(j == temp->content){
                adjMatrix[i][j] = temp->weight;
                temp = temp->next;
                j--;
            }
            else{
                adjMatrix[i][j] = 0;
                j--;
            }
        }
        while(j>-1){
            adjMatrix[i][j]=0;
            j--;
        }
    }
}

void printAdjMatrix(){
    int i, j;
    printf("The matrix is:\n");
    printf("    ");
    for(i=0;i<noOfVertices;i++){
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for(i=0;i<noOfVertices;i++){
        printf("%c ", 'A' + i);
        for(j=0;j<noOfVertices;j++){
            printf("%3d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printList(){
    int v;
    for(v=0;v<noOfVertices;v++){
        NodeL *temp = adjList[v];
        printf("\nAdjacency list of vertex %c:\n", v +'A');
        while(temp->next){
            printf("( %c , %d ) ", temp->content +'A', temp->weight);
            temp = temp->next;
        }
        printf("( %c , %d );", temp->content +'A', temp->weight);
        printf("\n");
    }
    printf("\n");
}

int getNumberOfNeighborsOfVertexFromList(int v){
    if(v < noOfVertices){
        int noOfNeighbors = 0;
        NodeL *temp = adjList[v];
        while(temp != NULL){
            noOfNeighbors++;
            temp = temp->next;
        }
        return noOfNeighbors;
    }
    else{
        return 0;
    }
}

int *getAllNeighborsOfVertexFromList(int v){
    if(v < noOfVertices){
        int noOfNeighbors = getNumberOfNeighborsOfVertexFromList(v);

        int i = noOfVertices-1;
        int j = noOfNeighbors-1;
        int *neighbors = (int*) malloc ( noOfNeighbors * sizeof(int) );
        NodeL *temp = adjList[v];

        while(temp != NULL){
            if(i == temp->content){
                neighbors[j] = i;
                temp = temp->next;
                i--;
                j--;
            }
            else{
                i--;
            }
        }
        return neighbors;
    }
    else{
        return NULL;
    }
}