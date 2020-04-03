//
// Created by q on 4/2/2020.
//

#include "matrix.h"

int ** createMatrix(int N) {
    // function to create an N x N matrix
    int ** A = (int **)malloc(N * sizeof(int *));
    if(A == NULL) {
        errMessage();
    }
    else {
        for(int i=0; i<N; i++) {
            A[i] = (int *)malloc(N * sizeof(int));
            if(A[i] == NULL) {
                errMessage();
            }
        }
    }
    return A;
}

void initializeMatrix(int N, int ** A) {
    // initialize entries of the matrix with 0
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) {
        A[i][j] = 0;
    }
}

int ** readMatrix(FILE * fp, int * N) {
    /*
     * function to create an adjacency matrix with entries read from an input file
     * * returns: adjacency matrix
     */
    fscanf(fp, "%d", N);
    int ** A = createMatrix(*N); // adjacency matrix
    for(int i=0; i<*N; i++) {
        for(int j=0; j<*N; j++) {
            fscanf(fp, "%d", &A[i][j]);
        }
        fgetc(fp);
    }
    fclose(fp);
    return A;
}

void printMatrix(int N, int ** A) {
   // function to print the adjacency matrix
   printf("Adjacency matrix:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ",A[i][j]);
        }
        new_line;
    }
    new_line;
}

void freeMatrix(int N, int ** A) {
    // function to free matrix
    for(int i=0; i<N; i++) {
        free(A[i]);
    }
    free(A);
}