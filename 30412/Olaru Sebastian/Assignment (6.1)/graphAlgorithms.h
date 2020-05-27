//
// Created by acer on 4/11/2020.
//

#ifndef ASSIGNMENT__6_1__GRAPHALGORITHMS_H
#define ASSIGNMENT__6_1__GRAPHALGORITHMS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct _edge
{
    int src, dest, weight;
} edgeT;

FILE* fin;
int **AdjMatrix;

int inputMatrix(int **AdjMatrix, int V);
void initializeMatrix(int V);
void findEdges(edgeT **edges, int V);
void kruskal(int V, int E, edgeT** e);
void bellmanFord(int V, int E, edgeT** edges);


#endif //ASSIGNMENT__6_1__GRAPHALGORITHMS_H
