//
// Created by q on 4/2/2020.
//

#ifndef ASSIGNMENT5_MATRIX_H
#define ASSIGNMENT5_MATRIX_H

#include "list.h"

// function to create an N x N matrix
int ** createMatrix(int N);
// function to create a matrix and fill it with entries
int ** readMatrix(FILE * fp, int * N);
// function to initialize entries of the matrix with 0
void initializeMatrix(int N, int ** A);
// function to free the matrix
void freeMatrix(int N, int ** A);
// function to print the adjacency matrix
void printMatrix(int N, int ** A);

#endif //ASSIGNMENT5_MATRIX_H
