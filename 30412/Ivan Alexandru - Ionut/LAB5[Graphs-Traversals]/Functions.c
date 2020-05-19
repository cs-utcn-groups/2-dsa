//
// Created by Ivan on 4/12/2020.
//

#include "functions.h"

//
// Created by Ivan on 4/12/2020.
//

#ifndef LAB5_TRAVERSALS_GRAPHS__FUNCTIONS_H
#define LAB5_TRAVERSALS_GRAPHS__FUNCTIONS_H

NodeT *createNode(int dest) {
    NodeT *newN = (NodeT *) malloc(sizeof(NodeT));
    newN->dest = dest;
    newN->next = NULL;
    return newN;
}

///queue
void enqueue(int content) {
    if (queue == NULL) {
        queue = createNode(content);
    } else {
        NodeT *aux = queue;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = createNode(content);
    }
}

void dequeue() {
    if (queue != NULL) {
        queue = queue->next;
    }
}

NodeT *peekQueue() {
    return queue;
}

int isEmptyQueue() {
    return queue == NULL;
}
///queue

void show(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", AdjMatrix[i][j]);
        }
        printf("\n");
    }
}

void Init()
{
    for(int i = 0; i < N; i++)
        AdjList[i] = NULL;
}

int getNumberOfNeighborsOfVertex(int v) {
    if (v < size) {
        int nrOfNeighbors = 0;
        int i;
        for (i = 0; i < size; i++) {
            if (AdjMatrix[v][i] > 0 && i != v) {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    } else {
        return 0;
    }
}

int *getAllNeighborsOfVertex(int v) {
    if (v < size) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int i, j = 0;
        for (i = 0; i < size; i++) {
            if (AdjMatrix[v][i] > 0 && i != v) {
                neighbors[j] = i;
                j++;
            }
        }
        return neighbors;
    } else {
        return NULL;
    }
}

void bfs(int startNode) {
    printf("BFS started\n");
    int *visited = (int *) malloc(size * sizeof(int));
    int i, v, w;

    for (i = 0; i < size; i++) {
        visited[i] = 0;
    }

    enqueue(startNode);
    visited[startNode] = 1;
    printf("%c ", startNode + 'A');

    while (!isEmptyQueue()) {
        v = peekQueue()->dest;
        dequeue();

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = getAllNeighborsOfVertex(v);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == 0) {
                printf("%c ", w + 'A');
                enqueue(w);
                visited[w] = 1;
            }
        }
    }

    printf("\nBFS ended\n\n");
}

void push(int content) {
    NodeT *newH = createNode(content);
    newH->next = stack;
    stack = newH;
}

void pop() {
    if (stack != NULL) {
        stack = stack->next;
    }
}

NodeT *peekStack() {
    return stack;
}

int isEmptyStack() {
    return stack == NULL;
}

void dfs(int startNode) {
    printf("DFS started\n");
    int *visited = (int *) malloc(size * sizeof(int));
    int i, v, w;

    for (i = 0; i < size; i++) {
        visited[i] = 0;
    }

    push(startNode);

    while (!isEmptyStack()) {
        v = peekStack()->dest;
        pop();

        if (visited[v] == 0) {
            visited[v] = 1;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int *neighbors = getAllNeighborsOfVertex(v);
            for (i = nrOfNeighbors - 1; i >= 0; i--) {
                w = neighbors[i];
                if (visited[w] == 0) {
                    push(w);
                }
            }
            printf("%c ", v + 'A');
        }
    }

    printf("\nDFS ended\n\n");
}

void matrixToList()
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(AdjMatrix[i][j] != 0)
            {
                if(AdjList[i] == NULL)
                {
                    AdjList[i] = (NodeT*)malloc(sizeof(NodeT));
                    AdjList[i]->dest = j;
                    AdjList[i]->length = AdjMatrix[i][j];
                    AdjList[i]->next = NULL;
                }
                else
                {
                    NodeT* p = (NodeT*)malloc(sizeof(NodeT));
                    p->dest = j;
                    p->length = AdjMatrix[i][j];
                    p->next = NULL;
                    NodeT* k = AdjList[i];
                    while(k->next != NULL)
                        k = k->next;
                    k->next = p;
                }
            }
        }
    }
}

void readMatrix()
{
    int x;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            fscanf(f, "%d", &x);
            if(x != 0)
            {
                AdjMatrix[i][j] = AdjMatrix[j][i] = x;
            }
        }
}

void listToMatrix()
{
    for(int i = 0; i < size; i++)
    {
        NodeT* k = AdjList[i];
        for(int j = 0; j < size; j++)
        {
            if(k != NULL)
            {
                if(k->dest == j)
                {
                    AdjMatrix[i][j] = k->length;
                    k = k->next;
                }else AdjMatrix[i][j] = 0;
            }
        }
    }
}

void printList()
{
    for(int i = 0; i < size; i++)
    {
        printf("head(%d) -> ", i);
        NodeT* k = AdjList[i];
        while(k != NULL)
        {
            printf("%d-(%d) -> ", k->dest, k->length);
            k = k ->next;
        }
        printf("NULL\n");
    }
}

#endif //LAB5_TRAVERSALS_GRAPHS__FUNCTIONS_H

