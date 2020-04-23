//
// Created by q on 4/3/2020.
//

#include "longestPath.h"

void findLongestPath(int N, ListT * AL, int s, int d) {
    /*
     * function to find and print the longest path
     * s = source node
     * d = destination node
     */
    printf("The longest simple path between %c and %c:\n",'A'+s,'A'+ d);
    int * visited = createVisitedArray(N);
    ListT * path = createAdjList(1);
    ListT * longestPath = createAdjList(1);
    // call recursive function
    findRec(AL,s,d,visited,path,longestPath);
    // print the longest simple path
    printList(*longestPath);
    new_line;
}

void findRec(ListT * AL, int s, int d, int * visited, ListT * path, ListT * longestPath) {
    // recursive function to find the longest path
    static int max = 0; // static variable that holds the value of the current maximum
    visited[s] = VISITED;
    insertNode(path,s);
    if(s == d) {
        // reached destination
        if(path->count > max) {
            // check if its length is greater than the current maximum
            copyList(path,longestPath);
            max = path->count; // update static variable max
        }
    }
    else {
        int * neighbours = getNeighbours(AL[s]);
        for(int i=0; i<AL[s].count; i++) {
            if(visited[neighbours[i]] == UNVISITED) {
                findRec(AL,neighbours[i],d,visited,path,longestPath);
            }
        }
    }
    visited[s] = UNVISITED;
    deleteLastNode(path);
}

void copyList(ListT * src, ListT * dest) {
    // copy content of src list to dest
    // clear previous content of destination list
    deleteList(dest);
    // duplicate list
    NodeT * temp = src->head;
    while(temp) {
        insertNode(dest,temp->data);
        temp = temp->next;
    }
}