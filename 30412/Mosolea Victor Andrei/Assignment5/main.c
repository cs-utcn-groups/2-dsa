#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UNVISITED 0
#define VISITED 1

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node *first, *last;
} List;

void initList(List *list) {
    list->first = NULL;
    list->last = NULL;
}

void enqueue(int data, List *list) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->first == NULL) {
        list->first = newNode;
        list->last = list->first;
        list->last->next = NULL;
    } else
        list->last->next = newNode;
    list->last = newNode;
}

int dequeue(List *list) {
    int dequeue = list->first->data;
    if (list->first != NULL) {
        Node *aux = list->first;
        list->first = list->first->next;
        free(aux);
    }
    if (list->first == NULL)
        list->last = NULL;
    return dequeue;
}

int **readAdjMatrix(FILE *f, int noOfVertices) {
    int **adjMatrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i < noOfVertices; i++)
        adjMatrix[i] = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        for (int j = 0; j < noOfVertices; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    return adjMatrix;
}

void printAdjMatrix(int noOfVertices, int **adjMatrix) {
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}

int getNoOfNeighbors(int v, int **adjMatrix, int noOfVertices) {
    int noOfNeighbors = 0;
    for (int i = 0; i < noOfVertices; i++)
        if (adjMatrix[v][i] > 0)
            noOfNeighbors++;
    return noOfNeighbors;
}

int *getNeighbors(int v, int **adjMatrix, int noOfVertices) {
    int noOfNeighbors = getNoOfNeighbors(v, adjMatrix, noOfVertices);
    int *neighbors = (int *) malloc(noOfNeighbors * sizeof(int));
    int j = -1;
    for (int i = 0; i < noOfVertices; i++)
        if (adjMatrix[v][i] > 0) {
            neighbors[++j] = i;
        }
    return neighbors;
}

void BFS(int startNode, int noOfVertices, int **adjMatrix) {
    List queue;
    initList(&queue);
    printf("BFS started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;

    enqueue(startNode, &queue);
    while (queue.first != NULL) {
        int v = dequeue(&queue);
        visited[v] = VISITED;
        printf("%d", v);
        int *neighbors = getNeighbors(v, adjMatrix, noOfVertices);
        for (int i = 0; i < getNoOfNeighbors(v, adjMatrix, noOfVertices); i++)
            if (visited[neighbors[i]] == UNVISITED) {
                enqueue(neighbors[i], &queue);
                visited[neighbors[i]] = VISITED;
            }
    }
    printf("\nBFS ended\n");
}

void recDFS(int *visited, int v, int **adjMatrix, int noOfVertices) {
    visited[v] = VISITED;
    printf("%d", v);
    int *neighbors = getNeighbors(v, adjMatrix, noOfVertices);
    for (int i = 0; i < getNoOfNeighbors(v, adjMatrix, noOfVertices); i++)
        if (visited[neighbors[i]] == UNVISITED) {
            visited[neighbors[i]] = VISITED;
            recDFS(visited, neighbors[i], adjMatrix, noOfVertices);
        }
}

void DFS(int startNode, int noOfVertices, int **adjMatrix) {
    printf("DFS started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;
    recDFS(visited, startNode, adjMatrix, noOfVertices);
    printf("\nDFS ended\n");
}

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

void BFSonList(int startNode, int noOfVertices, List *adjList) {
    List queue;
    initList(&queue);
    printf("BFS on List started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;

    enqueue(startNode, &queue);
    while (queue.first != NULL) {
        int v = dequeue(&queue);
        visited[v] = VISITED;
        printf("%d", v);
        Node *currentNode = adjList[v].first;
        while (currentNode != NULL) {
            if (visited[currentNode->data] == UNVISITED) {
                visited[currentNode->data] = VISITED;
                enqueue(currentNode->data, &queue);
            }
            currentNode = currentNode->next;
        }
    }
    printf("\nBFS on List ended\n");
}

void recDFSonList(int *visited, int v, List *adjList) {
    visited[v] = VISITED;
    printf("%d", v);
    Node *currentNode = adjList[v].first;
    while (currentNode != NULL) {
        if (visited[currentNode->data] == UNVISITED) {
            visited[currentNode->data] = VISITED;
            recDFSonList(visited, currentNode->data, adjList);
        }
        currentNode = currentNode->next;
    }
}

void DFSonList(int startNode, int noOfVertices, List *adjList) {
    printf("DFS on List started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    for (int i = 0; i < noOfVertices; i++)
        visited[i] = UNVISITED;
    recDFSonList(visited, startNode, adjList);
    printf("\nDFS on List ended\n");
}

bool isInList(int data, List adjList) {
    Node *currentNode = adjList.first;
    while (currentNode != NULL) {
        if (data == currentNode->data)
            return 1;
        currentNode = currentNode->next;
    }
    return 0;
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

int main() {
    FILE *f = fopen("../input.dat", "r");
    int noOfVertices;
    fscanf(f, "%d", &noOfVertices);
    int **adjMatrix = readAdjMatrix(f, noOfVertices);
    BFS(0, noOfVertices, adjMatrix);
    DFS(0, noOfVertices, adjMatrix);
    List *adjList = createListFromMatrix(noOfVertices, adjMatrix);
    BFSonList(0, noOfVertices, adjList);
    DFSonList(0, noOfVertices, adjList);
    int **newAdjMatrix = createMatrixFromList(noOfVertices, adjList);
    BFS(0, noOfVertices, newAdjMatrix);
    DFS(0, noOfVertices, newAdjMatrix);
    return 0;
}
