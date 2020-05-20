//
// Created by Alex on 11.04.2020.
//

#ifndef ASSIGNMENT_6_1_EDGES_H

#include <stdlib.h>
#include <stdio.h>

typedef struct edge {
    int nodeA;
    int nodeB;
    int lenght;
} Edge;

void orderEdge(Edge *edges, int n);

void Kruskal(Edge *edges, int n, int m,int *visited,int *order);

void createMatrix(Edge *edges,int n,int m,int **mat);

void BF(int **mat,int n,int x,int *visited);

#define ASSIGNMENT_6_1_EDGES_H

#endif //ASSIGNMENT_6_1_EDGES_H
