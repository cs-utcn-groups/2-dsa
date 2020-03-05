//
// Created by Andreea on 02-Mar-20.
//

#ifndef ASSIGNMENT_1_SLL_H
#define ASSIGNMENT_1_SLL_H

#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} NodeT;

NodeT *first, *last;

void initializeSLL();

void AL(int data);

void AF(int data);

void DF();

void DL();

void DOOM_THE_LIST();

void DE_x(int x);

void PRINT_ALL(FILE *outputFile);

void PRINT_F(int x, FILE *outputFile);

void PRINT_L(int x, FILE *outputFile);

#endif //ASSIGNMENT1_SLL_H
