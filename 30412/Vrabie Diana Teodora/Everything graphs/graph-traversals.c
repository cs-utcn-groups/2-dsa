//
// Created by diana on 09/05/2020.
//

#include "graph-traversals.h"

void fillVisited(int nrOfElements) {
    visited = (bool *) malloc(nrOfElements * sizeof(bool));
    for (int i = 0; i < nrOfElements; ++i) {
        visited[i] = false;
    }
}

void doMatrixDFS(AdjMatrix *adjMatrix, int startVertex, struct _iobuf *buffer) {
    fprintf(buffer, "%d ", startVertex);
    visited[startVertex] = true;
    for (int i = 0; i < adjMatrix->nrOfVertices; ++i) {
        if (adjMatrix->matrix[startVertex][i] != 0 && (!visited[i])) {
            doMatrixDFS(adjMatrix, i, buffer);
        }
    }
}

void matrixDFS(AdjMatrix *adjMatrix, int startVertex, struct _iobuf *buffer) {
    fprintf(buffer, "\nDFS on adjacency matrix:\n");
    fillVisited(adjMatrix->nrOfVertices);
    doMatrixDFS(adjMatrix, startVertex, buffer);
}

void doListDFS(Graph *graph, int startVertex, struct _iobuf *buffer) {
    fprintf(buffer, "%d ", startVertex);
    visited[startVertex] = true;
    ListNode *crawl = graph->nodesArray[startVertex].head;
    while (crawl != NULL) {
        if (visited[crawl->key] == false) {
            doListDFS(graph, crawl->key, buffer);
        }
        crawl = crawl->next;
    }
}

void listDFS(Graph *graph, int startVertex, struct _iobuf *buffer) {
    fprintf(buffer, "\nDFS on adjacency list: \n");
    fillVisited(graph->nrOfVertices);
    doListDFS(graph, startVertex, buffer);
}

void iterativeListDFS(Graph *graph, int startVertex, struct _iobuf *buffer) {
    fprintf(buffer, "\nIterative DFS on adjacency list: \n");
    fillVisited(graph->nrOfVertices);
    Stack *stack = initializeStack();
    push(startVertex, stack);

    while (!isStackEmpty(stack)) {
        startVertex = pop(stack)->value;
        if (!visited[startVertex]) {
            fprintf(buffer, "%d ", startVertex);
            visited[startVertex] = true;
        }

        ListNode *crawl = graph->nodesArray[startVertex].head;
        while (crawl != NULL) {
            if (!visited[crawl->key]) {
                push(crawl->key, stack);
            }
            crawl = crawl->next;
        }
    }
}

void iterativeListBFS(Graph *graph, int startVertex, struct _iobuf *buffer) {
    fprintf(buffer, "\nIterative BFS on adjacency list: \n");
    fillVisited(graph->nrOfVertices);
    Queue *queue = initializeQueue();

    visited[startVertex] = true;
    enqueue(startVertex, queue);

    while (!isQueueEmpty(queue)) {
        startVertex = dequeue(queue)->value;
        fprintf(buffer, "%d ", startVertex);

        ListNode *crawl = graph->nodesArray[startVertex].head;
        while (crawl!= NULL) {
            if (!visited[crawl->key]) {
                visited[crawl->key] = true;
                enqueue(crawl->key, queue);
            }
            crawl = crawl->next;
        }
    }
}
