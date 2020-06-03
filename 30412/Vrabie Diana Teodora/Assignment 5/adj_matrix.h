//
// Created by diana on 08/05/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "adj_list.h"

#ifndef ASSIGNMENT_5_ADJ_MATRIX_H
#define ASSIGNMENT_5_ADJ_MATRIX_H

int **createEmptyMatrix(int size);

void readAdjMatrix(FILE *inputFile, int **matrix, int size);

void printAdjMatrix(int **matrix, int size);

int **createMatrixFromList(Graph *graph);

#endif //ASSIGNMENT_5_ADJ_MATRIX_H
