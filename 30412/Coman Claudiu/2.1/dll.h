#ifndef A2_1_DLL_H
#define A2_1_DLL_H

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE_PATH "../input.dat"
#define OUTPUT_FILE_PATH "../output.dat"

void InitializeDll();
void AL(int key);
void DE(int key);
void AF(int key);
void DF();
void DL();
void PRINT_ALL();
void PrintList();
void PRINT_F(int nr);
void PRINT_L(int nr);
int ListLength();

typedef struct node {
    int data;
    struct node * next, * previous;
} NodeT;

typedef struct _doubleList{
    NodeT * first;
    NodeT * last;
}doubleList;

doubleList dL;

void removeAll();
#endif //A2_1_DLL_H