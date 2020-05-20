//
// Created by Ivan on 4/22/2020.
//

#ifndef LAB6_KRUSKBELL__FUNCTIONS_H
#define LAB6_KRUSKBELL__FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct _edge
{
    int src, dest, weight;
} edgeT;

FILE* f;
int **AdjMatrix;

int readMatrix(int **AdjMatrix, int V);
void InitMatrix(int V);
void getEdges(edgeT **edges, int V);
void kruskal(int V, int E, edgeT** e);
void bellmanFord(int V, int E, edgeT** edges);

#endif //LAB6_KRUSKBELL__FUNCTIONS_H
