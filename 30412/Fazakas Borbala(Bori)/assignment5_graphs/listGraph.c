//
// Created by Bori on 4/3/2020.
//

#include "listGraph.h"
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"
#include "edge.h"

static void allocateMatrix(mGraph* myGraph){
    myGraph->edges = (int**) malloc(sizeof(int*)*(myGraph->noNodes+1));
    for(int i=1; i<=myGraph->noNodes; i++){
        myGraph->edges[i] = (int*) malloc(sizeof(int)*(myGraph->noNodes+1));
    }
}

static void initMatrix(mGraph* myGraph){
    for(int i=1; i<=myGraph->noNodes; i++){
        for(int j=1; j<=myGraph->noNodes; j++){
            myGraph->edges[i][j]=0;
        }
    }
}

lGraph createLGaph_fromAdjMatrix(mGraph* MGraph){
    lGraph newGraph;
    newGraph.noNodes = MGraph->noNodes;
    newGraph.lists = (list*) malloc(sizeof(list)*(newGraph.noNodes+1));
    for(int i=1; i<=newGraph.noNodes; i++){
        newGraph.lists[i] = createList();
        for(int j=1; j<=newGraph.noNodes; j++){
            if(MGraph->edges[i][j]){
                addLast(&newGraph.lists[i], j, MGraph->edges[i][j]);
            }
        }
    }
    return newGraph;
}

mGraph createMGaph_fromAdjList(lGraph* listGraph)
{
    mGraph newGraph;
    newGraph.noNodes = listGraph->noNodes;
    allocateMatrix(&newGraph);
    initMatrix(&newGraph);
    for(int i=1; i<=newGraph.noNodes; i++){
        edge* iterator = listGraph->lists[i].first;
        while(iterator!=NULL){
            newGraph.edges[i][iterator->endPoint]=iterator->length;
            iterator = iterator->next;
        }
    }
    return newGraph;
}

void printAdjLists(lGraph* myGraph, FILE* outFile){
    fprintf(outFile, "The adjacency lists are(endpoint, length of edge): \n");
    for(int i=1; i<=myGraph->noNodes; i++){
        fprintf(outFile, "for node %d: ", i);
        printAllList(&myGraph->lists[i], outFile);
    }
}

static bool* l_getVisitedArray(lGraph* myGraph){
    bool* visited = (bool*) malloc(sizeof(bool)*(myGraph->noNodes+1));
    for(int i=1; i<myGraph->noNodes; i++) {
        visited[i] = false;
    }
    return visited;
}


static void l_dfs_helper(lGraph* myGraph, int node, FILE* outFile, bool* visited){
    fprintf(outFile, "%d ", node);
    visited[node]=true;
    edge* iterator = myGraph->lists[node].first;
    while(iterator!=NULL){
        if(!visited[iterator->endPoint]) {
           l_dfs_helper(myGraph, iterator->endPoint, outFile, visited);
        }
        iterator = iterator->next;
    }
}

void l_dfs(lGraph* myGraph, FILE* outFile, FILE* inFile){
    fprintf(outFile, "Which is the root of the dfs tree?");
    int root;
    fscanf(inFile, "%d", &root);
    fprintf(outFile, "DFS of the graph(stored with adjacency lists) is: \n");
    bool* visited = l_getVisitedArray(myGraph);
    l_dfs_helper(myGraph, root, outFile, visited);
    fprintf(outFile, "\n");
}

void l_bfs(lGraph* myGraph,  FILE* outFile, FILE* inFile){
    fprintf(outFile, "Which is the root of the bfs tree?");
    int root;
    fscanf(inFile, "%d", &root);
    fprintf(outFile, "BFS of the graph(stored with adjacency lists) is: \n");
    bool* visited = l_getVisitedArray(myGraph);
    Queue bfsQueue = createQueue();
    enqueue(&bfsQueue, root);
    visited[root]=true;
    int frontNode;
    while(!isEmpty(&bfsQueue)){
        frontNode = dequeue(&bfsQueue);
        fprintf(outFile, "%d ", frontNode);
        edge* iterator = myGraph->lists[frontNode].first;
        while(iterator!=NULL){
            if(!visited[iterator->endPoint]) {
                visited[iterator->endPoint]=true;
                enqueue(&bfsQueue, iterator->endPoint);
            }
            iterator = iterator->next;
        }
    }
    fprintf(outFile, "\n");
}


/*with a modified dfs I simply check all the siple paths in the graph starting at the given root
modifications with respect to the general dfs: I don't generate a tree --> I may need to visit a node more than once.
 --> in the visited[] array I don't store whether the given node was visited or not in the depth first search until now,
 but whether or not it is on the current path(starting from the root), which was built by the df search
 When I backtrack from a node X, I mark it as unvisited --> I my visit it later again, if it is reachable thorugh an other path as well form the root
 */


void longest_path_dfs(lGraph* myGraph, int node, int dest, bool* nowVisited, list* currPath, int currPathLength, int* longestPathLegth, list* longestPath){
    if(node!=dest) {
        nowVisited[node] = true;
        edge *iterator = myGraph->lists[node].first;
        while (iterator != NULL) {
            if (!nowVisited[iterator->endPoint]) {
                addLast(currPath, iterator->endPoint, iterator->length);
                longest_path_dfs(myGraph, iterator->endPoint, dest,  nowVisited, currPath, currPathLength+iterator->length, longestPathLegth, longestPath);
                deleteLast(currPath);
            }
            iterator = iterator->next;
        }
        nowVisited[node] = false;
    }
    else{
        if(currPathLength>*longestPathLegth) {
            *longestPathLegth = currPathLength;
            deleteAll(longestPath);
            edge *iterator = currPath->first;
            while (iterator != NULL) {
                addLast(longestPath, iterator->endPoint, iterator->length);
                iterator=iterator->next;
            }
        }
    }
}

list findLongestPath(lGraph* myGraph, int source, int dest){
    list longestPath = createList();
    list currPath = createList();
    addLast(&currPath, source, 0);
    bool* nowVisited = l_getVisitedArray(myGraph);
    int longestPathLength=0;
    longest_path_dfs(myGraph, source, dest,  nowVisited, &currPath, 0, &longestPathLength, &longestPath);
    return longestPath;
}
