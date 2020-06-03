#include <stdio.h>
#include <stdlib.h>

#define SEEN 1
#define NOTSEEN 0

typedef struct _node {
    int data;
    struct _node *next;
} nodeT;

typedef struct _list {
    nodeT *first, *last;
} nodeL;


int **readAdjacencyMatrix(FILE *in, int *noOfVertices) {
    fscanf(in, "%d", noOfVertices);
    fgetc(in);
    int **matrix = (int **) malloc((*noOfVertices) * sizeof(int *));
    for (int i = 0; i < (*noOfVertices); i++) {
        matrix[i] = (int *) malloc((*noOfVertices) * sizeof(int *));
        for (int j = 0; j < (*noOfVertices); j++) {
            fscanf(in, "%d", &matrix[i][j]);
            fgetc(in);
        }
    }
    return matrix;
}

void printMatrix(int **adjacencyMatrix, int noOfVertices) {
    for (int i = 0; i < noOfVertices; i++) {
        for (int j = 0; j < noOfVertices; ++j) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void addLast(nodeL *list, int value) {
    if (list->first == NULL) {
        list->first = (nodeT *) malloc(sizeof(nodeT));
        list->first->data = value;
        list->first->next = NULL;
        list->last = list->first;
    } else {
        nodeT *newNode = (nodeT *) malloc(sizeof(nodeT));
        newNode->data = value;
        newNode->next = NULL;
        list->last->next = newNode;
        list->last = newNode;
    }
}

nodeL *getListFromMatrix(int **matrix, int noOfVertices) {
    nodeL *adjList = (nodeL *) malloc(noOfVertices * sizeof(nodeL));
    for (int i = 0; i < noOfVertices; i++) {
        adjList[i].first = NULL;
        adjList[i].last = NULL;
        for (int j = 0; j < noOfVertices; ++j) {
            if (matrix[i][j])
                addLast(&adjList[i], j + 1);
        }
    }
    return adjList;
}


void printAdjList(nodeL *pList, int noOfVertices) {
    nodeT *currNode;
    for (int i = 0; i < noOfVertices; i++) {
        printf("%d: ", i + 1);
        currNode = pList[i].first;
        while (currNode != NULL) {
            printf("%d ", currNode->data);
            currNode = currNode->next;
        }
        printf("\n");
    }
}

int **getMatrixFromList(nodeL *pList, int noOfVertices) {
    int **matrix = (int **) malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i < noOfVertices; ++i) {
        matrix[i] = (int *) malloc(noOfVertices * sizeof(int));
        nodeT *currentNode = pList[i].first;
        while (currentNode) {
            matrix[i][currentNode->data - 1] = 1;
            currentNode = currentNode->next;
        }
    }
    for (int i = 0; i < noOfVertices; ++i) {
        for (int j = 0; j < noOfVertices; ++j) {
            if (matrix[i][j] != 1)
                matrix[i][j] = 0;
        }

    }
    return matrix;
}

void enqueue(nodeL *list, int value) {
    if (list->first == NULL) {
        list->first = (nodeT *) malloc(sizeof(nodeT));
        list->first->data = value;
        list->first->next = NULL;
        list->last = list->first;
    } else {
        nodeT *newNode = (nodeT *) malloc(sizeof(nodeT));
        newNode->data = value;
        newNode->next = NULL;
        list->last->next = newNode;
        list->last = newNode;
    }
}

int dequeue(nodeL *list) {
    int data;
    if (list->first) {
        data = list->first->data;
        list->first = list->first->next;
    }

    if (list->first == NULL)
        list->last = NULL;

    return data;
}

int getNoOfNeighbors(nodeL *pList, int indexNode) {
    int n = 0;
    nodeT *currentNeighbor = pList[indexNode].first;
    while (currentNeighbor) {
        n++;
        currentNeighbor = currentNeighbor->next;
    }
    return n;
}

int *getNeighbors(nodeL *pList, int indexNode, int nrOfNeighbors) {
    int *neighbors = (int *) malloc(nrOfNeighbors * sizeof(int));
    int i = 0;
    nodeT *currentNeighbor = pList[indexNode].first;
    while (currentNeighbor) {
        neighbors[i] = currentNeighbor->data - 1;
        i++;
        currentNeighbor = currentNeighbor->next;
    }
    return neighbors;
}

void bfs(int startNode, nodeL *adjList, int noOfVertices) {
    startNode--;
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < noOfVertices; i++) {
        visited[i] = NOTSEEN;
    }
    nodeL *queue = (nodeL *) malloc(sizeof(nodeL));
    queue->first = queue->last = NULL;
    enqueue(queue, startNode);
    visited[startNode] = SEEN;
    printf("%d ", startNode + 1);

    while (queue->first != NULL) {
        v = dequeue(queue);

        int nrOfNeighbors = getNoOfNeighbors(adjList, v);
        int *neighbors = getNeighbors(adjList, v, nrOfNeighbors);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == NOTSEEN) {
                printf("%d ", w + 1);
                enqueue(queue, w);
                visited[w] = SEEN;
            }
        }
    }

    printf("\nBFS end\n\n");
}

void dfs(int v, int *visited, nodeL *adjList) {
    int i;
    visited[v] = SEEN;
    int nrOfNeighbors = getNoOfNeighbors(adjList, v);
    int *neighbors = getNeighbors(adjList, v, nrOfNeighbors);
    printf("%d ", v + 1);
    for (i = 0; i < nrOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == NOTSEEN) {
            dfs(w, visited, adjList);
        }
    }
}

void dfsRecurs(int startNode, nodeL *adjList, int noOfVertices) {
    startNode--;
    printf("DFS rec. start\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < noOfVertices; i++) {
        visited[i] = NOTSEEN;
    }
    dfs(startNode, visited, adjList);
    printf("\nDFS rec. end\n");
}

int main() {
    FILE *in;
    in = fopen("input.txt", "r");
    int noOfVertices;
    int **adjacencyMatrix = readAdjacencyMatrix(in, &noOfVertices);
    nodeL *adjList = getListFromMatrix(adjacencyMatrix, noOfVertices);
    printf("\nThe adjacency list from given adjacency matrix:\n");
    printAdjList(adjList, noOfVertices);
    printf("\nThe given matrix from adjacency list:\n");
    adjacencyMatrix = getMatrixFromList(adjList, noOfVertices);
    printMatrix(adjacencyMatrix, noOfVertices);
    printf("\nBFS start\n");
    bfs(1, adjList, noOfVertices);
    dfsRecurs(1, adjList, noOfVertices);
    return 0;
}