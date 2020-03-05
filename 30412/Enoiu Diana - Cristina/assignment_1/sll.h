//
// Created by Diana on 2/29/2020.
//

#ifndef ASSIGNMENT_1_SLL_H
#define ASSIGNMENT_1_SLL_H
#include <stdio.h>
#include <stdlib.h>
void initializeSll();
void AF(int data);
void AL(int data);
void DF();
void DL();
void DOOM_THE_LIST();
void DE(int data);
void PRINT_ALL(FILE * output);
void PRINT_F (FILE * output, int tillValue);
void PRINT_L (FILE * output, int tillValue);
typedef struct _node {
    int data;
    struct _node * next;
} NodeT;
NodeT * first, * last;
#endif //ASSIGNMENT_1_SLL_H
