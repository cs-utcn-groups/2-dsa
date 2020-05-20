//
// Created by Ivan on 4/12/2020.
//

#ifndef LAB5_TRAVERSALS_GRAPHS__FUNCTIONS_H
#define LAB5_TRAVERSALS_GRAPHS__FUNCTIONS_H

#include <stdio.h>

#define N 100

typedef struct _node
{
    int dest, length;
    struct _node* next;
} NodeT;

NodeT* queue, *stack;

FILE* f, *g;

int AdjMatrix[N][N],size;
NodeT* AdjList[N];
void Init();
void bfs(int startNode);
void dfs(int startNode);
void matrixToList();
void readMatrix();
void listToMatrix();
void printList();


#endif //LAB5_TRAVERSALS_GRAPHS__FUNCTIONS_H
