//
// Created by q on 4/10/2020.
//

#include "graphAlgorithms.h"

void kruskal(int N, int ** A) {
    // kruskal's algorithm: start with min edge and keep adding min.weight edges without forming a cycle until all vertices are covered
    printf("Start of Kruskal's algorithm:\n");
    int * parents = createParentArray(N);
    EdgeT * edges = createEdges(N-1);
    int minCost = 0;
    int edgeCount = 0;
    while(edgeCount < N-1) {
        // find next edge with minimum weight
        EdgeT minEdge = findMinEdge(N,A,parents);
        edges[edgeCount] = minEdge;
        unite(parents,edges[edgeCount]);
        edgeCount++;
        minCost += minEdge.weight;
    }
    printf("min cost = %d\n",minCost);
    printEdges(N-1,edges);
    printf("End of Kruskal's algorithm.\n");
}

EdgeT findMinEdge(int N, int ** A, int * parents) {
    // search for edge with min weight that doesn't close a cycle
    EdgeT minEdge;
    minEdge.weight = MAX_LIMIT;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(A[i][j]!=0 && A[i][j] < minEdge.weight && findParent(parents, i) != findParent(parents, j)) {
                minEdge.weight = A[i][j];
                minEdge.src = i;
                minEdge.dest = j;
            }
        }
    }
    return minEdge;
}
int findParent(int * parents, int node) {
    // find parent of node
    while(parents[node]!= node) {
        node = parents[node];
    }
    return node;
}

int * createParentArray(int M) {
    // create and initialize parents array
    int * parents = (int*)malloc(M*sizeof(int));
    if(parents == NULL) {
        errMessage();
    }
    else {
        for(int i=0;i<M;i++) {
            parents[i] = i;
        }
    }
    return parents;
}

void unite(int * parents, EdgeT edge) {
    int x = edge.src;
    int y = edge.dest;
    int xSet = findParent(parents, x);
    int ySet = findParent(parents, y);
    // unite the two subsets
    if(xSet != ySet) {
        parents[xSet] = ySet;
    }
}

int * createAndInitializeArray(int N, int init) {
    // create and initialize an empty array if integers
    int * array = (int *)malloc(N* sizeof(int));
    if(array == NULL) {
        errMessage();
    }
    else {
        for(int i=0;i<N;i++) {
            array[i] = init;
        }
    }
    return array;
}

void bellmanFord(int N, int ** A, int start) {
    /* bellman-ford algorithm to find shortest distance from start-node to the other nodes
     * similar to dijkstra, but works with negative weights too
     * used on directed graph
     * we have to detect negative cycles!
     */
    printf("Start of Bellman-Ford's algorithm:\n");

    int * previous = createAndInitializeArray(N,UNDEFINED);
    int * distances = createAndInitializeArray(N, MAX_LIMIT);
    int M = getNoOfEdges(N,A);
    EdgeT * edges = getAllEdges(N,A,M);
    distances[start] = 0;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            int s = edges[j].src;
            int d = edges[j].dest;
            if(edges[j].weight + distances[s] < distances[d]) {
                distances[d] = edges[j].weight + distances[s];
                previous[d] = s;
            }
        }
    }
    if(detectNegativeCycle(M, edges,distances) == 0) {
        // if there's negative cycle the solution is not printed
        return;
    }
    // print distances of each node and the corresponding shortest distance path
    printDistances(N,distances);
    for(int i=0;i<N;i++) {
        printf("path from %c to %c: ",'A'+start,'A' + i);
        printPath(i,previous);
        new_line;
    }
    printf("End of Bellman-Ford's algorithm.\n");
}

int getNoOfEdges(int N, int ** A) {
    int noOfEdges = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++){
            if(A[i][j]) {
                noOfEdges++;
            }
        }
    }
    return noOfEdges;
}
EdgeT * getAllEdges(int N, int ** A, int noOfEdges) {
    // create edges array
    EdgeT * e = createEdges(noOfEdges);
    int k=0; // index pf edges
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++){
            if(A[i][j]) {
                e[k].src = i;
                e[k].dest = j;
                e[k].weight = A[i][j];
                k++;
            }
        }
    }
    return e;
}
int detectNegativeCycle(int M,EdgeT * edges, int * distances) {
    // detect if there's a negative cycle
    for (int i = 0; i < M; i++) {
        int s = edges[i].src;
        int d = edges[i].dest;
        if(edges[i].weight+distances[s] < distances[d]) {
            printf("Error: negative cycle detected\n");
            return 0;
        }
    }
    return 1;
}
void printDistances(int N, int * distances) {

    printf("The distances from the source to each node are:\n");
    for(int i=0;i<N;i++) {
        printf("%c: %d",'A' + i, distances[i]);
        new_line;
    }
}
void printPath(int i, int * previous) {
    if(previous[i] != UNDEFINED) {
        printPath(previous[i], previous);
    }
    printf("%c ",i + 'A');
}