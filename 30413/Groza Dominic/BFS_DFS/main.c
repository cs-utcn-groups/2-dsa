#include <stdio.h>
#include <stdlib.h>
#define UNVISITED 0
#define VISITED 1

typedef struct edge {
    int source;
    int destination;
} edgeT;

typedef struct node {
    int content;
    struct node *next;
} NodeT;

NodeT *stack;
NodeT *queue;

NodeT *createNode(int content) {
    NodeT *new = (NodeT *) malloc(sizeof(NodeT));
    new->content = content;
    new->next = NULL;
    return new;
}

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

NodeT *peekqueue() {
    return queue;
}

int isEmptyQueue() {
    return queue == NULL;
}

void push(int content){
    NodeT *new=createNode(content);
    new->next=stack;
    stack=new;
}

void pop (){
    if (stack!=NULL){
        stack=stack->next;
    }
}

NodeT *peekStack(){
    return stack;
}

int isEmptyStack() {
    return stack == NULL;
}
int nrOfVertexes;
int **adjMatrix;

void readFromAdjMatrix(FILE *f) {
    int n;
    fscanf(f, "%d", &n);
    nrOfVertexes = n;
    adjMatrix = (int **) malloc(sizeof(int *) * nrOfVertexes);
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int *) malloc(sizeof(int) * nrOfVertexes);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    fclose(f);

}

void printAdjMatrix() {
    printf("\n The matrix is:\n");
    for (int i = 0; i < nrOfVertexes; i++) {
        printf("%c  ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < nrOfVertexes; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < nrOfVertexes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int getNumberOfNeighborsOfVertex(int v) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = 0;
        for (int i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    } else {
        return 0;
    }

}

int *getNeighborsOfVertex(int v) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int j = 0;
        for (int i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
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
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertexes; i++){
        visited[i]=UNVISITED;
    }
    enqueue(startNode);
    visited[startNode]=VISITED;
    printf("%c ",startNode+ 'A');

    while (!isEmptyQueue()){
        v=peekqueue()->content;
        dequeue();

        int nrOfNeighbors=getNumberOfNeighborsOfVertex(v);
        int *neighbors=getNeighborsOfVertex(v);
        for (i=0;i<nrOfNeighbors;i++){
            w=neighbors[i];
            if(visited[w]==0){ // unvisited
                printf("%c ",w+'A');
                enqueue(w);
                visited[w]=VISITED;
            }
        }
    }
    printf("\n BFS ended \n");
}

void dfs(int startNode){
    printf("DFS started \n");
    int *visited=(int*)malloc(nrOfVertexes*sizeof(int));
    int i,v,w;
    for (i=0;i<nrOfVertexes;i++){
        visited[i]=UNVISITED;
    }
    push(startNode);
    while (!isEmptyStack()){
        v=peekStack()->content;
        pop();

        if (visited[v]==0){ //unvisited
            visited[v]=VISITED;
            int nrOfNeighbors=getNumberOfNeighborsOfVertex(v);
            int *neighbors=getNeighborsOfVertex(v);
            for(i=nrOfNeighbors-1;i>=0;i--){
                w=neighbors[i];
                if(visited[w] == UNVISITED){
                    push(w);
                }
            }
            printf("%c ",v + 'A');
        }
    }
    printf("\n DFS ENDED\n");
}

void dfsREC(int v, int *visited){
    int i;
    visited[v]=VISITED;
    int nrOfNeighbors=getNumberOfNeighborsOfVertex(v);
    int *neighbors=getNeighborsOfVertex(v);
    printf("%c ",v+'A');
    for (i=0;i<nrOfNeighbors;i++){
        int w=neighbors[i];
        if (visited[w]==UNVISITED){
            dfsREC(w,visited);
        }
    }
}

void dfsRecurs(int startNode){
    printf("\n Recursive DFS started \n");
    int *visited=(int*)malloc(sizeof(int)*nrOfVertexes);
    int i,v,w;

    for (i=0;i<nrOfVertexes;i++){
        visited[i]=UNVISITED;
    }
    dfsREC(startNode,visited);
    printf("\n DFS recursive ended \n\n");
}

int main() {
    FILE *f=fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs('G'-'A');
    dfs('G'-'A');
    dfsRecurs('G'-'A');
    return 0;
};
