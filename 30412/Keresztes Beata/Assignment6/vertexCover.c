//
// Created by q on 4/14/2020.
//

#include "vertexCover.h"

void vertexCover(int N, int ** A) {
    /*
     * vertex cover approximation
     * it finds the nodes necessary to cover all edges (= each edge must be incident to at least one of these nodes)
     * in fact, it returns the vertices from a maximal matching, as the edges,
     * whose vertices are considered at each step, are disjoint
     * => This vertex cover has size ≤ 2 × minimum_size (optimal solution)
     */
    printf("Vertex cover approximation:\n");
    int * visited = createVisitedArray(N);
    // create an empty list for the vertices
    VlistT * C = createList(N);
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // take an arbitrary edge whose endpoints are not in the list (unvisited)
            if (A[i][j] > 0 && visited[i] == UNVISITED && visited[j] == UNVISITED) {
                // add the endpoints to the list
                addNewNode(C, i);
                addNewNode(C, j);
                /*
                 * mark the vertices as visited, which means all the edges incident on these vertices
                 * will be marked as visited too (and will not be considered at the next step)
                 */
                visited[i] = VISITED;
                visited[j] = VISITED;
            }
        }
    }
    printf("The covered vertices are:\n");
    // print the list of vertices used to cover all edges
    printingList(C);
    free(C);
}

void vertexCoverOpt(int N, int ** A) {
    /*
     * vertex cover approximation by considering the vertices in the decreasing order of their degree;
     * this way, we add first the nodes to which a large number of edges are incident, and so remove most of the edges;
     * for the given example, this algorithm gives a better solution, although this might not be the case for every graph;
     * sometimes for the best solution, we need to pick a node with a smaller degree, but which covers the remaining edges;
     */
    printf("Vertex cover optimized approximation:\n");
    int * visited = createVisitedArray(N);
    // create an empty list for the vertices
    VlistT * C = createList(N);
    while(areAllEdgesCovered(N,A,visited) == 0) {
        // repeat until all edges are incident to at least one of the vertices in the given list
        int first = getMaxDegree(N,A,visited); // get first endpoint of the edge, the vertex with the highest degree
        if(first != -1) {
            // there are unvisited nodes left
            int second = getNextMaxDegree(N, A, visited, first); // get the second endpoint of the edge,
            // adjacent to the first endpoint previously found, and with highest degree
            if (second != -1) {
                // if there are unvisited nodes left
                // add the two endpoints to the list of nodes
                addNewNode(C, first);
                addNewNode(C, second);
                // mark the nodes as visited
                visited[first] = VISITED;
                visited[second] = VISITED;
            }
        }
    }
    printf("The covered vertices are:\n");
    // print the list of vertices used to cover all edges
    printingList(C);
    free(C);
}
int getDegreeOfNode(int N, int ** A, int node) {
    // return the degree of a node
    int degree = 0;
    for(int i = 0; i<N;i++) {
        if(A[node][i]) {
            degree++;
        }
    }
    return degree;
}
int getMaxDegree(int N, int ** A, int * visited) {
    // return the node with max degree
    int maxDegree = 0;
    int maxNode = -1;
    for(int i=0;i<N;i++) {
        int degree = getDegreeOfNode(N,A,i);
        if(visited[i] == UNVISITED) {
            if (degree > maxDegree) {
                maxDegree = degree;
                maxNode = i;
            }
        }
    }
    return maxNode;
}
int getNextMaxDegree(int N, int ** A, int * visited, int node) {
    // return the node with max degree adjacent to the given node
    int maxDegree = 0;
    int nextMaxNode = -1;
    for(int j = 0; j<N; j++) {
        if(A[node][j] > 0 && visited[j] == UNVISITED && visited[node] == UNVISITED) {
            int rank = getDegreeOfNode(N,A,j);
            if(rank> maxDegree) {
                maxDegree = rank;
                nextMaxNode = j;
            }
        }
    }
    return nextMaxNode;
}
int areAllEdgesCovered(int N, int ** A, int * visited) {
    // check if all the edges are covered by the currently visited nodes
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (A[i][j] > 0 && visited[i] == UNVISITED && visited[j] == UNVISITED) {
                // found an edge that was not covered
                return 0;
            }
        }
    }
    return 1;
}
