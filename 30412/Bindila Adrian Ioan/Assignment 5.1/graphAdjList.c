//
// Created by bindi on 4/6/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphAdjList.h"
#include "graph.h"
#define MAX_LINE_LENGTH 128

void getNoOfVertices(FILE *input){
    noOfVertices=0;
    char *buffer=(char*)malloc(MAX_LINE_LENGTH* sizeof(char));
    while(fgets(buffer,MAX_LINE_LENGTH,input)){
        noOfVertices++;
    }
    rewind(input);
}
void readAdjacencyList(FILE *input){
    char *buffer=(char*)malloc(MAX_LINE_LENGTH* sizeof(char));
    getNoOfVertices(input);
    adjMatrix=(int**)malloc(noOfVertices* sizeof(int*));
    for (int i = 0; i < noOfVertices; ++i) {
        adjMatrix[i]=(int*)malloc(noOfVertices* sizeof(int));
        for (int j = 0; j < noOfVertices; ++j) {
            adjMatrix[i][j]=0;
        }
    }

    while(fgets(buffer,MAX_LINE_LENGTH,input)){
        int currentVertex=buffer[0]-'A';
        char* token;
        strtok(buffer,"(");
        token=strtok(NULL,"(");
        while(token){
            ///token looks like: "B,12), "
            int neighbourVertex=token[0]-'A';
            int neighbourDistance=-1;
            strcpy(token,token+2);
            neighbourDistance=atoi(token);
            adjMatrix[currentVertex][neighbourVertex]=neighbourDistance;
            token=strtok(NULL,"(");
        }
    }
    fclose(input);
}

void printAdjacencyList(void){
    printf("The adjacency list is:\n");
    for (int i = 0; i < noOfVertices; ++i) {
        printf("%c ",'A'+i);
        for (int j = 0; j < noOfVertices; ++j) {
            if(adjMatrix[i][j]!=0){
                printf("(%c,%2d) ",'A'+j,adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}