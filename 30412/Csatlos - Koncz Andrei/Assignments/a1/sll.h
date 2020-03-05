//
// Created by csatl on 2/27/2020.
//

#ifndef A1_SLL_H
#define A1_SLL_H

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE_PATH "../input.dat"
#define OUTPUT_FILE_PATH "../output.dat"

void InitializeSll();
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
    struct node * next;
} NodeT;
NodeT *first, *last;

void removeAll();


#endif //A1_SLL_H
