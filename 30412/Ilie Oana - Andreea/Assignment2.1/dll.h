//
// Created by Andreea on 07-Mar-20.
//

#ifndef ASSIGNMENT2_1_DLL_H
#define ASSIGNMENT2_1_DLL_H
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
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

#endif //ASSIGNMENT2_1_DLL_H
