//
// Created by q on 5/7/2020.
//

#include "io.h"
FILE * openFile(char * name, char * mode) {
    FILE * fp = fopen(name, mode);
    if(fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return fp;
}


void createFile(int N, FILE * fp) {
    srand (time(NULL));
    for(int i=0; i<N; i++)
    {
        fprintf(fp,"%d\n",rand() % N);
    }
    fclose(fp);
}

int * readArray(FILE * fp, int * N) {
    fscanf(fp,"%d",N);
    int * array = (int *) malloc(sizeof(int) * (*N));
    if(array == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    else {
        for(int i = 0; i < *N; i++) {
            fscanf(fp,"%d",&array[i]);
        }
    }
    return array;
}
void printArray(int N, int * array) {
    for(int i = 0; i < N; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
}
