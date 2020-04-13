//
// Created by Bori on 4/3/2020.
//

#include "listGraph.h"
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"
#include "edge.h"
#include "deEdge.h"
#include "UnionFind.h"

static void allocateMatrix(mGraph *myGraph) {
    myGraph->edges = (int **) malloc(sizeof(int *) * (myGraph->noNodes + 1));
    for (int i = 1; i <= myGraph->noNodes; i++) {
        myGraph->edges[i] = (int *) malloc(sizeof(int) * (myGraph->noNodes + 1));
    }
}

static void initMatrix(mGraph *myGraph) {
    for (int i = 1; i <= myGraph->noNodes; i++) {
        for (int j = 1; j <= myGraph->noNodes; j++) {
            myGraph->edges[i][j] = 0;
        }
    }
}

lGraph createLGaph_fromAdjMatrix(mGraph *MGraph) {
    lGraph newGraph;
    newGraph.noNodes = MGraph->noNodes;
    newGraph.lists = (list *) malloc(sizeof(list) * (newGraph.noNodes + 1));
    for (int i = 1; i <= newGraph.noNodes; i++) {
        newGraph.lists[i] = createList();
        for (int j = 1; j <= newGraph.noNodes; j++) {
            if (MGraph->edges[i][j]) {
                addLast(&newGraph.lists[i], j, MGraph->edges[i][j]);
            }
        }
    }
    return newGraph;
}

mGraph createMGaph_fromAdjList(lGraph *listGraph) {
    mGraph newGraph;
    newGraph.noNodes = listGraph->noNodes;
    allocateMatrix(&newGraph);
    initMatrix(&newGraph);
    for (int i = 1; i <= newGraph.noNodes; i++) {
        edge *iterator = listGraph->lists[i].first;
        while (iterator != NULL) {
            newGraph.edges[i][iterator->endPoint] = iterator->length;
            iterator = iterator->next;
        }
    }
    return newGraph;
}

void printAdjLists(lGraph *myGraph, FILE *outFile) {
    fprintf(outFile, "The adjacency lists are(endpoint, length of edge): \n");
    for (int i = 1; i <= myGraph->noNodes; i++) {
        fprintf(outFile, "for node %d: ", i);
        printAllList(&myGraph->lists[i], outFile);
    }
}

static bool *l_getVisitedArray(lGraph *myGraph) {
    bool *visited = (bool *) malloc(sizeof(bool) * (myGraph->noNodes + 1));
    for (int i = 1; i < myGraph->noNodes; i++) {
        visited[i] = false;
    }
    return visited;
}


static void l_dfs_helper(lGraph *myGraph, int node, FILE *outFile, bool *visited) {
    fprintf(outFile, "%d ", node);
    visited[node] = true;
    edge *iterator = myGraph->lists[node].first;
    while (iterator != NULL) {
        if (!visited[iterator->endPoint]) {
            l_dfs_helper(myGraph, iterator->endPoint, outFile, visited);
        }
        iterator = iterator->next;
    }
}

void l_dfs(lGraph *myGraph, FILE *outFile, FILE *inFile) {
    fprintf(outFile, "Which is the root of the dfs tree?");
    int root;
    fscanf(inFile, "%d", &root);
    fprintf(outFile, "DFS of the graph(stored with adjacency lists) is: \n");
    bool *visited = l_getVisitedArray(myGraph);
    l_dfs_helper(myGraph, root, outFile, visited);
    fprintf(outFile, "\n");
}

void l_bfs(lGraph *myGraph, FILE *outFile, FILE *inFile) {
    fprintf(outFile, "Which is the root of the bfs tree?");
    int root;
    fscanf(inFile, "%d", &root);
    fprintf(outFile, "BFS of the graph(stored with adjacency lists) is: \n");
    bool *visited = l_getVisitedArray(myGraph);
    Queue bfsQueue = createQueue();
    enqueue(&bfsQueue, root);
    visited[root] = true;
    int frontNode;
    while (!isEmpty(&bfsQueue)) {
        frontNode = dequeue(&bfsQueue);
        fprintf(outFile, "%d ", frontNode);
        edge *iterator = myGraph->lists[frontNode].first;
        while (iterator != NULL) {
            if (!visited[iterator->endPoint]) {
                visited[iterator->endPoint] = true;
                enqueue(&bfsQueue, iterator->endPoint);
            }
            iterator = iterator->next;
        }
    }
    fprintf(outFile, "\n");
}

int* getIntArray(int size, int INIT_VALUE){
    int* array = (int*) malloc(sizeof(int)*size);
    for(int i=1; i<size; i++){
        array[i]=INIT_VALUE;
    }
    return array;
}



/*with a modified dfs I simply check all the siple paths in the graph starting at the given root
modifications with respect to the general dfs: I don't generate a tree --> I may need to visit a node more than once.
 --> in the visited[] array I don't store whether the given node was visited or not in the depth first search until now,
 but whether or not it is on the current path(starting from the root), which was built by the df search
 When I backtrack from a node X, I mark it as unvisited --> I my visit it later again, if it is reachable thorugh an other path as well form the root
 */


void longest_path_dfs(lGraph *myGraph, int node, int dest, int* distances, bool *nowVisited, list *currPath, int currPathLength,
                      int *longestPathLegth, list *longestPath) {
    if (node != dest) {
        nowVisited[node] = true;
        edge *iterator = myGraph->lists[node].first;
        while (iterator != NULL) {
            if (!nowVisited[iterator->endPoint] && distances[iterator->endPoint]>distances[node]+iterator->length) { //otherwise, it's not worth visiting it again
                addLast(currPath, iterator->endPoint, iterator->length);
                longest_path_dfs(myGraph, iterator->endPoint, dest, distances, nowVisited, currPath,
                                 currPathLength + iterator->length, longestPathLegth, longestPath);
                deleteLast(currPath);
            }
            iterator = iterator->next;
        }
        nowVisited[node] = false;
    } else {
        if (currPathLength > *longestPathLegth) {
            *longestPathLegth = currPathLength;
            deleteAll(longestPath);
            edge *iterator = currPath->first;
            while (iterator != NULL) {
                addLast(longestPath, iterator->endPoint, iterator->length);
                iterator = iterator->next;
            }
        }
    }
}

list findLongestPath(lGraph *myGraph, int source, int dest) {
    list longestPath = createList();
    list currPath = createList();
    addLast(&currPath, source, 0);
    bool *nowVisited = l_getVisitedArray(myGraph);
    int* distances = getIntArray(myGraph->noNodes+1, INT_MAX);
    distances[source]=0;
    int longestPathLength = 0;
    longest_path_dfs(myGraph, source, dest, distances, nowVisited, &currPath, 0, &longestPathLength, &longestPath);
    return longestPath;
}

deEdge* findMinimumFrontierEdge(lGraph* myGraph, bool* visited){ //!!! runs in e, not log e, as it would mi optimal
    int minCost = INT_MAX;
    deEdge* minEdge = NULL;
    for(int i=1; i<=myGraph->noNodes; i++){
        if(visited[i]){
            edge* iterator = myGraph->lists[i].first;
            while(iterator!=NULL){
                if(!visited[iterator->endPoint] && iterator->length<minCost) {
                    free(minEdge);
                    minEdge = createDeEdge(i, iterator->endPoint, iterator->length);
                    minCost = iterator->length;
                }
                iterator=iterator->next;
            }
        }
    }
    return minEdge;
}

void primsAlgorithm(lGraph *myGraph){ //O(ve), not O(vloge)
    printf("Prims algorithms for this graph:\n");
    int startNode;
    printf("Which is the root of the Prim-tree?");
    fscanf(stdin, "%d", &startNode);
    bool* visited = l_getVisitedArray(myGraph);
    visited[startNode]=true;
    int noVisitedNodes = 1;
    int minCost = 0;
    deEdge* frontierEdge;
    printf("the edges in the prim tree are:\n");
    while(noVisitedNodes<myGraph->noNodes){
        frontierEdge = findMinimumFrontierEdge(myGraph, visited);
        printf("(%d, %d, %d)\n",  frontierEdge->endp1, frontierEdge->endp2,  frontierEdge->length);
        visited[frontierEdge->endp2]=true;
        noVisitedNodes++;
    }
}

deEdge* findMinDistanceEdge(lGraph* myGraph, bool* visited, int* distances, int* prevs){ //O(v)
    int minDist = INT_MAX;
    deEdge* minEdge = NULL;
    for(int i=1; i<=myGraph->noNodes; i++){
        if(!visited[i] && distances[i]<minDist){
            minEdge = createDeEdge(prevs[i], i, distances[i]-distances[prevs[i]]);
            minDist = distances[i];
        }
    }
    return minEdge;
}

void updateDistances(lGraph* myGraph, int addedNode,  bool* visited, int* distances, int* prevs){ //O(v)
    edge* iterator = myGraph->lists[addedNode].first;
    while(iterator!=NULL){
        if(!visited[iterator->endPoint] && distances[iterator->endPoint]>distances[addedNode]+iterator->length){
            distances[iterator->endPoint]=distances[addedNode]+iterator->length;
            prevs[iterator->endPoint]=addedNode;
        }
        iterator=iterator->next;
    }
}

void printDistances(lGraph* myGraph, int root, int* distances, char* algorithm){
    printf("The distances obtained with %s's algorithm are:\n", algorithm);
    for(int i=1; i<=myGraph->noNodes; i++) {
        printf("From node %d to %d the distance is %d\n", root, i, distances[i]);
    }
}

void dijkstraAlgorithm(lGraph *myGraph){
    printf("Dijkstra algorithm for this graph: \n");
    int startNode;
    printf("Which is the root of the Dijkstra-tree?");
    fscanf(stdin, "%d", &startNode);

    bool* visited = l_getVisitedArray(myGraph);
    int* distances = getIntArray(myGraph->noNodes+1, INT_MAX);
    int* prevs = getIntArray(myGraph->noNodes+1, -1);

    distances[startNode]=0;
    prevs[startNode]=0;
    visited[startNode]=true;
    updateDistances(myGraph, startNode, visited, distances, prevs);

    int noVisitedNodes = 1;
    deEdge* frontierEdge;
    printf("the edges in the Dijsktra tree are:\n");
    while(noVisitedNodes<myGraph->noNodes){
        frontierEdge = findMinDistanceEdge(myGraph, visited, distances, prevs);
        printf("New edge: (%d, %d, %d)\n",  frontierEdge->endp1, frontierEdge->endp2,  frontierEdge->length);
        printf("--> the distance to node %d is %d\n", frontierEdge->endp2, distances[frontierEdge->endp2]);
        visited[frontierEdge->endp2]=true;
        updateDistances(myGraph, frontierEdge->endp2, visited, distances, prevs);
        noVisitedNodes++;
    }

    printDistances(myGraph, startNode, distances, "Dijkstra");
}

void BellmanFordAlgorithm(lGraph* myGraph){
    int startNode;
    printf("Which is the root of the Bellman_Ford-tree?");
    fscanf(stdin, "%d", &startNode);
    int* distances = getIntArray(myGraph->noNodes+1, INT_MAX);
    distances[startNode]=0;
    edge* iterator;
    for(int i=1; i<=myGraph->noNodes-1; i++) { //iterate v-1 times
        for (int j = 1; j <= myGraph->noNodes; j++) {//through all the edges{
            iterator = myGraph->lists[j].first;
            if (distances[j] != INT_MAX) {
                while (iterator != NULL) {
                    if (distances[iterator->endPoint] > distances[j] + iterator->length) {
                        distances[iterator->endPoint] = distances[j] + iterator->length;
                    }
                    iterator = iterator->next;
                }
            }
        }
    }

    printDistances(myGraph, startNode, distances, "Bellman-Ford");
}

int noEdges(lGraph* myGraph){
    int result = 0;
    for(int i=1; i<=myGraph->noNodes; i++){
        result+=myGraph->lists[i].size;
    }
    return result/2;
}

deEdge* getEdgesArray(lGraph* myGraph, int noEdgesInGraph){
    deEdge* edges = (deEdge*) malloc(sizeof(deEdge)*noEdgesInGraph);
    int index=0;
    for(int i=1; i<=myGraph->noNodes; i++){
        edge* iterator = myGraph->lists[i].first;
        while(iterator!=NULL){
            if(iterator->endPoint>i) { //otherwise, it was counted before
                edges[index] = *createDeEdge(i, iterator->endPoint, iterator->length);
                index++;
            }
            iterator=iterator->next;
        }
    }
    return edges;
}

int compareEdges_nonVoid(deEdge* a, deEdge* b){
    return a->length-b->length;
}

int compareEdges(const void* a, const void* b){
    return compareEdges_nonVoid(a, b);
}

void kruskalAlgorithm(lGraph* myGraph){
    printf("-------Kruskal algorithm--------\n");
    UnionFind myUF = createUnionFind(myGraph->noNodes);
    int noEdgesInGraph = noEdges(myGraph);
    deEdge* edges = getEdgesArray(myGraph, noEdgesInGraph);
    qsort(edges, noEdgesInGraph, sizeof(deEdge), compareEdges);
    printf("The edges in the minimum spanning tree are\n");

    int sumOfLengths=0;
    int noFoundEdges=0;
    for(int i=0; i<noEdgesInGraph && noFoundEdges<myGraph->noNodes-1; i++){
        if(!find(&myUF, edges[i].endp1, edges[i].endp2)){
            union_f(&myUF, edges[i].endp1, edges[i].endp2);
            printf("(%d, %d) with length %d\n", edges[i].endp1, edges[i].endp2, edges[i].length);
            sumOfLengths+=edges[i].length;
            noFoundEdges++;
        }
    }
}
