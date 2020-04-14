#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define maxLengthOfString 60
#define nrOfVertices 5

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity) {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (int *) malloc(queue->capacity * sizeof(int));
    return queue;
}

int QisFull(struct Queue *queue) { return (queue->size == queue->capacity); }

void enqueue(struct Queue *queue, int item) {
    if (QisFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int QisEmpty(struct Queue *queue) { return (queue->size == 0); }

int dequeue(struct Queue *queue) {
    if (QisEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));
    return stack;
}

int SisFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int SisEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int item) {
    if (SisFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if (SisEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int peek(struct Stack *stack) {
    if (SisEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

int *readVertices(FILE *f) {
    int *array = (int *) malloc(sizeof(int) * 10);
    char *buffer = (char *) malloc(sizeof(char) * maxLengthOfString);
    fgets(buffer, maxLengthOfString, f);
    char *pch = strtok(buffer, " ");
    pch = strtok(NULL, " ");
    pch = strtok(NULL, " ");
    int nr = 0;
    while (pch != NULL) {
        array[nr] = atoi(pch);
        nr++;
        pch = strtok(NULL, " ");
    }
    return array;
}

int encodeVertex(int vertex, int *arr) {
    int code = 0;
    for (int i = 0; i < nrOfVertices; i++) {
        if (vertex == arr[i]) {
            code = i;
        }
    }
    return code;
}

int **readEdges(FILE *f, int *array) {
    char *buffer = (char *) malloc(sizeof(char) * maxLengthOfString);
    int **matrix = (int **) malloc(sizeof(int *) * nrOfVertices);
    for (int i = 0; i < nrOfVertices; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * nrOfVertices);
    }
    for (int i = 0; i < nrOfVertices; i++) {
        for (int j = 0; j < nrOfVertices; j++) {
            matrix[i][j] = 0;
        }
    }
    fgets(buffer, maxLengthOfString, f);
    char *pch = strtok(buffer, " ");
    pch = strtok(NULL, " ");
    pch = strtok(NULL, ")");
    int source = atoi(&pch[1]);
    int destination = atoi(&pch[3]);
    matrix[encodeVertex(source, array)][encodeVertex(destination, array)] = 1;
    matrix[encodeVertex(destination, array)][encodeVertex(source, array)] = 1;
    pch = strtok(NULL, ")");
    while (pch != NULL) {
        int src = atoi(&pch[2]);
        int dest = atoi(&pch[4]);
        matrix[encodeVertex(src, array)][encodeVertex(dest, array)] = 1;
        matrix[encodeVertex(dest, array)][encodeVertex(src, array)] = 1;
        pch = strtok(NULL, ")");
    }
    return matrix;
}

void printMatrix(int **mat) {
    for (int i = 0; i < nrOfVertices; i++) {
        for (int j = 0; j < nrOfVertices; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

enum {
    UNVISITED, VISITED
};

void BFS(int srcNode, int *arr, int **matrix) {
    int mark[nrOfVertices];
    int w = 0;
    struct Queue *Q = createQueue(nrOfVertices);
    for (int i = 0; i < nrOfVertices; i++) {
        mark[i] = UNVISITED;
    }
    mark[encodeVertex(srcNode, arr)] = VISITED;
    printf("BFS: %d ", srcNode);
    enqueue(Q, encodeVertex(srcNode, arr));
    while (!QisEmpty(Q)) {
        int v = dequeue(Q);
        for (int i = 0; i < nrOfVertices; i++) {
            if (matrix[v][i] == 1) {
                w = i;
            }
            if (mark[w] == UNVISITED) {
                mark[w] = VISITED;
                printf("%d ", arr[w]);
                enqueue(Q, w);
            }
        }
    }
    printf("\n");
}

void DFS(int srcNode, int *arr, int **matrix) {
    int mark[nrOfVertices];
    int w = 0;
    struct Stack *S = createStack(nrOfVertices);
    for (int i = 0; i < nrOfVertices; i++) {
        mark[i] = UNVISITED;
    }
    mark[encodeVertex(srcNode, arr)] = VISITED;
    printf("DFS: %d ", srcNode);

    push(S, encodeVertex(srcNode, arr));
    while (!SisEmpty(S)) {
        int v = peek(S);
        for (int i = v + 1; i < nrOfVertices; i++) {
            if (matrix[v][i] == 1) {
                if (mark[i] == UNVISITED) {
                    w = i;
                    break;
                } else
                    continue;
            }
        }
        if (mark[w] == UNVISITED) {
            mark[w] = VISITED;
            printf("%d ", arr[w]);
            push(S, w);
        } else {
            pop(S);
        }
    }
    printf("\n");
}

int main() {
    FILE *f;
    f = fopen("input.txt", "r");

    int *arrayOfVertices = readVertices(f);
    int **adjMatrix = readEdges(f, arrayOfVertices);

    BFS(1, arrayOfVertices, adjMatrix);
    DFS(1, arrayOfVertices, adjMatrix);

    fclose(f);
    return 0;
}