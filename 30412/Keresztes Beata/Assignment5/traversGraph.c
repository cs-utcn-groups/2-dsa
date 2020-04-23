//
// Created by q on 4/2/2020.
//

#include "traversGraph.h"

void BFS(int N, ListT * AL, int startNode) {
    /*
     * breadth-first-search
     */
    printf("BFS:\n");
    int * v = createVisitedArray(N); // create visited array
    QueueT * queue = createQueue();
    enqueue(queue,startNode); // add startNode to queue
    v[startNode] = VISITED;
    printf("%c ",'A' + startNode);
    while(!isEmptyQueue(queue)) {
        // if queue is not empty dequeue last node and add its unvisited neighbours
        int node = dequeue(queue);
        int * neighbours = getNeighbours(AL[node]);
        for(int i=0; i<AL[node].count; i++) {
            if(v[neighbours[i]] == UNVISITED) {
                enqueue(queue,neighbours[i]);
                v[neighbours[i]] = VISITED;
                printf("%c ",'A' + neighbours[i]);
            }
        }
    }
    new_line;
}
void DFS(int N, ListT * AL, int startNode) {
    /*
     * iterative depth-first-search
     */
    printf("DFS:\n");
    int * v = createVisitedArray(N); // create visited array
    StackT * stack = createStack();
    push(stack,startNode);  // push first node
    while(!isEmptyStack(stack)) {
        // if stack is not empty remove top node and add all its unvisited neighbours
        int node = pop(stack);
        if (v[node] == UNVISITED) {
            printf("%c ", 'A' + node);
            v[node] = VISITED;
            int * neighbours = getNeighbours(AL[node]);
            for(int i = AL[node].count-1 ; i>=0; i--) {
                if(v[neighbours[i]] == UNVISITED) {
                    push(stack, neighbours[i]);
                }
            }
            free(neighbours);
        }
    }
    new_line;
    free(v);
    free(stack);
}

void DFSRec(int N, ListT * AL, int startNode) {
    /*
     * recursive depth-first-search
     */
    printf("DFS:\n");
    int * v = createVisitedArray(N); // create visited array
    auxRec(startNode,AL,v);
    new_line;
}

void auxRec(int node, ListT * AL, int * v) {
    // auxiliary recursive function for dfs traversal
    printf("%c ", 'A' + node);
    v[node] = VISITED;
    int * neighbours = getNeighbours(AL[node]);
    for(int i=0; i< AL[node].count; i++) {
        if(v[neighbours[i]] == UNVISITED) {
            auxRec(neighbours[i],AL,v);
        }
    }
    free(neighbours);
}

int * createVisitedArray(int N) {
    // create and initialize visited array
    int * visited = (int *)malloc(sizeof(int) * N);
    for(int i=0;i<N;i++) {
        visited[i] = UNVISITED;
    }
    return visited;
}

int * getNeighbours(ListT list) {
    // function to get the neighbours of a node
    int n = list.count;
    int * neighbours = (int *)malloc(sizeof(int) * n);
    NodeT * temp = list.head;
    for(int i=0; i<n; i++) {
        neighbours[i] = temp->data;
        temp = temp->next;
    }
    return neighbours;
}

