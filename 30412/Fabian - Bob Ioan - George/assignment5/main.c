#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define in "../input.dat"

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

void en(int data, List *list);

int de(List *list);

int **matrixRead(FILE *f, int vertices);

int getNoOfNeighbors(int k, int **matrix, int vertices);

int *getNeighbors(int k, int **matrix, int vertices);

void BFS(int start, int vertices, int **matrix);

void DFSsec(int *visited, int k, int **matrix, int vertices);

void DFS(int start, int vertices, int **matrix);

List *createLST(int vertices, int **matrix);

void BFSlst(int start, int vertices, List *lst);

void secDFSlst(int *visited, int k, List *lst);

void DFSlst(int start, int vertices, List *lst);

bool isInList(int data, List lst);

int **createMatrix(int vertices, List *lst);

void DFSsecPath(int *visited, int k, int **matrix, int vertices, int length,
                int endN, int *path, int *resultedPath, int *maxLen);

void DFSpath(int start, int vertices, int **matrix, int endN);



int main() {
    FILE *f;
    f = fopen(in, "r");
    if (f == NULL) {
        perror("ERROR");
        exit(-1);
    }
    int vertices;
    fscanf(f, "%d", &vertices);
    int **matrix = matrixRead(f, vertices);
    BFS(0, vertices, matrix);
    DFS(0, vertices, matrix);
    List *lst = createLST(vertices, matrix);
    BFSlst(0, vertices, lst);
    DFSlst(0, vertices, lst);
    int **newAdjMatrix = createMatrix(vertices, lst);
    BFS(0, vertices, newAdjMatrix);
    DFS(0, vertices, newAdjMatrix);
    DFSpath(2, vertices, newAdjMatrix, 4);

    return 0;
}

void en(int data, List *list) {
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

int de(List *list) {
    int de = list->first->data;
    if (list->first != NULL) {
        Node *aux = list->first;
        list->first = list->first->next;
        free(aux);
    }
    if (list->first == NULL)
        list->last = NULL;
    return de;
}

int **matrixRead(FILE *f, int vertices) {
    int **adjMatrix = (int **) malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
        adjMatrix[i] = (int *) malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    return adjMatrix;
}

int getNoOfNeighbors(int k, int **matrix, int vertices) {
    int noOfNeighbors = 0;
    for (int i = 0; i < vertices; i++)
        if (matrix[k][i] > 0)
            noOfNeighbors++;
    return noOfNeighbors;
}

int *getNeighbors(int k, int **matrix, int vertices) {
    int noOfNeighbors = getNoOfNeighbors(k, matrix, vertices);
    int *neighbors = (int *) malloc(noOfNeighbors * sizeof(int));
    int j = -1;
    for (int i = 0; i < vertices; i++)
        if (matrix[k][i] > 0) {
            neighbors[++j] = i;
        }
    return neighbors;
}

void BFS(int start, int vertices, int **matrix) {
    List queue;
    initList(&queue);
    printf("BFS Started\n");
    int *visited = (int *) malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    en(start, &queue);
    while (queue.first != NULL) {
        int v = de(&queue);
        visited[v] = 1;
        printf("%d", v);
        int *neighbors = getNeighbors(v, matrix, vertices);
        for (int i = 0; i < getNoOfNeighbors(v, matrix, vertices); i++)
            if (visited[neighbors[i]] == 0) {
                en(neighbors[i], &queue);
                visited[neighbors[i]] = 1;
            }}
    printf("\nBFS Ended\n");
}

void DFSsec(int *visited, int k, int **matrix, int vertices) {
    visited[k] = 1;
    printf("%d", k);
    int *neighbors = getNeighbors(k, matrix, vertices);
    for (int i = 0; i < getNoOfNeighbors(k, matrix, vertices); i++)
        if (visited[neighbors[i]] == 0) {
            visited[neighbors[i]] = 1;
            DFSsec(visited, neighbors[i], matrix, vertices);
        }
}

void DFS(int start, int vertices, int **matrix) {
    printf("DFS Started\n");
    int *visited = (int *) malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    DFSsec(visited, start, matrix, vertices);
    printf("\nDFS Ended\n");
}

List *createLST(int vertices, int **matrix) {
    List *adjList = (List *) malloc(vertices * sizeof(List));
    for (int i = 0; i < vertices; i++)
        initList(&adjList[i]);
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (matrix[i][j] > 0)
                en(j, &adjList[i]);
    return adjList;
}

void BFSlst(int start, int vertices, List *lst) {
    List queue;
    initList(&queue);
    printf("BFS Lst Started\n");
    int *visited = (int *) malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    en(start, &queue);
    while (queue.first != NULL) {
        int v = de(&queue);
        visited[v] = 1;
        printf("%d", v);
        Node *currentNode = lst[v].first;
        while (currentNode != NULL) {
            if (visited[currentNode->data] == 0) {
                visited[currentNode->data] = 1;
                en(currentNode->data, &queue);
            }
            currentNode = currentNode->next;
        }
    }
    printf("\nBFS Lst Ended\n");
}

void secDFSlst(int *visited, int k, List *lst) {
    visited[k] = 1;
    printf("%d", k);
    Node *currentNode = lst[k].first;
    while (currentNode != NULL) {
        if (visited[currentNode->data] == 0) {
            visited[currentNode->data] = 1;
            secDFSlst(visited, currentNode->data, lst);
        }
        currentNode = currentNode->next;
    }
}

void DFSlst(int start, int vertices, List *lst) {
    printf("DFS Lst Started\n");
    int *visited = (int *) malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    secDFSlst(visited, start, lst);
    printf("\nDFS Lst Ended\n");
}

bool isInList(int data, List lst) {
    Node *currentNode = lst.first;
    while (currentNode != NULL) {
        if (data == currentNode->data)
            return 1;
        currentNode = currentNode->next;
    }
    return 0;
}

int **createMatrix(int vertices, List *lst) {
    int **newAdjMatrix = (int **) malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
        newAdjMatrix[i] = (int *) malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (isInList(j, lst[i]))
                newAdjMatrix[i][j] = 1;
            else newAdjMatrix[i][j] = 0;
    return newAdjMatrix;
}

void DFSsecPath(int *visited, int k, int **matrix, int vertices, int length, int endN, int *path, int *resultedPath, int *maxLen) {
    visited[k] = 1;
    path[length]=k;
    if(k == endN) {
        if(*maxLen < length){
            *maxLen=length;
            for(int i=0; i <= length; i++)
                resultedPath[i]=path[i];
        }
    }
    else {
        int *neighbors = getNeighbors(k, matrix, vertices);
        for (int i = 0; i < getNoOfNeighbors(k, matrix, vertices); i++)
            if (visited[neighbors[i]] == 0) {
                visited[neighbors[i]] = 1;
                DFSsecPath(visited, neighbors[i], matrix, vertices, length + 1, endN, path, resultedPath, maxLen);
                visited[neighbors[i]] = 0;
            }
    }
}

void DFSpath(int start, int vertices, int **matrix, int endN) {
    printf("DFS Longest Path Started\n");
    int *visited = (int *) malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    int *path = (int *) malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        path[i] = -1;
    int *resultPath=(int *)malloc(vertices * sizeof(int));
    int maxLength=0;
    DFSsecPath(visited, start, matrix, vertices, 0, endN, path, resultPath, &maxLength);
    for(int i=0;path[i]!=-1&& i<=maxLength;i++)
        printf("%d",resultPath[i]);
    printf("\nDFS Longest Path Ended\n");

}