//
// Created by q on 4/1/2020.
//

#include "representGraph.h"

ListT * convertMatrixToList(int N, int ** A) {
    /*
     * function to convert an adj. matrix into an adj. array of lists
     * * returns: array of lists
     */
    ListT * AL = createAdjList(N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if (A[i][j]) {
                insertNode(&AL[i],j);
            }
        }
    }
    freeMatrix(N, A);
    return AL;
}

int ** convertListToMatrix(int N, ListT * AL) {
    /*
     * function to convert adjacency list back into adjacency array
     * * returns: matrix
     */
    int ** A = createMatrix(N);
    // initialize matrix
    initializeMatrix(N, A);
    for(int i=0; i<N; i++) {
        // mark adjacent nodes
        NodeT * temp = AL[i].head;
        while(temp) {
            A[i][temp->data] = 1;
            temp = temp->next;
        }
    }
    free(AL);
    return A;
}