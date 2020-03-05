//
// Created by Denisa on 2/26/2020.
//

#ifndef ASSIGNMENTLAB1_HEAD_H
#define ASSIGNMENTLAB1_HEAD_H

#include <stdio.h>
#include <stdlib.h>

void initializeSll();

void AF(int x);

void AL(int x);

void DF();

void DL();

void DOOM_THE_LIST();

void DE(int x);

void PRINT_ALL(FILE *output);

void PRINT_F(FILE *output, int x);

void PRINT_L(FILE *output, int x);

typedef struct node {
    int data;
    struct node *next;
} NodeT;

NodeT *first, *last;
#endif //ASSIGNMENTLAB1_HEAD_H
