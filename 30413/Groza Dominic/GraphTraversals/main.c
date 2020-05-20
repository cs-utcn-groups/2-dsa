//DIJKSTRA AND PRIM


#include <stdio.h>
#include <stdlib.h>

#define MAX 99999999
#define VISITED 1
#define UNVISITED 0
#define UNDEFINED -1

int nrOfVertices;
int **adjMatrix;
typedef struct edge {
    int source;
    int destination;
    int weight;
} edgeT;
typedef struct node {
    int content;
    struct node *next;
} NodeT;
NodeT *stack;

NodeT *createNode(int content) {
    NodeT *new = (NodeT *) malloc(sizeof(NodeT));
    new->content = content;
    new->next = NULL;
    return new;
}

void pop() {
   if (stack!=NULL){
       stack=stack->next;
   }
}
void push(int content){
    NodeT *new=createNode(content);
    new->next=stack;
    stack=new;

}

NodeT *peekStack() {
    return stack;
}

int isEmptyStack() {
    return stack == NULL;
}

void readFromAdjMatrix(FILE *f) {
    int n;
    fscanf(f, "%d", &n);
    nrOfVertices = n;
    adjMatrix = (int **) malloc(sizeof(int *) * nrOfVertices);
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int *) malloc(sizeof(int) * nrOfVertices);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(f, "%d", &adjMatrix[i][j]);
    fclose(f);

}

edgeT getMinEdgeForCurrentlyVisitedNodes(const int *visited) {
    edgeT minEdge;
    minEdge.weight = MAX;

    for (int i = 0; i < nrOfVertices; i++) {
        for (int j = 0; j < nrOfVertices; j++) {
            if (visited[i] == VISITED && visited[j] == UNVISITED && adjMatrix[i][j] > 0) {
                minEdge.source = i;
                minEdge.destination = j;
                minEdge.weight = adjMatrix[i][j];
            }
        }
    }
    return minEdge;
}

void printEdges(edgeT *edges, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c -> %c\t", edges[i].source + 'A', edges[i].destination + 'A');
    }
    printf("\n");
}

int getMinDistanceVertex(const int *distance, const int *visited) {
    int min = MAX;
    int minV = 0;
    for (int i = 0; i < nrOfVertices; i++) {
        if (distance[i] < min && visited[i] == UNVISITED) {
            minV = i;
        }
    }
    return minV;
}

int getNumberOfNeighborsOfVertex(int v) {
    if (v < nrOfVertices) {
        int nrOfNeighbors = 0;
        for (int i = 0; i < nrOfVertices; i++) {
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
    if (v < nrOfVertices) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int j = 0;
        for (int i = 0; i < nrOfVertices; i++) {
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

void prim(int startNode) {
    printf("Started Prim's Algorithm\n");

    int nrVerticesVisited = 0, minCost = 0;
    int *visited = (int *) malloc(sizeof(int) * nrOfVertices);
    for (int i = 0; i < nrOfVertices; i++) {
        visited[i] = UNVISITED;
    }

    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (nrOfVertices - 1));
    visited[startNode] = VISITED;

    while (nrVerticesVisited < nrOfVertices - 1) {
        edgeT minEdge = getMinEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination] = VISITED;
        edges[nrVerticesVisited++] = minEdge;
        minCost += minEdge.weight;
    }

    printEdges(edges, nrVerticesVisited);
    printf("Cost of MST by Prim alg is : %d \n", minCost);
    printf("Prim's alg ended\n\n");
}


void dijkstra(int startNode) {
    printf("Dijkstra started\n");

    int *distances = (int *) malloc(nrOfVertices * sizeof(int));
    int *previous = (int *) malloc(nrOfVertices * sizeof(int));
    int *visited = (int *) malloc(nrOfVertices * sizeof(int));
    int nrOfVisitedVertices = 0;
    for (int i = 0; i < nrOfVertices; i++) {
        distances[i] = MAX;
        previous[i] = UNDEFINED;
        visited[i] = UNVISITED;
    }
    distances[startNode] = 0;

    while (nrOfVisitedVertices < nrOfVertices) {
        int u = getMinDistanceVertex(distances, visited);
        visited[u] = VISITED;

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
        int *neighbors = getNeighborsOfVertex(u);
        for (int i = 0; i < nrOfNeighbors; i++) {
            int w = neighbors[i];
            int alt = distances[u] + adjMatrix[u][w];
            if (alt < distances[w]) {
                distances[w] = alt;
                previous[w] = u;
            }
        }
        nrOfVisitedVertices++;
    }
    for (int i = 0; i < nrOfVertices; i++) {
        int u = i;
        if (i != startNode) {
            while (previous[u] != UNDEFINED) {
                push(u);
                u = previous[u];
            }
            printf("path from %c to %c is : %c", startNode + 'A', i + 'A', startNode + 'A');
            while(!isEmptyStack()){
                printf(" -> %c",peekStack()->content+'A');
                pop();
            }
            printf("\n");
        }
    }
    printf("Dijkstra ended\n");
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
