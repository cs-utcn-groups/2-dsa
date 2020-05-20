//
// Created by q on 5/7/2020.
//

#ifndef SORTING_ALGORITHMS_IO_H
#define SORTING_ALGORITHMS_IO_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void createFile(int N, FILE * fp);

FILE * openFile(char * name, char * mode);

int * readArray(FILE * fp, int * N);

void printArray(int N, int * array);
#endif //SORTING_ALGORITHMS_IO_H
